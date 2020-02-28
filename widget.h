#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QTreeWidgetItem>
#include <QVector>
#include <QHash>
#include <QListWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_serversAll_toggled(bool checked);

    void on_pushButton_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *itemTable);

    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column);

private:
    QHash<QString, QStringList> modulsFromSettings;
    QList<QTreeWidgetItem *> treeItemsLogs;
    QList<QString> tableItems;
    QHash<QString,QTreeWidgetItem*> hashTreeItems;
    Ui::Widget *ui;
};

#endif // WIDGET_H
