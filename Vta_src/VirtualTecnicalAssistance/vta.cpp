#include "vta.h"
#include "ui_vta.h"
#include <QMessageBox>
#include <QtTest/QTest>
#include <QAction>
#include <QCheckBox>
#include <QComboBox>
#include <QCoreApplication>
#include <QCloseEvent>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>

VTA::VTA(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::VTA)
{
     ui->setupUi(this);

    VtaSetup();

   ui->vtaWait->setVisible(false);
    ui->TypingLbl->setStyleSheet("color: rgb(0, 0, 255);");

 }

VTA::~VTA()
{
    VtaSpeek->StopSpeakProcess();
    VtaSpeekRecognize->StopRecognize();
    delete ui;
}
QPoint VTA::GetClickPoint(const QString& str)
{
////////////////////////////////////////////////////////////////
     QPoint  RPoint,PointXY;
     PointXY = WindowsFuncations::CaptureActiveWindow();

     QPixmap  pa = QPixmap::fromImage(QImage(qApp->applicationDirPath()+"/VtaFiles/DesktopActive.png"));

     QPixmap pd =   CaptureDesktop();

   if(pa.height() == pd.height() && pa.width() == pd.width())
   {
      ui->TxtInput->setText("No active Windows");
   }
   else
   {
        QPoint pointm =  OpenCvFun::MatchImage(qApp->applicationDirPath()+"/VtaFiles/DesktopActive.png",qApp->applicationDirPath()+"/VtaImage/"+str);

        if(pointm.x() == 0 && pointm.y() == 0)
        {
            RPoint.setX(0);
            RPoint.setY(0);
        }
        else
        {
            RPoint.setX(PointXY.x()+pointm.x()+5);
            RPoint.setY(PointXY.y()+pointm.y()+5);
        }
   }


   return RPoint;
}
void VTA::VtaSetup()
{

     setWindowFlags(Qt::Widget | Qt::FramelessWindowHint );
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground,true);
    setAttribute(Qt::WA_TranslucentBackground,true);
    setAttribute(Qt::WA_PaintOnScreen);
    setWindowOpacity(0.60);


    ui->label->setStyleSheet( "border-image: url("+qApp->applicationDirPath()+"/VtaIcon/Vta.png);");
    ui->vtaWait->setStyleSheet( "border-image: url("+qApp->applicationDirPath()+"/VtaIcon/VtaWait.gif);");


   VtaSpeek = new VtaSpeak();
   VtaSpeekRecognize = new VtaSpeakRecognize();
   VtaTask = new VTATask();
   VtaVoiceSetting = new VtaSetting(this);

   VtaAIML =  new VtaAiml("English_");

   CreatTroy();
   VtaTroy->show();

   this->move(VtaVoiceSetting->GetVtaLoc());

    StartReco();

   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(StartVta()));
   timer->start(500);
   VtaTime = 0;
  this->show();

   StartMovie();
  if(!VtaVoiceSetting->GetStartChat())
  {
     VtaSpeek->StartSpeak("Wait For Loading AIML. voice Command is enable for AIML.");
  }
  else
  {
      VtaSpeek->StartSpeak("Wait For Loading AIML. voice Command is Disable for AIML.");

  }
  ui->TxtInput->setText(VtaAIML->setAIMLSet("English"));

  StopMovie();
}

void VTA::StartReco()
{
     StartMovie();
     bool isR = VtaSpeekRecognize->StartRecognize();
     StopMovie();

    if(isR)
    {
        isVtaOn  =true;
        ui->TxtInput->setText("Recognize Started ");
    }
    else
    {
        isVtaOn  = false;
        ui->TxtInput->setText("Recognize Not Started ");
    }



}

void VTA::Help()
{
     QFile file(qApp->applicationDirPath()+"/VtaFiles/VtaHelp.Vta");

    if(file.open(QIODevice::ReadOnly))
    {
        QTextEdit *te = new QTextEdit();
        te->setText(file.readAll());
        te->setWindowTitle("Vta Help");
        te->setGeometry(30,30,526,515);
        te->show();
    }

}
void VTA::StartTypingT(const QString& Lan)
{

    StartMovie();
    QProcess *tp = new QProcess();
    tp->execute("VtaTyperEnHi.exe",QStringList()<<Lan);
    tp->waitForStarted();
    StopMovie();

      if(Lan == "Hi")
           ui->TxtInput->setText("HindiTyping Starting..   ");
        else
           ui->TxtInput->setText("EnglishTyping Starting..   ");

      isVtaOn = false;
  //  ui->TxtInput->setText("Vta Is in Sleep , Say : "+VtaVoiceSetting->GetVtaGetUpStr());

}

