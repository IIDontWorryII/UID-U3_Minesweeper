/********************************************************************************
** Form generated from reading UI file 'statisticsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSDIALOG_H
#define UI_STATISTICSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *statisticsTable;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *goBackButton;

    void setupUi(QDialog *StatisticsDialog)
    {
        if (StatisticsDialog->objectName().isEmpty())
            StatisticsDialog->setObjectName(QString::fromUtf8("StatisticsDialog"));
        StatisticsDialog->resize(840, 561);
        verticalLayoutWidget = new QWidget(StatisticsDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 752, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        statisticsTable = new QTableWidget(verticalLayoutWidget);
        if (statisticsTable->columnCount() < 7)
            statisticsTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        statisticsTable->setObjectName(QString::fromUtf8("statisticsTable"));
        statisticsTable->setMinimumSize(QSize(750, 0));
        statisticsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        statisticsTable->setSortingEnabled(true);

        verticalLayout->addWidget(statisticsTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        goBackButton = new QPushButton(verticalLayoutWidget);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/arrow-go-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        goBackButton->setIcon(icon);

        horizontalLayout->addWidget(goBackButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(StatisticsDialog);

        QMetaObject::connectSlotsByName(StatisticsDialog);
    } // setupUi

    void retranslateUi(QDialog *StatisticsDialog)
    {
        StatisticsDialog->setWindowTitle(QCoreApplication::translate("StatisticsDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = statisticsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("StatisticsDialog", "Feldl\303\244nge", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = statisticsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("StatisticsDialog", "Feldbreite", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = statisticsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("StatisticsDialog", "Minenanzahl", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = statisticsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("StatisticsDialog", "Spielanzahl", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = statisticsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("StatisticsDialog", "Gewonnen", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = statisticsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("StatisticsDialog", "Verloren", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = statisticsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("StatisticsDialog", "Zeitrekorde", nullptr));
        goBackButton->setText(QCoreApplication::translate("StatisticsDialog", "Zur\303\274ck ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsDialog: public Ui_StatisticsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSDIALOG_H
