/********************************************************************************
** Form generated from reading UI file 'vta.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VTA_H
#define UI_VTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VTA
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *TxtInput;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *vtaWait;
    QLabel *TypingLbl;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *VTA)
    {
        if (VTA->objectName().isEmpty())
            VTA->setObjectName(QStringLiteral("VTA"));
        VTA->resize(296, 127);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        VTA->setFont(font);
        centralWidget = new QWidget(VTA);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        TxtInput = new QLineEdit(centralWidget);
        TxtInput->setObjectName(QStringLiteral("TxtInput"));
        QFont font1;
        font1.setPointSize(10);
        TxtInput->setFont(font1);
        TxtInput->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(TxtInput, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(90, 70));
        label->setMaximumSize(QSize(91, 71));
        label->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 4, 1);

        vtaWait = new QLabel(centralWidget);
        vtaWait->setObjectName(QStringLiteral("vtaWait"));
        vtaWait->setMinimumSize(QSize(40, 30));
        vtaWait->setMaximumSize(QSize(41, 31));
        vtaWait->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(vtaWait, 1, 1, 1, 1);

        TypingLbl = new QLabel(centralWidget);
        TypingLbl->setObjectName(QStringLiteral("TypingLbl"));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(11);
        TypingLbl->setFont(font2);
        TypingLbl->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(TypingLbl, 2, 1, 1, 1);

        VTA->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VTA);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 296, 21));
        VTA->setMenuBar(menuBar);

        retranslateUi(VTA);

        QMetaObject::connectSlotsByName(VTA);
    } // setupUi

    void retranslateUi(QMainWindow *VTA)
    {
        VTA->setWindowTitle(QApplication::translate("VTA", "VTA", 0));
        TxtInput->setText(QString());
        label->setText(QString());
        vtaWait->setText(QString());
        TypingLbl->setText(QApplication::translate("VTA", "Vta", 0));
    } // retranslateUi

};

namespace Ui {
    class VTA: public Ui_VTA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VTA_H
