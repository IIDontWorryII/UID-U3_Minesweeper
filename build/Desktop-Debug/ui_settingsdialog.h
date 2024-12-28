/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QComboBox *difficultyCB;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSlider *lengthSlider;
    QLineEdit *lengthLineEdit;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSlider *widthSlider;
    QLineEdit *widthLineEdit;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSlider *minesSlider;
    QLineEdit *minesLineEdit;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(399, 291);
        widget = new QWidget(SettingsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 371, 261));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        difficultyCB = new QComboBox(widget);
        difficultyCB->addItem(QString());
        difficultyCB->addItem(QString());
        difficultyCB->addItem(QString());
        difficultyCB->addItem(QString());
        difficultyCB->setObjectName(QString::fromUtf8("difficultyCB"));

        verticalLayout->addWidget(difficultyCB);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lengthSlider = new QSlider(widget);
        lengthSlider->setObjectName(QString::fromUtf8("lengthSlider"));
        lengthSlider->setMinimum(10);
        lengthSlider->setMaximum(40);
        lengthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(lengthSlider);

        lengthLineEdit = new QLineEdit(widget);
        lengthLineEdit->setObjectName(QString::fromUtf8("lengthLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lengthLineEdit->sizePolicy().hasHeightForWidth());
        lengthLineEdit->setSizePolicy(sizePolicy);
        lengthLineEdit->setMaximumSize(QSize(50, 25));
        lengthLineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lengthLineEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(120, 0));
        label_3->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(label_3);

        horizontalLayout_3->setStretch(0, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widthSlider = new QSlider(widget);
        widthSlider->setObjectName(QString::fromUtf8("widthSlider"));
        widthSlider->setMinimum(10);
        widthSlider->setMaximum(70);
        widthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(widthSlider);

        widthLineEdit = new QLineEdit(widget);
        widthLineEdit->setObjectName(QString::fromUtf8("widthLineEdit"));
        sizePolicy.setHeightForWidth(widthLineEdit->sizePolicy().hasHeightForWidth());
        widthLineEdit->setSizePolicy(sizePolicy);
        widthLineEdit->setMaximumSize(QSize(50, 25));
        widthLineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(widthLineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(120, 0));
        label_2->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_2->addWidget(label_2);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        minesSlider = new QSlider(widget);
        minesSlider->setObjectName(QString::fromUtf8("minesSlider"));
        minesSlider->setMinimum(10);
        minesSlider->setMaximum(250);
        minesSlider->setValue(10);
        minesSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(minesSlider);

        minesLineEdit = new QLineEdit(widget);
        minesLineEdit->setObjectName(QString::fromUtf8("minesLineEdit"));
        sizePolicy.setHeightForWidth(minesLineEdit->sizePolicy().hasHeightForWidth());
        minesLineEdit->setSizePolicy(sizePolicy);
        minesLineEdit->setMaximumSize(QSize(50, 25));
        minesLineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(minesLineEdit);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(120, 0));
        label->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(label);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("edit-clear");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        cancelButton->setIcon(icon);

        horizontalLayout_4->addWidget(cancelButton);

        okButton = new QPushButton(widget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("emblem-default");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        okButton->setIcon(icon1);

        horizontalLayout_4->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 10);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 10);
        verticalLayout->setStretch(5, 1);
        verticalLayout->setStretch(6, 10);
        verticalLayout->setStretch(7, 3);
        verticalLayout->setStretch(8, 5);

        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Dialog", nullptr));
        difficultyCB->setItemText(0, QString());
        difficultyCB->setItemText(1, QCoreApplication::translate("SettingsDialog", "Leicht (10x10, 10 Minen)", nullptr));
        difficultyCB->setItemText(2, QCoreApplication::translate("SettingsDialog", "Mittel (14x18, 40 Minen)", nullptr));
        difficultyCB->setItemText(3, QCoreApplication::translate("SettingsDialog", "Schwer (20x24, 99 Minen)", nullptr));

        difficultyCB->setCurrentText(QString());
        lengthLineEdit->setPlaceholderText(QCoreApplication::translate("SettingsDialog", "10", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsDialog", "L\303\244nge des Feldes", nullptr));
        widthLineEdit->setPlaceholderText(QCoreApplication::translate("SettingsDialog", "10", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsDialog", "Breite des Feldes", nullptr));
        minesLineEdit->setPlaceholderText(QCoreApplication::translate("SettingsDialog", "10", nullptr));
        label->setText(QCoreApplication::translate("SettingsDialog", "Anzahl von Minen", nullptr));
        cancelButton->setText(QCoreApplication::translate("SettingsDialog", "Cancel", nullptr));
        okButton->setText(QCoreApplication::translate("SettingsDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
