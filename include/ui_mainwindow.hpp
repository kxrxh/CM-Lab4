/********************************************************************************
** Form generated from reading UI file 'designerjrCbdP.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGNERJRCBDP_H
#define DESIGNERJRCBDP_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
  QAction *actionShow_file_format_info;
  QAction *actionDescription;
  QWidget *centralwidget;
  QGridLayout *gridLayout;
  QTextBrowser *result_output;
  QFrame *frame_3;
  QVBoxLayout *verticalLayout_4;
  QLabel *label_3;
  QWebEngineView *webview;
  QFrame *frame_2;
  QVBoxLayout *verticalLayout_3;
  QLabel *label_2;
  QTableWidget *point_table;
  QPushButton *add_btn;
  QPushButton *clear_btn;
  QFrame *frame;
  QVBoxLayout *verticalLayout_2;
  QLabel *file_label;
  QTextEdit *file_path_edit;
  QPushButton *browse_btn;
  QPushButton *load_btn;
  QPushButton *calc_button;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(948, 1032);
    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(0, 0, 0, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    QBrush brush2(QColor(255, 255, 220, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
    palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
    QBrush brush3(QColor(255, 255, 255, 128));
    brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
    MainWindow->setPalette(palette);
    actionShow_file_format_info = new QAction(MainWindow);
    actionShow_file_format_info->setObjectName(
        QString::fromUtf8("actionShow_file_format_info"));
    actionDescription = new QAction(MainWindow);
    actionDescription->setObjectName(QString::fromUtf8("actionDescription"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    result_output = new QTextBrowser(centralwidget);
    result_output->setObjectName(QString::fromUtf8("result_output"));
    result_output->setMinimumSize(QSize(500, 200));

    gridLayout->addWidget(result_output, 4, 0, 1, 3);

    frame_3 = new QFrame(centralwidget);
    frame_3->setObjectName(QString::fromUtf8("frame_3"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
    frame_3->setSizePolicy(sizePolicy);
    frame_3->setMinimumSize(QSize(694, 721));
    frame_3->setFrameShape(QFrame::StyledPanel);
    frame_3->setFrameShadow(QFrame::Raised);
    verticalLayout_4 = new QVBoxLayout(frame_3);
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    label_3 = new QLabel(frame_3);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setMinimumSize(QSize(0, 60));
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    font.setWeight(75);
    label_3->setFont(font);

    verticalLayout_4->addWidget(label_3);

    webview = new QWebEngineView(frame_3);
    webview->setObjectName(QString::fromUtf8("webview"));
    webview->setMinimumSize(QSize(700, 643));
    webview->setUrl(QUrl(QString::fromUtf8("about:blank")));

    verticalLayout_4->addWidget(webview);

    gridLayout->addWidget(frame_3, 0, 1, 2, 1);

    frame_2 = new QFrame(centralwidget);
    frame_2->setObjectName(QString::fromUtf8("frame_2"));
    frame_2->setMaximumSize(QSize(230, 515));
    frame_2->setFrameShape(QFrame::StyledPanel);
    frame_2->setFrameShadow(QFrame::Raised);
    verticalLayout_3 = new QVBoxLayout(frame_2);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    verticalLayout_3->setContentsMargins(6, -1, -1, -1);
    label_2 = new QLabel(frame_2);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setFont(font);

    verticalLayout_3->addWidget(label_2);

    point_table = new QTableWidget(frame_2);
    if (point_table->columnCount() < 2)
      point_table->setColumnCount(2);
    QFont font1;
    font1.setBold(true);
    font1.setItalic(false);
    font1.setWeight(75);
    font1.setStrikeOut(false);
    font1.setKerning(true);
    QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
    __qtablewidgetitem->setFont(font1);
    point_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
    QFont font2;
    font2.setBold(true);
    font2.setWeight(75);
    QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
    __qtablewidgetitem1->setFont(font2);
    point_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
    point_table->setObjectName(QString::fromUtf8("point_table"));
    point_table->setFrameShape(QFrame::StyledPanel);
    point_table->setFrameShadow(QFrame::Sunken);
    point_table->setLineWidth(1);
    point_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    point_table->setAutoScroll(false);
    point_table->setAlternatingRowColors(false);
    point_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    point_table->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    point_table->setShowGrid(false);
    point_table->setGridStyle(Qt::DashDotDotLine);
    point_table->setSortingEnabled(false);
    point_table->setWordWrap(true);
    point_table->setCornerButtonEnabled(true);
    point_table->setRowCount(0);
    point_table->horizontalHeader()->setVisible(true);
    point_table->horizontalHeader()->setCascadingSectionResizes(false);
    point_table->horizontalHeader()->setMinimumSectionSize(20);
    point_table->horizontalHeader()->setDefaultSectionSize(110);
    point_table->horizontalHeader()->setHighlightSections(false);
    point_table->horizontalHeader()->setProperty("showSortIndicator",
                                                 QVariant(false));
    point_table->verticalHeader()->setVisible(false);
    point_table->verticalHeader()->setHighlightSections(false);

    verticalLayout_3->addWidget(point_table);

    add_btn = new QPushButton(frame_2);
    add_btn->setObjectName(QString::fromUtf8("add_btn"));

    verticalLayout_3->addWidget(add_btn);

    clear_btn = new QPushButton(frame_2);
    clear_btn->setObjectName(QString::fromUtf8("clear_btn"));

    verticalLayout_3->addWidget(clear_btn);

    gridLayout->addWidget(frame_2, 1, 0, 1, 1);

    frame = new QFrame(centralwidget);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setMaximumSize(QSize(230, 200));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    verticalLayout_2 = new QVBoxLayout(frame);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    file_label = new QLabel(frame);
    file_label->setObjectName(QString::fromUtf8("file_label"));
    file_label->setMaximumSize(QSize(16777215, 70));
    file_label->setFont(font);

    verticalLayout_2->addWidget(file_label);

    file_path_edit = new QTextEdit(frame);
    file_path_edit->setObjectName(QString::fromUtf8("file_path_edit"));
    file_path_edit->setMaximumSize(QSize(16777215, 40));
    file_path_edit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    verticalLayout_2->addWidget(file_path_edit);

    browse_btn = new QPushButton(frame);
    browse_btn->setObjectName(QString::fromUtf8("browse_btn"));
    browse_btn->setAutoExclusive(false);
    browse_btn->setAutoDefault(false);
    browse_btn->setFlat(false);

    verticalLayout_2->addWidget(browse_btn);

    load_btn = new QPushButton(frame);
    load_btn->setObjectName(QString::fromUtf8("load_btn"));

    verticalLayout_2->addWidget(load_btn);

    gridLayout->addWidget(frame, 0, 0, 1, 1);

    calc_button = new QPushButton(centralwidget);
    calc_button->setObjectName(QString::fromUtf8("calc_button"));
    QFont font3;
    font3.setPointSize(12);
    font3.setBold(true);
    font3.setWeight(75);
    calc_button->setFont(font3);

    gridLayout->addWidget(calc_button, 5, 0, 1, 3);

    MainWindow->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    browse_btn->setDefault(false);

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "Lab 3", nullptr));
    actionShow_file_format_info->setText(QCoreApplication::translate(
        "MainWindow", "Show file format info", nullptr));
    actionDescription->setText(
        QCoreApplication::translate("MainWindow", "Description", nullptr));
    label_3->setText(QCoreApplication::translate(
        "MainWindow", "Graphical representation", nullptr));
    label_2->setText(
        QCoreApplication::translate("MainWindow", "Points input", nullptr));
    QTableWidgetItem *___qtablewidgetitem =
        point_table->horizontalHeaderItem(0);
    ___qtablewidgetitem->setText(
        QCoreApplication::translate("MainWindow", "X", nullptr));
    QTableWidgetItem *___qtablewidgetitem1 =
        point_table->horizontalHeaderItem(1);
    ___qtablewidgetitem1->setText(
        QCoreApplication::translate("MainWindow", "Y", nullptr));
    add_btn->setText(
        QCoreApplication::translate("MainWindow", "Add point", nullptr));
    clear_btn->setText(
        QCoreApplication::translate("MainWindow", "Clear", nullptr));
    file_label->setText(QCoreApplication::translate(
        "MainWindow", "Load points from file", nullptr));
    browse_btn->setText(
        QCoreApplication::translate("MainWindow", "Browse", nullptr));
    load_btn->setText(
        QCoreApplication::translate("MainWindow", "Load", nullptr));
    calc_button->setText(
        QCoreApplication::translate("MainWindow", "Calculate", nullptr));
  } // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNERJRCBDP_H
