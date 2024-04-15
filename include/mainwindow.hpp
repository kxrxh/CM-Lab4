#ifndef F0C149B2_1688_4B08_AA51_D271DD3E55A3
#define F0C149B2_1688_4B08_AA51_D271DD3E55A3

#include "table_event_handler.hpp"
#include "ui_mainwindow.hpp"
#include <QDateTime>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QToolTip>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow final : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override = default;

private:
  std::unique_ptr<Ui::MainWindow> ui = std::make_unique<Ui::MainWindow>();
  std::unique_ptr<TableEventHandler> table_event_handler;

private slots:
  void show_file_dialog();
  void load_file();
  void add_point();
  void clear_points();
  void calculate();
};

#endif /* F0C149B2_1688_4B08_AA51_D271DD3E55A3 */