bool VTA::DoCommand(const QString& str)
{
   bool isCommand =  false;
     ui->TxtInput->setText(str);
    if(str == VtaVoiceSetting->GetVtaSleepStr())
    {
        isVtaOn = false;
        ui->TxtInput->setText("Vta Is in Sleep , Say : "+VtaVoiceSetting->GetVtaGetUpStr());

        isCommand = true;
        return true;
    }
    else if(str == VtaVoiceSetting->GetHindiTypingTxt())
    {
          VtaSpeek->StartSpeak("Hindi Typing Starting Please wait");
       // VtaSpeek->StartSpeak("Hindi Typing on open a Notepad and Start Speaking Say Show Dictionary To Show Dictionarty");
        StartTypingT("Hi");
          isCommand = true;
        return true;
    }
    else if(str == VtaVoiceSetting->GetEnglishTypingTxt())
    {
           VtaSpeek->StartSpeak("English Typing Starting Please wait");
        //VtaSpeek->StartSpeak("English Typing On Open a Notepad and Start Speaking Say Show Dictionary To Show Dictionarty");
         StartTypingT("En");
           isCommand = true;
        return true;
    }
    else if(str == VtaVoiceSetting->GetDictionaryTxt())
    {

         QProcess *pr   = new QProcess();
         pr->execute("VtaKeyBoard.exe");
         pr->waitForStarted();

           isCommand = true;

      return true;
    }
      for(int i = 0;i<VtaVoiceSetting->VtaVoice.length();i++)
      {
         QString st =  VtaVoiceSetting->VtaVoice.at(i);


         if(st == str)
         {
            QString ct =   VtaVoiceSetting->VtaCommandTo.at(i);


            if(ct == "DoubleClick")
            {
                  isCommand = true;

              Qt::CheckState cs = VtaVoiceSetting->CheckedStat.at(i);
              if(cs == Qt::Checked)
              {
                    int ans =   QMessageBox::warning(this,"Message","Do You Went To Close",QMessageBox::Yes,QMessageBox::No);
                     if(ans == QMessageBox::Yes)
                     {
                         QString imgadd =   VtaVoiceSetting->VtaArgument.at(i);
                         QPoint p  = GetClickPoint(imgadd);
                         if(p.x() == 0 && p.y() == 0)
                         {

                         }
                         else
                            WindowsFuncations::DoubleClick(p.x(),p.y());
                     }

              }
              else
              {
                   QString imgadd =   VtaVoiceSetting->VtaArgument.at(i);
                   QPoint p  = GetClickPoint(imgadd);
                   if(p.x() == 0 && p.y() == 0)
                   {

                   }
                   else
                      WindowsFuncations::DoubleClick(p.x(),p.y());
              }


            }
            else if(ct == "SingleClick")
            {
                  isCommand = true;

                Qt::CheckState cs = VtaVoiceSetting->CheckedStat.at(i);
                if(cs == Qt::Checked)
                {
                      int ans =   QMessageBox::warning(this,"Message","Do You Went To Sure :"+VtaVoiceSetting->VtaArgument.at(i),QMessageBox::Yes,QMessageBox::No);
                       if(ans == QMessageBox::Yes)
                       {
                           QString imgadd =   VtaVoiceSetting->VtaArgument.at(i);
                           QPoint p  = GetClickPoint(imgadd);
                           if(p.x() == 0 && p.y() == 0)
                           {

                           }
                           else
                              WindowsFuncations::SingleClick(p.x(),p.y());
                       }
                }
                else
                {
                    QString imgadd =   VtaVoiceSetting->VtaArgument.at(i);
                    QPoint p  = GetClickPoint(imgadd);
                    if(p.x() == 0 && p.y() == 0)
                    {

                    }
                    else
                      WindowsFuncations::SingleClick(p.x(),p.y());

                }

            }
            else if(ct == "SendKey")
            {

                  isCommand = true;

                  Qt::CheckState cs = VtaVoiceSetting->CheckedStat.at(i);
                if(cs == Qt::Checked)
                {
                      int ans =   QMessageBox::warning(0,"Message","Do You Went Sure "+VtaVoiceSetting->VtaArgument.at(i),QMessageBox::Yes,QMessageBox::No);
                       if(ans == QMessageBox::Yes)
                       {

                           unsigned short FKey =  0;
                           unsigned short FKeyChar = 0;
                           QString sendkey =   VtaVoiceSetting->VtaArgument.at(i);
                           QStringList slist = sendkey.split(";",QString::SkipEmptyParts);
                            QString Key,KeyChar;
                           for(int l = 0;l<slist.length();l++)
                           {
                               QString slistlist = slist.at(l);
                               QStringList sll  =  slistlist.split("+",QString::SkipEmptyParts);
                                 if(sll.length() == 1)
                                 {
                                     Key = sll.at(0);
                                    if(Key.startsWith("VK_",Qt::CaseInsensitive))
                                    {
                                        QRegularExpression re("VK_(\\w+.*){(\\w+.*)}$",QRegularExpression::CaseInsensitiveOption);
                                        QRegularExpressionMatch match = re.match(Key);
                                        if (match.hasMatch())
                                        {
                                            bool ok;
                                            FKey = match.captured(2).replace("0x","").toUShort(&ok,16);

                                        }
                                    }
                                    else
                                    {
                                       FKey = Key.data()->toLatin1() ;
                                    }
                                       WindowsFuncations::SendSingleKey(FKey);

                                 }
                                 else
                                 {
                                      KeyChar = sll.at(1);
                                      Key = sll.at(0);


                                     if(KeyChar.startsWith("VK_",Qt::CaseInsensitive))
                                     {
                                         QRegularExpression re("VK_(\\w+.*){(\\w+.*)}$",QRegularExpression::CaseInsensitiveOption);
                                         QRegularExpressionMatch match = re.match(KeyChar);
                                          if (match.hasMatch())
                                          {
                                               bool ok;
                                               FKeyChar = match.captured(2).replace("0x","").toUShort(&ok,16);

                                          }
                                     }
                                     else
                                     {
                                         FKeyChar = KeyChar.data()->toLatin1() ;
                                     }
                                     if(Key.startsWith("VK_",Qt::CaseInsensitive))
                                     {
                                         QRegularExpression re("VK_(\\w+.*){(\\w+.*)}$",QRegularExpression::CaseInsensitiveOption);
                                         QRegularExpressionMatch match = re.match(Key);
                                         if (match.hasMatch())
                                         {
                                             bool ok;
                                             FKey = match.captured(2).replace("0x","").toUShort(&ok,16);

                                         }
                                     }
                                     else
                                     {
                                        FKey = Key.data()->toLatin1() ;
                                     }
                                         WindowsFuncations::SendKey(FKey,FKeyChar);

                                 }
                           }

                       }
                }
                else
                {


                    unsigned short FKey =  0;
                    unsigned short FKeyChar = 0;
                    QString sendkey =   VtaVoiceSetting->VtaArgument.at(i);
                    QStringList slist = sendkey.split(";",QString::SkipEmptyParts);
                     QString Key,KeyChar;
                    for(int l = 0;l<slist.length();l++)
                    {
                        QString slistlist = slist.at(l);
                        QStringList sll  =  slistlist.split("+",QString::SkipEmptyParts);
                          if(sll.length() == 1)
                          {
                              Key = sll.at(0);
                             if(Key.startsWith("VK_",Qt::CaseInsensitive))
                             {
                                 QRegularExpression re("VK_(\\w+.*){(\\w+.*)}$",QRegularExpression::CaseInsensitiveOption);
                                 QRegularExpressionMatch match = re.match(Key);
                                 if (match.hasMatch())
                                 {
                                     bool ok;
                                     FKey = match.captured(2).replace("0x","").toUShort(&ok,16);

                                 }
                             }
                             else
                             {
                                FKey = Key.data()->toLatin1() ;
                             }
                                WindowsFuncations::SendSingleKey(FKey);

                          }
                          else
                          {
                               KeyChar = sll.at(1);
                               Key = sll.at(0);


                              if(KeyChar.startsWith("VK_",Qt::CaseInsensitive))
                              {
                                  QRegularExpression re("VK_(\\w+.*){(\\w+.*)}$",QRegularExpression::CaseInsensitiveOption);
                                  QRegularExpressionMatch match = re.match(KeyChar);
                                   if (match.hasMatch())
                                   {
                                        bool ok;
                                        FKeyChar = match.captured(2).replace("0x","").toUShort(&ok,16);

                                   }
                              }
                              else
                              {
                                  FKeyChar = KeyChar.data()->toLatin1() ;
                              }
                              if(Key.startsWith("VK_",Qt::CaseInsensitive))
                              {
                                  QRegularExpression re("VK_(\\w+.*){(\\w+.*)}$",QRegularExpression::CaseInsensitiveOption);
                                  QRegularExpressionMatch match = re.match(Key);
                                  if (match.hasMatch())
                                  {
                                      bool ok;
                                      FKey = match.captured(2).replace("0x","").toUShort(&ok,16);

                                  }
                              }
                              else
                              {
                                 FKey = Key.data()->toLatin1() ;
                              }
                                  WindowsFuncations::SendKey(FKey,FKeyChar);

                          }


                    }

                }


            }
            else if(ct == "ToCMD")
            {

                  isCommand = true;

                Qt::CheckState cs = VtaVoiceSetting->CheckedStat.at(i);
                if(cs == Qt::Checked)
                {
                      int ans =   QMessageBox::warning(this,"Message","Do You Went Sure : "+VtaVoiceSetting->VtaArgument.at(i),QMessageBox::Yes,QMessageBox::No);
                       if(ans == QMessageBox::Yes)
                       {
                           QString cmd =   VtaVoiceSetting->VtaArgument.at(i);
                           QStringList sl =  cmd.split(QRegExp("\\s+"),QString::SkipEmptyParts);
                            QString s = sl.at(0);
                            sl.removeAt(0);
                            cmdCommand(s,sl);
                       }
                }
                else
                {
                    QString cmd =   VtaVoiceSetting->VtaArgument.at(i);
                    QStringList sl =  cmd.split(QRegExp("\\s+"),QString::SkipEmptyParts);
                     QString s = sl.at(0);
                     sl.removeAt(0);
                      cmdCommand(s,sl);

                }


            }


         }


      }

     if(!isCommand)
     {
    //    if(!VtaVoiceSetting->GetStartChat())
   //     {
          QString stra =  VtaAIML->validateInput(ui->TxtInput->text());
          ui->TxtInput->setText(stra);
          VtaSpeek->StartSpeak(stra);
     //   }
     }

      return false;
}
QPixmap VTA::CaptureDesktop()
{
    QScreen *s = QGuiApplication::primaryScreen();
    if(s)
    {

          QPixmap  p = s->grabWindow(QApplication::desktop()->winId());
          return p;
    }


}
void VTA::cmdCommand(const QString& str,const QStringList& sl)
{
    QProcess *p  = new QProcess();
    if(p->isOpen())
        p->close();

    p->start(str,sl);
    p->waitForStarted();
}




