#include "mainwindow.hpp"
#include "calculator.hpp"
#include "table_event_handler.hpp"
#include <file_parser.hpp>
#include <fstream>
#include <qmessagebox.h>
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  ui->setupUi(this);

  ui->result_output->acceptRichText();

  connect(ui->clear_btn, &QPushButton::clicked, this,
          &MainWindow::clear_points);
  connect(ui->browse_btn, &QPushButton::clicked, this,
          &MainWindow::show_file_dialog);
  connect(ui->add_btn, &QPushButton::clicked, this, &MainWindow::add_point);
  connect(ui->load_btn, &QPushButton::clicked, this, &MainWindow::load_file);
  connect(ui->calc_button, &QPushButton::clicked, this, &MainWindow::calculate);

  table_event_handler = std::make_unique<TableEventHandler>(ui->point_table);

  QString html = R"(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script src="https://www.desmos.com/api/v1.8/calculator.js?apiKey=dcb31709b452b1cf9dc26972add0fda6"></script>
</head>
<body>
    <div id="calculator" style="height: 643px; width: 100%;"></div>
    <script>
        var elt = document.getElementById('calculator');
        var calculator = Desmos.GraphingCalculator(elt);
    </script>
</body>
</html>
)";
  ui->webview->setHtml(html);
}

void MainWindow::clear_points() { ui->point_table->setRowCount(0); }

void MainWindow::add_point() {
  auto row = ui->point_table->rowCount();
  ui->point_table->setRowCount(row + 1);
  ui->point_table->setItem(row, 0, new QTableWidgetItem("0"));
  ui->point_table->setItem(row, 1, new QTableWidgetItem("0"));
  ui->point_table->editItem(ui->point_table->item(row, 0));
}

void MainWindow::load_file() {
  auto file_name = ui->file_path_edit->toPlainText();
  if (file_name.isEmpty()) {
    QMessageBox::warning(this, "Error",
                         "No file selected. Please, provide path to file.");
    return;
  }
  FileParser parser(file_name);
  if (!parser.parse()) {
    QMessageBox::critical(this, "Error reading file", "Invalid file format.");
    return;
  }
  auto lines = parser.getLines();
  ui->point_table->setRowCount(lines.size());
  for (int i = 0; i < lines.size(); i++) {
    auto [x, y] = lines[i];
    ui->point_table->setItem(i, 0, new QTableWidgetItem(x));
    ui->point_table->setItem(i, 1, new QTableWidgetItem(y));
  }
  QMessageBox::information(this, "File loaded", "File loaded successfully.");
}

void MainWindow::show_file_dialog() {
  auto file_name = QFileDialog::getOpenFileName(this, tr("Open File"), ".",
                                                tr("Any text file (*.txt)"));
  ui->file_path_edit->setText(file_name);
}

void MainWindow::calculate() {
  std::vector<double> x;
  x.reserve(ui->point_table->rowCount());
  std::vector<double> y;
  y.reserve(ui->point_table->rowCount());
  ui->webview->page()->runJavaScript("calculator.setBlank()");
  for (int i = 0; i < ui->point_table->rowCount(); i++) {
    x.push_back(ui->point_table->item(i, 0)->text().toDouble());
    y.push_back(ui->point_table->item(i, 1)->text().toDouble());
    QString query =
        QString(
            "calculator.setExpression({ id: 'point%1', latex: '(%2, %3)' })")
            .arg(QString::number(i), QString::number(x[i]),
                 QString::number(y[i]));
    ui->webview->page()-> runJavaScript(query);
  }

  auto n = ui->point_table->rowCount();
  auto func = ApproximationCalculator::find_best_function(n, x, y);
  auto calc = ApproximationCalculator(func, x, y);
  auto coefficients = calc.calculate_coefficients();
  auto phi_values = calc.get_phi_values();
  auto eps_values = calc.get_epsilon_values();
  auto pearson = calc.calculate_pearson_correlation();
  QDateTime currentDateTime = QDateTime::currentDateTime();
  QString currentTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
  ui->result_output->append("<h3> Approximation result from " +
                            currentTimeString + ":</h3>");

  if (!pearson.second.empty()) {
    ui->result_output->append(
        "<b>" + QString::fromUtf8(pearson.second.c_str()) + "</b>");
    return;
  }
  ui->result_output->append(
      "<b>Best matching function:</b> " +
      QString::fromUtf8(func.to_string().c_str()) + " " +
      QString::fromUtf8(func.get_string_function(coefficients).c_str()));
  ui->result_output->append("<b>Pearson correlation:</b> " +
                            QString::number(pearson.first));
  ui->result_output->append("<b>Coefficients:</b>");
  for (int i = 0; i < coefficients.size(); i++) {
    ui->result_output->append(QString::number(coefficients[i]));
  }
  ui->result_output->append("<b>Phi values:</b>");
  for (int i = 0; i < phi_values.size(); i++) {
    ui->result_output->append(QString::number(phi_values[i]));
  }
  ui->result_output->append("<b>Epsilon values:</b>");
  for (int i = 0; i < eps_values.size(); i++) {
    ui->result_output->append(QString::number(eps_values[i]));
  }
  QString js_expr =
      QString("calculator.setExpression({ id: '%1', latex: "
              "'%2', color: Desmos.Colors.BLUE })")
          .arg("graph", func.get_string_function(coefficients).c_str());
  ui->webview->page()->runJavaScript(js_expr);
}