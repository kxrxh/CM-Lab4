#ifndef CE04B23D_63B9_443D_B1E0_1494F015BCB7
#define CE04B23D_63B9_443D_B1E0_1494F015BCB7

#include <QtWidgets/QTableWidget>
#include <QMessageBox>
#include <QKeyEvent>



class TableEventHandler : public QObject {
public:
    explicit TableEventHandler(QTableWidget *tableWidget) : QObject(tableWidget), tableWidget(tableWidget) {
        tableWidget->installEventFilter(this);
    }

protected:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (obj == tableWidget && event->type() == QEvent::KeyPress) {
            QKeyEvent const *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Delete) {
                if (QList<QTableWidgetItem *> selectedItems = tableWidget->selectedItems(); !selectedItems.isEmpty()) {
                    // Show confirmation dialog before deleting
                    QMessageBox::StandardButton reply = QMessageBox::question(tableWidget, "Delete Item", "Are you sure you want to delete the selected item?", QMessageBox::Yes | QMessageBox::No);
                    if (reply == QMessageBox::Yes) {
                        for (QTableWidgetItem const *item : selectedItems) {
                            tableWidget->removeRow(item->row());
                        }
                    }
                }
                return true; // Event handled
            }
        }
        return QObject::eventFilter(obj, event);
    }

private:
    QTableWidget *tableWidget;
};

#endif /* CE04B23D_63B9_443D_B1E0_1494F015BCB7 */