void VTA::StartVta()
{

      if(!VtaVoiceSetting->GetVtaGetUpStr().isEmpty())
      {
          VtaTime = VtaTime + 1;

        if(VtaTime >= VtaVoiceSetting->GetVtaSleepTime()*3)
        {
            isVtaOn = false;
            ui->TxtInput->setText("Vta Is in Sleep , Say : "+VtaVoiceSetting->GetVtaGetUpStr());
            setWindowIcon(QIcon(QPixmap(qApp->applicationDirPath()+"/VtaIcon/VtaRed.png")));
        }
      }


        if(this->isActiveWindow())
        {
             setWindowOpacity(1);
        }
        else
        {
             setWindowOpacity(0.50);
        }


         qApp->processEvents();
      // VtaSpeekRecognize->SpeakRecoProcess->waitForReadyRead(1000);
         if(VtaSpeekRecognize->SpeakRecoProcess->canReadLine())
         {
              QByteArray result = VtaSpeekRecognize->SpeakRecoProcess->readLine();
              QString str =  FilterRecognizeString(result);
              // qDebug()<<str<<" Th";
              ui->TypingLbl->setText(str);
             ui->TxtInput->setText("Vta is On");
               if(!str.isEmpty())
              {
                   if(isVtaOn)
                   {
                       if(DoCommand(str))
                      {
                          VtaTime = 0;
                      }

                   }
                   else
                   {

                      if(str == VtaVoiceSetting->GetVtaGetUpStr())
                      {
                           isVtaOn = true;
                           ui->TypingLbl->setStyleSheet("color: rgb(0, 0, 255);");
                           ui->TxtInput->setText("Vta is On");
                        //   ui->TypingLbl->setText("Vta is On");
                             VtaSpeek->StartSpeak("Vta is now on");
                      }
                      else
                      {
                        ui->TypingLbl->setStyleSheet("color: rgb(255, 0, 0);");
                        ui->TxtInput->setText("Vta is in sleep");
                    //   VtaSpeek->StartSpeak("Vta is Sleep. Please Say "+VtaVoiceSetting->GetVtaGetUpStr());
                     }
                       VtaTime = 0;

                   }
             }
         }

}
void VTA::StartMovie()
{
    ui->vtaWait->show();
     movie = new QMovie(qApp->applicationDirPath()+"/VtaIcon/VtaWait.gif");
    QSize s(40,31);
    movie->setScaledSize(s);
    ui->vtaWait->setMovie(movie);
    movie->start();
}
void VTA::StopMovie()
{
    movie->stop();
    ui->vtaWait->hide();
}

