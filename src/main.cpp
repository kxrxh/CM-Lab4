#include "mainwindow.hpp"
#include <QApplication>
#include <qresource.h>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  MainWindow w;
  w.show();

  return QApplication::exec();
}