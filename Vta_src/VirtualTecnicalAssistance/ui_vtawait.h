/********************************************************************************
** Form generated from reading UI file 'vtawait.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VTAWAIT_H
#define UI_VTAWAIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VtaWait
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *labelw;

    void setupUi(QDialog *VtaWait)
    {
        if (VtaWait->objectName().isEmpty())
            VtaWait->setObjectName(QStringLiteral("VtaWait"));
        VtaWait->resize(247, 110);
        gridLayout = new QGridLayout(VtaWait);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(VtaWait);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/VtaIcon/VtaBlue.png);"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(VtaWait);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        labelw = new QLabel(VtaWait);
        labelw->setObjectName(QStringLiteral("labelw"));
        labelw->setStyleSheet(QStringLiteral("border-image: url(:/VtaIcon/VtaWait.gif);"));

        verticalLayout->addWidget(labelw);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(VtaWait);

        QMetaObject::connectSlotsByName(VtaWait);
    } // setupUi

    void retranslateUi(QDialog *VtaWait)
    {
        VtaWait->setWindowTitle(QApplication::translate("VtaWait", "Dialog", 0));
        label_2->setText(QString());
        label->setText(QString());
        labelw->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VtaWait: public Ui_VtaWait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VTAWAIT_H
