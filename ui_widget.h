/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_what;
    QLabel *label_2;
    QLineEdit *lineEdit_when;
    QVBoxLayout *verticalLayout_3;
    QToolBox *toolBox;
    QWidget *servers_page;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_servers;
    QRadioButton *serversAll;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1204, 662);
        horizontalLayout_5 = new QHBoxLayout(Widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        lineEdit_what = new QLineEdit(Widget);
        lineEdit_what->setObjectName(QStringLiteral("lineEdit_what"));

        verticalLayout_4->addWidget(lineEdit_what);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        lineEdit_when = new QLineEdit(Widget);
        lineEdit_when->setObjectName(QStringLiteral("lineEdit_when"));

        verticalLayout_4->addWidget(lineEdit_when);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        toolBox = new QToolBox(Widget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        servers_page = new QWidget();
        servers_page->setObjectName(QStringLiteral("servers_page"));
        servers_page->setGeometry(QRect(0, 0, 584, 184));
        gridLayout = new QGridLayout(servers_page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_servers = new QHBoxLayout();
        horizontalLayout_servers->setSpacing(6);
        horizontalLayout_servers->setObjectName(QStringLiteral("horizontalLayout_servers"));
        serversAll = new QRadioButton(servers_page);
        serversAll->setObjectName(QStringLiteral("serversAll"));

        horizontalLayout_servers->addWidget(serversAll);


        gridLayout->addLayout(horizontalLayout_servers, 0, 0, 1, 1);

        toolBox->addItem(servers_page, QString::fromUtf8("\320\241\320\265\321\200\320\262\320\265\321\200\320\260"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 584, 210));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_2 = new QRadioButton(page);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget->setShowGrid(false);
        tableWidget->setWordWrap(true);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(tableWidget);

        toolBox->addItem(page, QString::fromUtf8("\320\234\320\276\320\264\321\203\320\273\321\214 ${WHERE} 	"));

        verticalLayout_3->addWidget(toolBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        treeWidget = new QTreeWidget(Widget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        horizontalLayout_2->addWidget(treeWidget);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addLayout(verticalLayout_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_5->addWidget(label_3);

        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_5->addWidget(textBrowser);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_5);


        retranslateUi(Widget);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "\320\230\321\201\320\272\320\260\321\202\321\214", 0));
        label_2->setText(QApplication::translate("Widget", "\320\227\320\260 \320\277\320\265\321\200\320\270\320\276\320\264", 0));
        lineEdit_when->setPlaceholderText(QApplication::translate("Widget", "YYYYMMDD", 0));
        serversAll->setText(QApplication::translate("Widget", "\320\222\321\201\320\265", 0));
        toolBox->setItemText(toolBox->indexOf(servers_page), QApplication::translate("Widget", "\320\241\320\265\321\200\320\262\320\265\321\200\320\260", 0));
        radioButton_2->setText(QApplication::translate("Widget", "\320\222\321\201\320\265", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "New Column", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "New Row", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "New Row", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Widget", "\320\234\320\276\320\264\321\203\320\273\321\214 ${WHERE} 	", 0));
        pushButton->setText(QApplication::translate("Widget", "\320\241\320\272\320\260\320\275\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\273\320\276\320\263\320\270", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Widget", "\320\222\321\213\320\261\321\200\320\260\320\275\321\213 \320\274\320\276\320\264\321\203\320\273\320\270", 0));
        pushButton_3->setText(QApplication::translate("Widget", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262 \321\204\320\260\320\271\320\273", 0));
        label_3->setText(QApplication::translate("Widget", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \321\201\320\272\320\260\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        pushButton_2->setText(QApplication::translate("Widget", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
