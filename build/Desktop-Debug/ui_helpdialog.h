/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_13;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *goBackButton;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(979, 791);
        verticalLayoutWidget = new QWidget(HelpDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 961, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(70, 90));
        label->setMaximumSize(QSize(70, 90));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/lmc.png")));
        label->setScaledContents(true);
        label->setWordWrap(false);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Mono PS"));
        font.setPointSize(14);
        font.setBold(true);
        label_4->setFont(font);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(false);
        label_4->setMargin(0);
        label_4->setIndent(-1);

        horizontalLayout->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(70, 90));
        label_2->setMaximumSize(QSize(70, 90));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/rmc.png")));
        label_2->setScaledContents(true);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font);
        label_6->setTextFormat(Qt::MarkdownText);
        label_6->setScaledContents(false);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(false);
        label_6->setMargin(0);
        label_6->setIndent(-1);

        horizontalLayout_2->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(70, 90));
        label_3->setMaximumSize(QSize(70, 90));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/mmc.png")));
        label_3->setScaledContents(true);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Mono PS"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        label_5->setFont(font1);
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(false);
        label_5->setMargin(0);
        label_5->setIndent(-1);

        horizontalLayout_3->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(50, 50));
        label_7->setMaximumSize(QSize(50, 50));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/number_1.png")));
        label_7->setScaledContents(true);

        horizontalLayout_6->addWidget(label_7);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nimbus Mono PS"));
        font2.setPointSize(13);
        font2.setBold(true);
        label_16->setFont(font2);
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_16);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(50, 50));
        label_10->setMaximumSize(QSize(50, 50));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/flag.png")));
        label_10->setScaledContents(true);

        horizontalLayout_10->addWidget(label_10);

        label_21 = new QLabel(verticalLayoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_21);


        gridLayout->addLayout(horizontalLayout_10, 0, 2, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setMinimumSize(QSize(50, 50));
        label_14->setMaximumSize(QSize(50, 50));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/exploded_mine.png")));
        label_14->setScaledContents(true);

        horizontalLayout_11->addWidget(label_14);

        label_22 = new QLabel(verticalLayoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_22);


        gridLayout->addLayout(horizontalLayout_11, 1, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(50, 50));
        label_9->setMaximumSize(QSize(50, 50));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/mine.png")));
        label_9->setScaledContents(true);

        horizontalLayout_8->addWidget(label_9);

        label_19 = new QLabel(verticalLayoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);
        label_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_19);


        gridLayout->addLayout(horizontalLayout_8, 1, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(50, 50));
        label_8->setMaximumSize(QSize(50, 50));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/opened_cell.png")));
        label_8->setScaledContents(true);

        horizontalLayout_5->addWidget(label_8);

        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_15);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(50, 50));
        label_13->setMaximumSize(QSize(50, 50));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/covered_cell.png")));
        label_13->setScaledContents(true);

        horizontalLayout_9->addWidget(label_13);

        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_17);


        gridLayout->addLayout(horizontalLayout_9, 0, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(50, 50));
        label_11->setMaximumSize(QSize(50, 50));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/right_mark.png")));
        label_11->setScaledContents(true);

        horizontalLayout_7->addWidget(label_11);

        label_18 = new QLabel(verticalLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_18);


        gridLayout->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(50, 50));
        label_12->setMaximumSize(QSize(50, 50));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/wrong_mark.png")));
        label_12->setScaledContents(true);

        horizontalLayout_12->addWidget(label_12);

        label_20 = new QLabel(verticalLayoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font2);
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_20);


        gridLayout->addLayout(horizontalLayout_12, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        goBackButton = new QPushButton(verticalLayoutWidget);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/arrow-go-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        goBackButton->setIcon(icon);

        horizontalLayout_4->addWidget(goBackButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 10);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 10);
        verticalLayout->setStretch(5, 1);

        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QCoreApplication::translate("HelpDialog", "Dialog", nullptr));
        label->setText(QString());
        label_4->setText(QCoreApplication::translate("HelpDialog", "<html><head/><body><p>Linker Mausklick - deckt das gew\303\244hlte Feld auf. Wenn das Feld an keine Mine</p><p>grenzt, werden auch alle Nachbarfelder aufgedeckt. Um das Spiel </p><p>zu gewinnen, muss man alle unverminte Felder \303\266ffnen.</p></body></html>", nullptr));
        label_2->setText(QString());
        label_6->setText(QCoreApplication::translate("HelpDialog", "<html><head/><body><p>Rechter Mausklick - markiert das ausgew\303\244hlte Feld mit einer Flage.</p><p>Wenn das Feld schon markiert ist wird die Markierung entfernt. Um das Spiel </p><p>zu gewinnen muss man alle verminte Felder markieren.</p></body></html>", nullptr));
        label_3->setText(QString());
        label_5->setText(QCoreApplication::translate("HelpDialog", "Mittlerer Mausklick - entfernt die Markierung auf dem gew\303\244hlten Feld.", nullptr));
        label_7->setText(QString());
        label_16->setText(QCoreApplication::translate("HelpDialog", "Feld, das an eine Mine grenzt", nullptr));
        label_10->setText(QString());
        label_21->setText(QCoreApplication::translate("HelpDialog", "Das markierte Feld", nullptr));
        label_14->setText(QString());
        label_22->setText(QCoreApplication::translate("HelpDialog", "Explodierte Mine", nullptr));
        label_9->setText(QString());
        label_19->setText(QCoreApplication::translate("HelpDialog", "Mine", nullptr));
        label_8->setText(QString());
        label_15->setText(QCoreApplication::translate("HelpDialog", "Das aufgedeckte Feld", nullptr));
        label_13->setText(QString());
        label_17->setText(QCoreApplication::translate("HelpDialog", "Das verdeckte Feld", nullptr));
        label_11->setText(QString());
        label_18->setText(QCoreApplication::translate("HelpDialog", "Das richtig markierte Feld", nullptr));
        label_12->setText(QString());
        label_20->setText(QCoreApplication::translate("HelpDialog", "Das falsch markierte Feld", nullptr));
        goBackButton->setText(QCoreApplication::translate("HelpDialog", "Zur\303\274ck ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
