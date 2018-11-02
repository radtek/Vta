/********************************************************************************
** Form generated from reading UI file 'vtasetting.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VTASETTING_H
#define UI_VTASETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VtaSetting
{
public:
    QGridLayout *gridLayout;
    QLabel *LblSettingOutPut;
    QTabWidget *VtaSet;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *TxtVtaVoice;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *CommandType;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *CBKey;
    QComboBox *CBKeyChar;
    QLineEdit *TxtVtaCommand;
    QPushButton *BtnSetImage;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BtnExportCommand;
    QPushButton *BtnImportCommand;
    QSpacerItem *horizontalSpacer;
    QPushButton *BtnAdd;
    QTableWidget *VtaVoiceTable;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *CHRecog;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QLineEdit *TxtEnglishTyping;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLineEdit *TxtHindiTyping;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QLineEdit *TxtHindiDictionary;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *CHChatRecog;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *VtaSleepAfter;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *VtaGetUpTxt;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *VtaGetSleepTxt;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *BtnSave;

    void setupUi(QDialog *VtaSetting)
    {
        if (VtaSetting->objectName().isEmpty())
            VtaSetting->setObjectName(QStringLiteral("VtaSetting"));
        VtaSetting->resize(715, 552);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        VtaSetting->setFont(font);
        gridLayout = new QGridLayout(VtaSetting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LblSettingOutPut = new QLabel(VtaSetting);
        LblSettingOutPut->setObjectName(QStringLiteral("LblSettingOutPut"));
        LblSettingOutPut->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(LblSettingOutPut, 0, 0, 1, 1);

        VtaSet = new QTabWidget(VtaSetting);
        VtaSet->setObjectName(QStringLiteral("VtaSet"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        TxtVtaVoice = new QLineEdit(tab);
        TxtVtaVoice->setObjectName(QStringLiteral("TxtVtaVoice"));

        horizontalLayout->addWidget(TxtVtaVoice);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        CommandType = new QComboBox(tab);
        CommandType->setObjectName(QStringLiteral("CommandType"));

        horizontalLayout_4->addWidget(CommandType);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        CBKey = new QComboBox(tab);
        CBKey->setObjectName(QStringLiteral("CBKey"));
        CBKey->setMaximumSize(QSize(300, 16777215));
        CBKey->setEditable(true);

        horizontalLayout_2->addWidget(CBKey);

        CBKeyChar = new QComboBox(tab);
        CBKeyChar->setObjectName(QStringLiteral("CBKeyChar"));
        CBKeyChar->setMaximumSize(QSize(250, 16777215));
        CBKeyChar->setEditable(true);

        horizontalLayout_2->addWidget(CBKeyChar);

        TxtVtaCommand = new QLineEdit(tab);
        TxtVtaCommand->setObjectName(QStringLiteral("TxtVtaCommand"));

        horizontalLayout_2->addWidget(TxtVtaCommand);

        BtnSetImage = new QPushButton(tab);
        BtnSetImage->setObjectName(QStringLiteral("BtnSetImage"));

        horizontalLayout_2->addWidget(BtnSetImage);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        BtnExportCommand = new QPushButton(tab);
        BtnExportCommand->setObjectName(QStringLiteral("BtnExportCommand"));

        horizontalLayout_3->addWidget(BtnExportCommand);

        BtnImportCommand = new QPushButton(tab);
        BtnImportCommand->setObjectName(QStringLiteral("BtnImportCommand"));

        horizontalLayout_3->addWidget(BtnImportCommand);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        BtnAdd = new QPushButton(tab);
        BtnAdd->setObjectName(QStringLiteral("BtnAdd"));

        horizontalLayout_3->addWidget(BtnAdd);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        VtaVoiceTable = new QTableWidget(tab);
        if (VtaVoiceTable->columnCount() < 4)
            VtaVoiceTable->setColumnCount(4);
        VtaVoiceTable->setObjectName(QStringLiteral("VtaVoiceTable"));
        VtaVoiceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        VtaVoiceTable->setDragDropOverwriteMode(false);
        VtaVoiceTable->setDragDropMode(QAbstractItemView::NoDragDrop);
        VtaVoiceTable->setDefaultDropAction(Qt::IgnoreAction);
        VtaVoiceTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        VtaVoiceTable->setColumnCount(4);
        VtaVoiceTable->horizontalHeader()->setStretchLastSection(true);

        gridLayout_2->addWidget(VtaVoiceTable, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        VtaSet->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_3->addLayout(verticalLayout_5);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        CHRecog = new QCheckBox(groupBox);
        CHRecog->setObjectName(QStringLiteral("CHRecog"));

        verticalLayout_7->addWidget(CHRecog);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_10->addWidget(label_5);

        TxtEnglishTyping = new QLineEdit(groupBox);
        TxtEnglishTyping->setObjectName(QStringLiteral("TxtEnglishTyping"));

        horizontalLayout_10->addWidget(TxtEnglishTyping);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_9->addWidget(label_4);

        TxtHindiTyping = new QLineEdit(groupBox);
        TxtHindiTyping->setObjectName(QStringLiteral("TxtHindiTyping"));

        horizontalLayout_9->addWidget(TxtHindiTyping);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_13->addWidget(label_10);

        TxtHindiDictionary = new QLineEdit(groupBox);
        TxtHindiDictionary->setObjectName(QStringLiteral("TxtHindiDictionary"));

        horizontalLayout_13->addWidget(TxtHindiDictionary);


        verticalLayout_6->addLayout(horizontalLayout_13);


        verticalLayout_7->addLayout(verticalLayout_6);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        CHChatRecog = new QCheckBox(groupBox_2);
        CHChatRecog->setObjectName(QStringLiteral("CHChatRecog"));

        verticalLayout_8->addWidget(CHChatRecog);


        verticalLayout_7->addWidget(groupBox_2);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        VtaSleepAfter = new QLineEdit(tab_2);
        VtaSleepAfter->setObjectName(QStringLiteral("VtaSleepAfter"));

        horizontalLayout_5->addWidget(VtaSleepAfter);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        VtaGetUpTxt = new QLineEdit(tab_2);
        VtaGetUpTxt->setObjectName(QStringLiteral("VtaGetUpTxt"));

        horizontalLayout_6->addWidget(VtaGetUpTxt);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        VtaGetSleepTxt = new QLineEdit(tab_2);
        VtaGetSleepTxt->setObjectName(QStringLiteral("VtaGetSleepTxt"));

        horizontalLayout_7->addWidget(VtaGetSleepTxt);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        BtnSave = new QPushButton(tab_2);
        BtnSave->setObjectName(QStringLiteral("BtnSave"));

        horizontalLayout_8->addWidget(BtnSave);


        verticalLayout_4->addLayout(horizontalLayout_8);


        gridLayout_4->addLayout(verticalLayout_4, 0, 0, 1, 1);

        VtaSet->addTab(tab_2, QString());

        gridLayout->addWidget(VtaSet, 1, 0, 1, 1);


        retranslateUi(VtaSetting);

        VtaSet->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(VtaSetting);
    } // setupUi

    void retranslateUi(QDialog *VtaSetting)
    {
        VtaSetting->setWindowTitle(QApplication::translate("VtaSetting", "Vta Setting", 0));
        LblSettingOutPut->setText(QApplication::translate("VtaSetting", "Vta-By Deep Govind,   Email:deepgovind4@gmail.com,  Mob No. : 7388966141", 0));
        label->setText(QApplication::translate("VtaSetting", "Write Voice Text :", 0));
        CommandType->clear();
        CommandType->insertItems(0, QStringList()
         << QApplication::translate("VtaSetting", "ToCMD", 0)
         << QApplication::translate("VtaSetting", "DoubleClick", 0)
         << QApplication::translate("VtaSetting", "SingleClick", 0)
         << QApplication::translate("VtaSetting", "SendKey", 0)
        );
        label_3->setText(QApplication::translate("VtaSetting", "Select Type", 0));
        label_2->setText(QApplication::translate("VtaSetting", "Write Arguments :", 0));
        BtnSetImage->setText(QApplication::translate("VtaSetting", "Capture Image", 0));
        BtnExportCommand->setText(QApplication::translate("VtaSetting", "Export Command", 0));
        BtnImportCommand->setText(QApplication::translate("VtaSetting", "Import Command", 0));
        BtnAdd->setText(QApplication::translate("VtaSetting", "Add", 0));
        VtaSet->setTabText(VtaSet->indexOf(tab), QApplication::translate("VtaSetting", "Vta Add Voice", 0));
        groupBox->setTitle(QString());
        CHRecog->setText(QApplication::translate("VtaSetting", "off Recognize", 0));
        label_5->setText(QApplication::translate("VtaSetting", "Start English Typing Txt : ", 0));
        label_4->setText(QApplication::translate("VtaSetting", "Start Hindi Typing Txt   :   ", 0));
        label_10->setText(QApplication::translate("VtaSetting", "Start Hindi Dictionary :     ", 0));
        groupBox_2->setTitle(QString());
        CHChatRecog->setText(QApplication::translate("VtaSetting", "off Chat Recognize", 0));
        label_8->setText(QApplication::translate("VtaSetting", "Set Time To Sleep :", 0));
        VtaSleepAfter->setText(QApplication::translate("VtaSetting", "5", 0));
        label_9->setText(QApplication::translate("VtaSetting", "Second", 0));
        label_7->setText(QApplication::translate("VtaSetting", "Set Txt To Get Up :", 0));
        VtaGetUpTxt->setText(QApplication::translate("VtaSetting", "get up", 0));
        label_6->setText(QApplication::translate("VtaSetting", "Set Txt To Sleep   :", 0));
        VtaGetSleepTxt->setText(QApplication::translate("VtaSetting", "go to sleep", 0));
        BtnSave->setText(QApplication::translate("VtaSetting", "Save", 0));
        VtaSet->setTabText(VtaSet->indexOf(tab_2), QApplication::translate("VtaSetting", "Vta Default Voice", 0));
    } // retranslateUi

};

namespace Ui {
    class VtaSetting: public Ui_VtaSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VTASETTING_H
