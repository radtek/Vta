#ifndef VTASETTING_H
#define VTASETTING_H

#include <QDialog>

#include <QtGui>
#include <QFileIconProvider>
#include <QtXml/QDomDocument>
#include <QMessageBox>
#include <QTableWidgetItem>
//#include "CaptureImage/captureimage.h"
#include "CaptureImage/imagecropper.h"

namespace Ui {
class VtaSetting;
}

class VtaSetting : public QDialog
{
    Q_OBJECT

public:
    explicit VtaSetting(QWidget *parent = 0);
    ~VtaSetting();
    QStringList VtaVoice,VtaCommandTo,VtaArgument;
    QList<Qt::CheckState> CheckedStat;
    QPoint GetVtaLoc();
    void  writeSettings();
    void  SetLoc(const QPoint& p);
    QString  GetVtaGetUpStr();
    quint64  GetVtaSleepTime();
    QString  GetVtaSleepStr();
    QString  GetHindiTypingTxt() ;
    QString  GetEnglishTypingTxt();
    QString  GetDictionaryTxt();
    bool  GetStartChat();


private slots:

    bool CompareGramStr(const QString& str);
    void on_BtnAdd_clicked();
    void CreatVtaCommandFile();
    void ReadVtaCommandFile();
    void AddRow();
    void ReadCommand();
   void  WriteVtaGram();

    bool  CompareWord(const QString& str);

     void on_BtnSetImage_clicked();

    void on_VtaVoiceTable_cellDoubleClicked(int row, int column);



    void on_BtnExportCommand_clicked();

    void on_BtnImportCommand_clicked();

    void  readSettings();

    void on_CommandType_currentTextChanged(const QString &arg1);

    void on_CBKeyChar_currentTextChanged(const QString &arg1);

    void on_BtnSave_clicked();

    void on_VtaVoiceTable_itemClicked(QTableWidgetItem *item);

    void on_CBKey_currentTextChanged(const QString &arg1);

    void on_CHRecog_clicked();

    void on_CHChatRecog_clicked();

private:
    Ui::VtaSetting *ui;
    QStringList slist,VtaIsVoice;
    QPoint Loc;
   ImageCropper* m_imageCropper;

};

#endif // VTASETTING_H