void VTA::mousePressEvent(QMouseEvent *u)
{
    point =  u->pos();
}
void VTA::mouseReleaseEvent(QMouseEvent *event)
{
     VtaVoiceSetting->writeSettings();
}

void VTA::mouseMoveEvent(QMouseEvent *u)
{
   this->move(u->pos() - point +this->pos());  
   VtaVoiceSetting->SetLoc(u->pos() - point +this->pos());

}

void VTA::VtaSettingShow()
{
     VtaVoiceSetting->show();
}
void VTA::CreatTroy()
{
   // VtaSettingShow();

    VtaSettingS = new QAction(tr("Vta Setting"), this);
    connect(VtaSettingS, SIGNAL(triggered()), this,SLOT(VtaSettingShow()));

    VtaHelp = new QAction(tr("Vta Help"), this);
    connect(VtaHelp,  SIGNAL(triggered()), this,SLOT(Help()));

    Quit = new QAction(tr("&Quit"), this);
    connect(Quit, &QAction::triggered, qApp, &QGuiApplication::quit);


    VtaTroyMenu = new QMenu(this);
    VtaTroyMenu->addAction(VtaSettingS);
    VtaTroyMenu->addAction(VtaHelp);
    VtaTroyMenu->addSeparator();
    VtaTroyMenu->addAction(Quit);

    VtaTroy = new QSystemTrayIcon(this);
    VtaTroy->setContextMenu(VtaTroyMenu);
    VtaTroy->setIcon(QIcon(QPixmap(qApp->applicationDirPath()+"/VtaIcon/VtaBlue.png")));

}

