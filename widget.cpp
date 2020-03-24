#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSettings>
#include <QCheckBox>
#include <QProcess>
#include <iostream>

//void _log_debug(const template_node_t *render, log_context_t *context, char const *format, ...) __attribute__ ((format(printf, 3, 4)));

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPalette palette = ui->tableWidget->palette();
    palette .setBrush(QPalette::Base, Qt::transparent);
    ui->tableWidget->setPalette(palette);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

    QSettings *settings = new QSettings("settings.conf",QSettings::NativeFormat);
    settings->beginGroup("servers");
    foreach(QString str , settings->allKeys()){
        QCheckBox * check=new QCheckBox;
        servers.push_back(check);
        check->setText(str);
        ui->horizontalLayout_servers->addWidget(check);
    }

    settings->endGroup();

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setEditTriggers (QAbstractItemView :: NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    settings->beginGroup("modules");
    int i=0;
    int j=0;
    foreach(QString  str , settings->allKeys()){
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
//    QTableWidgetItem * itemTable=new QTableWidgetItem;
//    itemTable->setText("rtertwet");
//    itemTable->setCheckState(Qt::Unchecked);
//    QTableWidgetItem * itemTable2=new QTableWidgetItem;
//    itemTable2->setText("rtertwet1");
//    itemTable2->setCheckState(Qt::Unchecked);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_serversAll_toggled(bool checked)
{
    foreach(QCheckBox * chBox , servers){
        chBox->setChecked(checked);
    }
}

void Widget::on_pushButton_clicked()
{
        QProcess process;
        QString servers_str;
        foreach(QCheckBox *server , servers){
            servers_str=servers_str+server->text()+" ";
        }
    if(treeItemsLogs.count()==0){
        ui->textBrowser->append("Не выбран ни один модуль");
        return;
    }
    if(treeItemsLogs.count()>0){
        foreach(QTreeWidgetItem *item , treeItemsLogs){

            qDebug()<<item->parent()->text(0);
            qDebug()<<item->text(0);
            //for s in `echo 172.18.1.15`; do ssh root@${s} "hostname && find /home/clr/roam-nrtrde -follow -name *_20200212*.log -exec cat {} 005C; 2>/dev/null | grep \"ttt\""; done;
//            QString LProc("for s in `echo "+servers_str+"`; do ssh $s 'hostname && find /home/clr/"+item->parent()->text(0)+" -follow -name *"+item->text(0)+"_"+ui->lineEdit_when->text()+"*.log -exec cat {} "+QChar('\\')+"; 2>/dev/null | grep \""+ui->lineEdit_what->text()+"\"'; done;");
//            QString LProc("for s in `echo "+"172.18.1.15"+"`; do ssh root@{$s} 'hostname && find /home/clr/"+item->parent()->text(0)+" -follow -name *"+item->text(0)+"_"+ui->lineEdit_when->text()+"*.log -exec cat {} "+QChar('\\')+"; 2>/dev/null | grep \""+ui->lineEdit_what->text()+"\"'; done;");
            QString LProc("echo hello");
            ui->textBrowser->append(LProc);
            process.start("sh", QStringList() << "-c" << LProc);
            if (!process.waitForStarted()){ //default wait time 30 sec
                qWarning() << " cannot start process ";
                ui->textBrowser->append(" cannot start process ");
            }
            int waitTime = 60000 ; //60 sec
            if (!process.waitForFinished(waitTime)){
                qWarning() << "timeout .. ";
                ui->textBrowser->append("timeout .. ");
            }
            qDebug() << process.readAll();
            ui->textBrowser->append(process.readAll());
        }
    }
//    else {
//        for(QString & str : tableItems)
//            qDebug()<<str;
//    }
    ui->textBrowser->show();
}


void Widget::on_tableWidget_itemChanged(QTableWidgetItem *itemTable)
{
    if(itemTable->checkState()==Qt::Checked){
        QTreeWidgetItem * item=new QTreeWidgetItem;
        ui->treeWidget->insertTopLevelItem(0,item);
        item->setText(0,itemTable->text());
        QStringList itemsList=modulsFromSettings.value(itemTable);
        QTreeWidgetItem * parentEmptyCheckbox=new QTreeWidgetItem;
        item->addChild(parentEmptyCheckbox);
        parentEmptyCheckbox->setDisabled(true);
        parentEmptyCheckbox->setText(0,"");
        parentEmptyCheckbox->setHidden(true);
        parentEmptyCheckbox->setCheckState(0,Qt::Checked);
        foreach(QString  str , itemsList){
            QTreeWidgetItem * itemChild=new QTreeWidgetItem;
            itemChild->setText(0,str);
            item->addChild(itemChild);
            itemChild->setCheckState(0,Qt::Unchecked);
        }
        tableItems.append(itemTable->text());
        hashTreeItems.insert(itemTable,item);
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
    foreach(QTableWidgetItem * it , modulsFromSettings.keys()){
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
