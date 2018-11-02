#ifndef VTA_H
#define VTA_H

#include <QMainWindow>
#include "vtatask.h"
#include <QtGui>
#include "VtaSpeak/vtaspeak.h"
#include "VtaAiml/vtaaiml.h"
#include "VtaSpeak/vtaspeakrecognize.h"
#include "vtasetting.h"
#include <QSystemTrayIcon>
#include "windowsfuncations.h"
#include "opencvfun.h"
#include <QDesktopWidget>
#include <QMovie>
#include "convertor.h"

namespace Ui {
class VTA;
}

class VTA : public QMainWindow
{
    Q_OBJECT

public:
    explicit VTA(QWidget *parent = 0);
    ~VTA();

private slots:

    void  Help();
    void  VtaSettingShow();

     void on_BtnSendToVTA_clicked();
     void keyPressEvent(QKeyEvent *event);


      void StartVta();
     QString FilterRecognizeString(const QString& str);

     void  CreatTroy();

      void  mousePressEvent(QMouseEvent *u);
      void  mouseMoveEvent(QMouseEvent *u);
      void  mouseReleaseEvent(QMouseEvent *event);

      void  VtaSetup();
      void StartReco();

   void StopMovie();
   void StartMovie();

   QPoint GetClickPoint(const QString& str);
   bool  DoCommand(const QString& str);
    QPixmap CaptureDesktop();
   void cmdCommand(const QString& str,const QStringList& sl);
    void  StartTypingT(const QString& Lan);

   void on_TxtInput_textChanged(const QString &arg1);

private:
    Ui::VTA *ui;
    QPoint point;

    VtaSpeak *VtaSpeek;
    VtaSpeakRecognize *VtaSpeekRecognize;
     VtaAiml *VtaAIML;

    VTATask *VtaTask;
    VtaSetting *VtaVoiceSetting;

    // OpenCvFun *OpenCvF;
   // bool isRecognize;
    bool isVtaOn,isChatOn;
    quint64 VtaTime;

    QSystemTrayIcon *VtaTroy;
    QMenu *VtaTroyMenu;

    QAction *VtaSettingS;
    QAction *VtaHelp;
    QAction *Quit;

    QMovie  *movie;
      int TxtInputLe;
     QTimer *timer;
};

#endif // VTA_H