QString VTA::FilterRecognizeString(const QString& str)
{
    QString string = str;
    if(string.startsWith("[VtaSR"))
    {
         string.replace("[VtaSR debug] ","",Qt::CaseInsensitive);
         string.replace("[VtaSR debug]","",Qt::CaseInsensitive);
          string.replace("[VtaSR] ","",Qt::CaseInsensitive);
          string.replace("[VtaSR]","",Qt::CaseInsensitive);
           string.replace("\r\n","",Qt::CaseInsensitive);


    }
    else if(string.startsWith("[VtaSpeach]"))
    {
         string.replace("[VtaSpeach] ","",Qt::CaseInsensitive);
         string.replace(" [VtaSpeach]","",Qt::CaseInsensitive);
         string.replace("\r\n","");
         return string;
    }
    else
    {
        string.replace("\r\n","");
        QMessageBox::critical(this,"Vta Error ! ",string);
        VtaSpeek->StopSpeakProcess();
        VtaSpeekRecognize->StopRecognize();
    }
    return "";


}


void VTA::on_BtnSendToVTA_clicked()
{/*
     if(ui->TxtInput->text() == "chat")
     {
          StartMovie();
           VtaSpeek->StartSpeak("Wait For Loading AIML");
           ui->TxtInput->setText(VtaAIML->setAIMLSet("English"));
          StopMovie();
          isChatOn = true;
     }
     if(ui->TxtInput->text() == "chat off")
     {
         VtaAIML->ClearAiml();
         isChatOn = false;
     }

    if(!DoCommand(ui->TxtInput->text()))
    {
        if(isChatOn)
        {
           QString str =  VtaAIML->validateInput(ui->TxtInput->text());
           ui->TxtInput->setText(str);
           VtaSpeek->StartSpeak(str);
        }
    } */
           DoCommand(ui->TxtInput->text());
}

void VTA::keyPressEvent(QKeyEvent *event)
{
     switch (event->key())
     {
          case Qt::Key_Return:
          {
                on_BtnSendToVTA_clicked();
               break;
              }
          default:
            QWidget::keyPressEvent(event);
        }
}


void VTA::on_TxtInput_textChanged(const QString &arg1)
{
     if(TxtInputLe > ui->TxtInput->text().length())
    {

         this->setGeometry(this->geometry().x(),this->geometry().y(),this->width()-6*(TxtInputLe-ui->TxtInput->text().length()),this->height());

     }
     else
     {
         this->setGeometry(this->geometry().x(),this->geometry().y(),this->width()+6*(ui->TxtInput->text().length()-TxtInputLe),this->height());

     }
     TxtInputLe = ui->TxtInput->text().length();
}
