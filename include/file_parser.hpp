#ifndef C5E01910_F282_475A_9AD3_8B901FA6E19B
#define C5E01910_F282_475A_9AD3_8B901FA6E19B

#include <QPair>
#include <QString>
#include <QStringList>
#include <algorithm>
#include <fstream>
#include <qdebug.h>
#include <vector>

class FileParser {
private:
  QString filename;
  std::vector<QPair<QString, QString>> lines;

public:
  explicit FileParser(QString const &filename) : filename(filename){};
  std::vector<QPair<QString, QString>> const &getLines() const { return lines; }
  bool parse() {
    if (std::ifstream file(filename.toStdString()); file.is_open()) {
      std::string x_line;
      std::string y_line;
      // Reading lines
      if (std::getline(file, x_line) && std::getline(file, y_line)) {
        // Getting numbers from lines
        QStringList x_list = QString::fromStdString(x_line).split(' ');
        QStringList y_list = QString::fromStdString(y_line).split(' ');

        // Shitty checking, but I don't care
        if (!std::all_of(x_list.begin(), x_list.end(), [](QString const &str) {
              bool ok;
              str.toDouble(&ok);
              return ok;
            })) {
          qDebug() << "not all el of x is numbers";
          return false;
        }
        if (!std::all_of(y_list.begin(), y_list.end(), [](QString const &str) {
              bool ok;
              str.toDouble(&ok);
              return ok;
            })) {
          qDebug() << "not all el of y is numbers";
          return false;
        }

        for (int i = 0; i < x_list.size(); i++) {
          lines.push_back(QPair<QString, QString>(x_list[i], y_list[i]));
        }
        return true;
      }
    }
    return false;
  }
};

#endif /* C5E01910_F282_475A_9AD3_8B901FA6E19B */
