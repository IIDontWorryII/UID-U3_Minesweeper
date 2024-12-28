/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalWidget;
    QVBoxLayout *mainlayout;
    QWidget *statusBarWidget;
    QHBoxLayout *statusBar;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLCDNumber *minesLCDNumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLCDNumber *flagsLCDNumber;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLCDNumber *timeLCDNumber;
    QPushButton *menuButton;
    QWidget *gameGridWidget;
    QGridLayout *gameGrid;
    QWidget *gameSwitchesWidget;
    QHBoxLayout *gameSwitches;
    QPushButton *newGameButton;
    QPushButton *pauseGameButton;
    QPushButton *endGameButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1204, 896);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setGeometry(QRect(0, 0, 500, 400));
        verticalWidget->setMaximumSize(QSize(1920, 16777215));
        mainlayout = new QVBoxLayout(verticalWidget);
        mainlayout->setSpacing(0);
        mainlayout->setObjectName(QString::fromUtf8("mainlayout"));
        mainlayout->setSizeConstraint(QLayout::SetFixedSize);
        mainlayout->setContentsMargins(10, 10, 10, 10);
        statusBarWidget = new QWidget(verticalWidget);
        statusBarWidget->setObjectName(QString::fromUtf8("statusBarWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusBarWidget->sizePolicy().hasHeightForWidth());
        statusBarWidget->setSizePolicy(sizePolicy);
        statusBarWidget->setMinimumSize(QSize(300, 50));
        statusBarWidget->setMaximumSize(QSize(16777215, 50));
        statusBar = new QHBoxLayout(statusBarWidget);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeConstraint(QLayout::SetMinimumSize);
        statusBar->setContentsMargins(10, 0, 10, 10);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(statusBarWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(40, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/mine_2.png")));
        label_2->setScaledContents(true);

        horizontalLayout_3->addWidget(label_2);

        minesLCDNumber = new QLCDNumber(statusBarWidget);
        minesLCDNumber->setObjectName(QString::fromUtf8("minesLCDNumber"));
        sizePolicy1.setHeightForWidth(minesLCDNumber->sizePolicy().hasHeightForWidth());
        minesLCDNumber->setSizePolicy(sizePolicy1);
        minesLCDNumber->setMinimumSize(QSize(75, 0));
        minesLCDNumber->setMaximumSize(QSize(75, 30));

        horizontalLayout_3->addWidget(minesLCDNumber);


        statusBar->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(statusBarWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMaximumSize(QSize(40, 40));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/flag_2.png")));
        label_3->setScaledContents(true);

        horizontalLayout_4->addWidget(label_3);

        flagsLCDNumber = new QLCDNumber(statusBarWidget);
        flagsLCDNumber->setObjectName(QString::fromUtf8("flagsLCDNumber"));
        sizePolicy1.setHeightForWidth(flagsLCDNumber->sizePolicy().hasHeightForWidth());
        flagsLCDNumber->setSizePolicy(sizePolicy1);
        flagsLCDNumber->setMinimumSize(QSize(75, 0));
        flagsLCDNumber->setMaximumSize(QSize(75, 30));

        horizontalLayout_4->addWidget(flagsLCDNumber);


        statusBar->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label = new QLabel(statusBarWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(40, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/clock.png")));
        label->setScaledContents(true);

        horizontalLayout_6->addWidget(label);

        timeLCDNumber = new QLCDNumber(statusBarWidget);
        timeLCDNumber->setObjectName(QString::fromUtf8("timeLCDNumber"));
        sizePolicy1.setHeightForWidth(timeLCDNumber->sizePolicy().hasHeightForWidth());
        timeLCDNumber->setSizePolicy(sizePolicy1);
        timeLCDNumber->setMinimumSize(QSize(100, 0));
        timeLCDNumber->setMaximumSize(QSize(100, 30));

        horizontalLayout_6->addWidget(timeLCDNumber);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 100);
        horizontalLayout_6->setStretch(2, 100);

        statusBar->addLayout(horizontalLayout_6);

        menuButton = new QPushButton(statusBarWidget);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        sizePolicy1.setHeightForWidth(menuButton->sizePolicy().hasHeightForWidth());
        menuButton->setSizePolicy(sizePolicy1);
        menuButton->setMinimumSize(QSize(30, 30));
        menuButton->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuButton->setIcon(icon);

        statusBar->addWidget(menuButton);


        mainlayout->addWidget(statusBarWidget);

        gameGridWidget = new QWidget(verticalWidget);
        gameGridWidget->setObjectName(QString::fromUtf8("gameGridWidget"));
        gameGridWidget->setMinimumSize(QSize(400, 300));
        gameGrid = new QGridLayout(gameGridWidget);
        gameGrid->setSpacing(0);
        gameGrid->setObjectName(QString::fromUtf8("gameGrid"));
        gameGrid->setSizeConstraint(QLayout::SetDefaultConstraint);
        gameGrid->setContentsMargins(0, 0, 0, 10);

        mainlayout->addWidget(gameGridWidget);

        gameSwitchesWidget = new QWidget(verticalWidget);
        gameSwitchesWidget->setObjectName(QString::fromUtf8("gameSwitchesWidget"));
        sizePolicy.setHeightForWidth(gameSwitchesWidget->sizePolicy().hasHeightForWidth());
        gameSwitchesWidget->setSizePolicy(sizePolicy);
        gameSwitchesWidget->setMinimumSize(QSize(400, 30));
        gameSwitchesWidget->setMaximumSize(QSize(16777215, 30));
        gameSwitches = new QHBoxLayout(gameSwitchesWidget);
        gameSwitches->setSpacing(0);
        gameSwitches->setObjectName(QString::fromUtf8("gameSwitches"));
        gameSwitches->setSizeConstraint(QLayout::SetMinimumSize);
        gameSwitches->setContentsMargins(10, 0, 10, 0);
        newGameButton = new QPushButton(gameSwitchesWidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(newGameButton->sizePolicy().hasHeightForWidth());
        newGameButton->setSizePolicy(sizePolicy2);
        newGameButton->setMinimumSize(QSize(133, 0));
        newGameButton->setMaximumSize(QSize(1000, 30));

        gameSwitches->addWidget(newGameButton);

        pauseGameButton = new QPushButton(gameSwitchesWidget);
        pauseGameButton->setObjectName(QString::fromUtf8("pauseGameButton"));
        sizePolicy2.setHeightForWidth(pauseGameButton->sizePolicy().hasHeightForWidth());
        pauseGameButton->setSizePolicy(sizePolicy2);
        pauseGameButton->setMinimumSize(QSize(133, 0));
        pauseGameButton->setMaximumSize(QSize(1000, 30));

        gameSwitches->addWidget(pauseGameButton);

        endGameButton = new QPushButton(gameSwitchesWidget);
        endGameButton->setObjectName(QString::fromUtf8("endGameButton"));
        sizePolicy2.setHeightForWidth(endGameButton->sizePolicy().hasHeightForWidth());
        endGameButton->setSizePolicy(sizePolicy2);
        endGameButton->setMinimumSize(QSize(133, 0));
        endGameButton->setMaximumSize(QSize(1000, 30));

        gameSwitches->addWidget(endGameButton);


        mainlayout->addWidget(gameSwitchesWidget);

        mainlayout->setStretch(1, 100);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label->setText(QString());
        menuButton->setText(QString());
        newGameButton->setText(QCoreApplication::translate("MainWindow", "Neu", nullptr));
        pauseGameButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        endGameButton->setText(QCoreApplication::translate("MainWindow", "Beenden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
