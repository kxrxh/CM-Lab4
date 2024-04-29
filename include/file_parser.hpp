#ifndef C5E01910_F282_475A_9AD3_8B901FA6E19B
#define C5E01910_F282_475A_9AD3_8B901FA6E19B

#include <QDebug>
#include <QPair>
#include <QString>
#include <QStringList>
#include <algorithm>
#include <fstream>
#include <vector>

/**
 * @brief The FileParser class handles parsing of a file containing two sets of
 * data.
 *
 * It reads two lines from the file, splits them into individual elements, and
 * pairs corresponding elements from each line into QPair objects. The file must
 * contain space-separated numeric data on each line.
 */
class FileParser {
private:
  QString filename; /**< The name of the file to parse. */
  std::vector<QPair<QString, QString>> lines; /**< Pairs of parsed data. */

public:
  /**
   * @brief Constructs a FileParser object with the specified filename.
   * @param filename The name of the file to parse.
   */
  explicit FileParser(QString const &filename) : filename(filename){};

  /**
   * @brief Retrieves the parsed data pairs.
   * @return A constant reference to the vector of QPair objects containing
   * parsed data.
   */
  std::vector<QPair<QString, QString>> const &getLines() const { return lines; }

  /**
   * @brief Parses the file and populates the lines vector with paired data.
   * @return True if parsing is successful, false otherwise.
   *
   * It reads two lines from the file, splits them into individual elements, and
   * pairs corresponding elements from each line into QPair objects. The file
   * must contain space-separated numeric data on each line. Returns false if
   * the file cannot be opened, or if any line contains non-numeric data.
   */
  bool parse() {
    if (std::ifstream file(filename.toStdString()); file.is_open()) {
      std::string x_line;
      std::string y_line;
      // Reading lines
      if (std::getline(file, x_line) && std::getline(file, y_line)) {
        // Getting numbers from lines
        QStringList x_list = QString::fromStdString(x_line).split(' ');
        QStringList y_list = QString::fromStdString(y_line).split(' ');

        // Check if all elements of x_list and y_list are numbers
        if (!std::all_of(x_list.begin(), x_list.end(), [](QString const &str) {
              bool ok;
              str.toDouble(&ok);
              return ok;
            })) {
          qDebug() << "not all elements of x are numbers";
          return false;
        }
        if (!std::all_of(y_list.begin(), y_list.end(), [](QString const &str) {
              bool ok;
              str.toDouble(&ok);
              return ok;
            })) {
          qDebug() << "not all elements of y are numbers";
          return false;
        }

        // Pair elements from x_list and y_list and add to lines vector
        for (int i = 0; i < x_list.size(); i++) {
          lines.push_back(QPair<QString, QString>(x_list[i], y_list[i]));
        }
        return true; // Parsing successful
      }
    }
    return false; // Unable to open file or read lines
  }
};

#endif /* C5E01910_F282_475A_9AD3_8B901FA6E19B */
