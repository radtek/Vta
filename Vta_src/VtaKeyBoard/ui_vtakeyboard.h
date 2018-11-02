/********************************************************************************
** Form generated from reading UI file 'vtakeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VTAKEYBOARD_H
#define UI_VTAKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VtaKeyBoard
{
public:
    QWidget *centralWidget;
    QLineEdit *InputText;
    QTextEdit *textEdit;
    QLineEdit *InputText_2;
    QLineEdit *VtaInputText;

    void setupUi(QMainWindow *VtaKeyBoard)
    {
        if (VtaKeyBoard->objectName().isEmpty())
            VtaKeyBoard->setObjectName(QStringLiteral("VtaKeyBoard"));
        VtaKeyBoard->resize(456, 335);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(11);
        VtaKeyBoard->setFont(font);
        centralWidget = new QWidget(VtaKeyBoard);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        InputText = new QLineEdit(centralWidget);
        InputText->setObjectName(QStringLiteral("InputText"));
        InputText->setGeometry(QRect(190, 130, 241, 31));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(130, 10, 321, 81));
        InputText_2 = new QLineEdit(centralWidget);
        InputText_2->setObjectName(QStringLiteral("InputText_2"));
        InputText_2->setGeometry(QRect(0, 100, 249, 30));
        VtaInputText = new QLineEdit(centralWidget);
        VtaInputText->setObjectName(QStringLiteral("VtaInputText"));
        VtaInputText->setGeometry(QRect(30, 190, 241, 31));
        VtaKeyBoard->setCentralWidget(centralWidget);

        retranslateUi(VtaKeyBoard);

        QMetaObject::connectSlotsByName(VtaKeyBoard);
    } // setupUi

    void retranslateUi(QMainWindow *VtaKeyBoard)
    {
        VtaKeyBoard->setWindowTitle(QApplication::translate("VtaKeyBoard", "VtaKeyBoard", 0));
    } // retranslateUi

};

namespace Ui {
    class VtaKeyBoard: public Ui_VtaKeyBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VTAKEYBOARD_H
