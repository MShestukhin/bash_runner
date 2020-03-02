#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSettings>
#include <QCheckBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ui->textBrowser->hide();

    QPalette palette = ui->tableWidget->palette();
    palette .setBrush(QPalette::Base, Qt::transparent);
    ui->tableWidget->setPalette(palette);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
//    ui->tableWidget->setStyleSheet("QTableView::item {selection-color: black; selection-background-color: rgba(200, 200, 200, 10%);}");

    QSettings *settings = new QSettings("settings.conf",QSettings::NativeFormat);
    settings->beginGroup("servers");
    for(QString & str : settings->allKeys()){
        QCheckBox * check=new QCheckBox;
        servers.push_back(check);
        check->setText(str);
        ui->horizontalLayout_servers->addWidget(check);
    }

    settings->endGroup();

    ui->tableWidget -> setEditTriggers ( QAbstractItemView :: NoEditTriggers);
    ui->tableWidget->setSelectionMode( QAbstractItemView::NoSelection);
    ui->tableWidget -> setEditTriggers ( QAbstractItemView :: NoEditTriggers);
    ui->tableWidget->setSelectionMode( QAbstractItemView::NoSelection);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    settings->beginGroup("modules");
    int i=0;
    int j=0;
    for(QString & str : settings->allKeys()){
        QTableWidgetItem * itemTable=new QTableWidgetItem;
        itemTable->setText(str);
        itemTable->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(j,i,itemTable);
        modulsFromSettings.insert(itemTable, settings->value(str).toStringList());
        if(i>=4){
            j++;
            i=0;
            ui->tableWidget->setRowCount(j+1);
        }
        i++;
    }

    ui->treeWidget->setColumnCount(1);
    QTableWidgetItem * itemTable=new QTableWidgetItem;
    itemTable->setText("rtertwet");
    itemTable->setCheckState(Qt::Unchecked);
    QTableWidgetItem * itemTable2=new QTableWidgetItem;
    itemTable2->setText("rtertwet1");
    itemTable2->setCheckState(Qt::Unchecked);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_serversAll_toggled(bool checked)
{
    for(QCheckBox * chBox : servers){
        chBox->setChecked(checked);
    }
}

void Widget::on_pushButton_clicked()
{
    qDebug()<<treeItemsLogs.count();
    if(tableItems.count()==0 && treeItemsLogs.count()==0){
        ui->textBrowser->append("Не выбран ни один модуль");
        return;
    }
    if(treeItemsLogs.count()>0){
        for(QTreeWidgetItem *item : treeItemsLogs){
            qDebug()<<item->parent()->text(0);
            qDebug()<<item->text(0);
        }
    }
    else {
        for(QString & str : tableItems)
            qDebug()<<str;
    }
    ui->textBrowser->show();
}


void Widget::on_tableWidget_itemChanged(QTableWidgetItem *itemTable)
{
    if(itemTable->checkState()==Qt::Checked){
        QTreeWidgetItem * item=new QTreeWidgetItem;
        tableItems.append(itemTable->text());
        item->setText(0,itemTable->text());
        QStringList itemsList=modulsFromSettings.value(itemTable);
        for(QString & str : itemsList){
            QTreeWidgetItem * itemChild=new QTreeWidgetItem;
            itemChild->setText(0,str);
            item->addChild(itemChild);
            itemChild->setCheckState(0,Qt::Unchecked);
        }
        hashTreeItems.insert(itemTable,item);
        ui->treeWidget->insertTopLevelItem(0,item);
    }
    if(itemTable->checkState()==Qt::Unchecked){
          QTreeWidgetItem * itemTree=hashTreeItems.take(itemTable);
          ui->treeWidget->setCurrentItem(itemTree);
          if(itemTree){
          for(int i=0;i<itemTree->childCount();i++)
            treeItemsLogs.removeOne(itemTree->child(i));
          }
          delete ui->treeWidget->currentItem();
          tableItems.removeOne(itemTable->text());
    }
}


void Widget::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    if(item->checkState(column)==Qt::Checked)
        treeItemsLogs.append(item);
    if(item->checkState(column)==Qt::Unchecked)
        treeItemsLogs.removeOne(item);
}

void Widget::on_radioButton_2_toggled(bool checked)
{
    qDebug()<<modulsFromSettings.keys().count();
    for(QTableWidgetItem * it : modulsFromSettings.keys()){
        if(checked)
            it->setCheckState(Qt::Checked);
        else
            it->setCheckState(Qt::Unchecked);
    }

//        if(checked)
//            it->setCheckState(Qt::Checked);
//        else
//            it->setCheckState(Qt::Unchecked);
//    }
}
