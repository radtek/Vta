#include "vtasetting.h"
#include "ui_vtasetting.h"
#include <QFileDialog>
#include <QtTest/QTest>
#include <QDesktopWidget>

VtaSetting::VtaSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VtaSetting)
{
    ui->setupUi(this);
    ui->VtaVoiceTable->setHorizontalHeaderLabels(QStringList()<<"Show Message/Command to"<<"VtaVoice"<<"Command Arg / Image");
    ui->VtaVoiceTable->hideColumn(3);

    QFile file(qApp->applicationDirPath()+"/VtaFiles/VtaVoiceWordList.Vta");
    if(!file.open(QFile::ReadOnly))
    {
        QMessageBox::critical(this,"error","WordList Opening Faill ! ");
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        slist<<in.readLine();
    }

    ReadVtaCommandFile();
    readSettings();
    ReadCommand();
    WriteVtaGram();
    writeSettings();

    ui->CBKey->hide();
    ui->CBKeyChar->hide();
    ui->BtnSetImage->hide();


}


void VtaSetting::SetLoc(const QPoint& p)
{
     Loc.setX(p.x());
     Loc.setY(p.y());
}

void VtaSetting::writeSettings()
  {
      QSettings settings("Vta", "Setting");
      settings.beginGroup("VtaSetting");

      settings.setValue("thisgeometry",this->geometry());
      settings.setValue("VtaLoc_X",QString::number(Loc.x()));
      settings.setValue("VtaLoc_Y",QString::number(Loc.y()));

      settings.setValue("VtaGetUpTxt",ui->VtaGetUpTxt->text());
      settings.setValue("VtaSleepAfter",ui->VtaSleepAfter->text());
      settings.setValue("VtaGetSleepTxt",ui->VtaGetSleepTxt->text());
      settings.setValue("TxtEnglishTyping",ui->TxtEnglishTyping->text());
      settings.setValue("TxtHindiDictionary",ui->TxtHindiDictionary->text());
      settings.setValue("TxtHindiTyping",ui->TxtHindiTyping->text());
       settings.setValue("CHChatRecog",QString::number(ui->CHChatRecog->isChecked()));
       settings.setValue("CHRecog",QString::number(ui->CHRecog->isChecked()));
      settings.endGroup();
  }

 void VtaSetting::readSettings()
  {
       QSettings settings("Vta", "Setting");
       settings.beginGroup("VtaSetting");

       if(!settings.value("thisgeometry").toRect().isEmpty() || !settings.value("geometry").toRect().isNull())
       {
         this->setGeometry(settings.value("geometry").toRect());
       }

       Loc.setX(settings.value("VtaLoc_X").toInt());
       Loc.setY(settings.value("VtaLoc_Y").toInt());

       ui->VtaGetUpTxt->setText(settings.value("VtaGetUpTxt").toString());
       ui->VtaSleepAfter->setText(settings.value("VtaSleepAfter").toString());
       ui->VtaGetSleepTxt->setText(settings.value("VtaGetSleepTxt").toString());
       ui->TxtEnglishTyping->setText(settings.value("TxtEnglishTyping").toString());
       ui->TxtHindiTyping->setText(settings.value("TxtHindiTyping").toString());
       ui->TxtHindiDictionary->setText(settings.value("TxtHindiDictionary").toString());
        ui->CHRecog->setChecked(settings.value("CHRecog").toBool());
       ui->CHChatRecog->setChecked(settings.value("CHChatRecog").toBool());

       settings.endGroup();

  }
VtaSetting::~VtaSetting()
{
    writeSettings();
    delete ui;
}
void VtaSetting::WriteVtaGram()
{
      QFile fileg(qApp->applicationDirPath()+"/lib/VtaSRGrammer/VtaGrammer_En/VtaCommand.gram");
      if(!fileg.open(QIODevice::WriteOnly))
      {
         QMessageBox::warning(this,"Error !","Grammer Writing Error !\n"+fileg.errorString()) ;
          return;
      }
      QTextStream in(&fileg);

      QString Str = "#JSGF V1.0;\ngrammar Command;\n";
       in<<Str;

      int j = 1;
      QString str1 = "public <Command"+QString::number(j)+"> = ( ";
      in<<str1;

      bool k  = false;
      for(int i = 0 ;i<VtaVoice.length();i++)
      {

         if(i > 10*j)
         {
             j++;
             in<<" );";
             str1 = "\npublic <Command"+QString::number(j)+"> = ( ";
              k  = false;
             in<<str1;
         }
         if(VtaIsVoice.at(i) == "Ok")
         {
            if(k)
            {
                in<<" | ";
            }

            in<<VtaVoice.at(i);
            k  = true;
         }


      }
       in<<" );";

       QString str2 = "\npublic <CommanCommand> = ( ";

        if(CompareGramStr(ui->VtaGetUpTxt->text()) && CompareGramStr(ui->VtaGetSleepTxt->text()))
        {
            str2.append(ui->VtaGetUpTxt->text()+" | "+ui->VtaGetSleepTxt->text());
            ui->LblSettingOutPut->setText("Setting Save For Next Start");
        }
        else
        {
           ui->LblSettingOutPut->setText("Vta Sleep Or Get up Text Setting Saveing  Faill! ");
        }

    if(!ui->CHRecog->isChecked())
    {
        if(CompareGramStr(ui->TxtEnglishTyping->text()))
        {
            str2.append(" | ");
            str2.append(ui->TxtEnglishTyping->text());
            ui->LblSettingOutPut->setText("Setting Save For Next Start");
        }
        else
        {
           ui->LblSettingOutPut->setText("Vta Hindi Typing Text Setting Saveing  Faill! ");
        }

        if(CompareGramStr(ui->TxtHindiDictionary->text()))
        {
             str2.append(" | ");
            str2.append(ui->TxtHindiDictionary->text());
            ui->LblSettingOutPut->setText("Setting Save For Next Start");
        }
        else
        {
           ui->LblSettingOutPut->setText("Vta  Hindi Dictionary Text Setting Saveing  Faill! ");
        }

        if(CompareGramStr(ui->TxtHindiTyping->text()))
        {
             str2.append(" | ");
            str2.append(ui->TxtHindiTyping->text());
            ui->LblSettingOutPut->setText("Setting Save For Next Start");
        }
        else
        {
           ui->LblSettingOutPut->setText("Vta  Hindi Typing Text Setting Saveing  Faill! ");
        }




    }

        str2.append(" );");
        in<<str2;

        if(!ui->CHChatRecog->isChecked())
        {
            in<<"\n";

                 QFile file1(qApp->applicationDirPath()+"/VtaFiles/ChatVoiceWordList.Vta");
                 if(!file1.open(QFile::ReadOnly))
                 {
                     QMessageBox::critical(this,"error","ChatVoiceWordList.Vta File Opening Faill ! ");
                 }

                 QTextStream inc(&file1);
                 while(!inc.atEnd())
                 {

                     in<<inc.readLine();
                 }

                 ui->LblSettingOutPut->setText("Setting Save For Next Start");
              file1.close();

        }

       fileg.close();
}

void VtaSetting::AddRow()
{
     int row =  ui->VtaVoiceTable->rowCount();
      ui->VtaVoiceTable->insertRow(row);

     QTableWidgetItem *item0 = new QTableWidgetItem;
     item0->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
       ui->VtaVoiceTable->setItem(row, 0, item0);

     QTableWidgetItem *item1 = new QTableWidgetItem;
     item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
      ui->VtaVoiceTable->setItem(row, 1, item1);

      QTableWidgetItem *item2 = new QTableWidgetItem;
      item2->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
       ui->VtaVoiceTable->setItem(row, 2, item2);

       QTableWidgetItem *item3 = new QTableWidgetItem;
       item3->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->VtaVoiceTable->setItem(row, 3, item3);
/*
        QTableWidgetItem *item4 = new QTableWidgetItem;
        item4->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
         ui->VtaVoiceTable->setItem(row, 4, item4);*/


}
void VtaSetting::CreatVtaCommandFile()
{


     QString OutFileName;
     OutFileName = qApp->applicationDirPath()+"/VtaFiles/VtaCommand.Vta";

    QFile GMif_file(OutFileName);

     if(!GMif_file.open(QFile::WriteOnly))
     {
         QMessageBox::critical(this,"GMif Error!","File : \n"+OutFileName+" \nWriting Error ! \n "+GMif_file.errorString());
          return;
     }

     QTextStream GMif_file_Txt(&GMif_file);
     QDomDocument GMif_Creat("GMif_Data");


       QDomElement _Main_Node = GMif_Creat.createElement("command");
       GMif_Creat.appendChild(_Main_Node);


       for(int i=0;i<ui->VtaVoiceTable->rowCount();i++)
       {

          QDomElement Main_Node = GMif_Creat.createElement("command"+QString::number(i));
          _Main_Node.appendChild(Main_Node);

          QDomElement command = GMif_Creat.createElement("VtaVoice");
          Main_Node.appendChild(command);
          QDomText commandData = GMif_Creat.createTextNode(ui->VtaVoiceTable->item(i,1)->text());
          command.appendChild(commandData);

          QDomElement commandTo = GMif_Creat.createElement("CommandTo");
          Main_Node.appendChild(commandTo);
         QDomText commandToData = GMif_Creat.createTextNode(ui->VtaVoiceTable->item(i,0)->text());
         commandTo.appendChild(commandToData);

         QDomElement commandArg = GMif_Creat.createElement("CommandArg");
         Main_Node.appendChild(commandArg);
        QDomText commandArgData = GMif_Creat.createTextNode(ui->VtaVoiceTable->item(i,2)->text());
        commandArg.appendChild(commandArgData);


        QDomElement commandType = GMif_Creat.createElement("CommandType");
        Main_Node.appendChild(commandType);
       QDomText commandTypeData = GMif_Creat.createTextNode(ui->VtaVoiceTable->item(i,3)->text());
       commandType.appendChild(commandTypeData);

       QDomElement chackedStat = GMif_Creat.createElement("ChackedStat");
       Main_Node.appendChild(chackedStat);
      QDomText chackedStatData = GMif_Creat.createTextNode(QString::number(ui->VtaVoiceTable->item(i,0)->checkState()));
      chackedStat.appendChild(chackedStatData);


     }

 GMif_file_Txt<<GMif_Creat;


}
void VtaSetting::ReadVtaCommandFile()
{

    QDomDocument doc("Vta");
    QFile file(qApp->applicationDirPath()+"/VtaFiles/VtaCommand.Vta");
     if (!file.open(QIODevice::ReadOnly))
     {
          QMessageBox::critical(this,"Vta Error!","File :   Opening Error ! \n "+file.errorString());
          return;
     }

     if (!doc.setContent(&file))
     {
         QMessageBox::critical(this,"Vta Reading Error!","File :  Can Reading Error!  \n "+file.errorString());
         file.close();
         return;
     }
     file.close();

 QDomElement  root = doc.documentElement();
 QDomNode Dn = root.firstChild();

  while(!Dn.isNull())
 {
        QDomElement e = Dn.toElement();
        QDomNode dn1 = e.firstChild();

        int r = ui->VtaVoiceTable->rowCount();
        AddRow();

        while(!dn1.isNull())
        {
            QDomElement e1 = dn1.toElement();
            if(!e1.isNull())
            {



              if(e1.nodeName() == "VtaVoice")
              {
                  QDomText Txt = e1.firstChild().toText();
                  ui->VtaVoiceTable->item(r,1)->setText(Txt.data());
                 // qDebug()<<Txt.data();
               }
              else if(e1.nodeName() == "CommandTo")
              {
                  QDomText Txt = e1.firstChild().toText();
                   ui->VtaVoiceTable->item(r,0)->setText(Txt.data() );
                 // qDebug()<<Txt.data() ;
               }
              else if(e1.nodeName() == "CommandArg")
              {
                  QDomText Txt = e1.firstChild().toText();
                  ui->VtaVoiceTable->item(r,2)->setText(Txt.data());

                   QFileInfo fi(qApp->applicationDirPath()+"/VtaImage/"+Txt.data());
                   if(fi.exists())
                  {
                      ui->VtaVoiceTable->item(r,2)->setIcon(QIcon(QPixmap(qApp->applicationDirPath()+"/VtaImage/"+Txt.data()).scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
                  }

              }
              else if(e1.nodeName() == "ChackedStat")
              {
                   QDomText Txt = e1.firstChild().toText();
                  if(Txt.data().toInt() == 0)
                  {
                      ui->VtaVoiceTable->item(r,0)->setCheckState(Qt::Unchecked);
                  }
                  else if(Txt.data().toInt() == 1)
                  {
                      ui->VtaVoiceTable->item(r,0)->setCheckState(Qt::PartiallyChecked);
                  }
                  else if(Txt.data().toInt() == 2)
                  {
                      ui->VtaVoiceTable->item(r,0)->setCheckState(Qt::Checked);
                  }

              }
              else if(e1.nodeName() == "CommandType")
              {
                  QDomText Txt = e1.firstChild().toText();
                  if(Txt.data() == "Ok")
                  {
                      QIcon ic(qApp->applicationDirPath()+"/VtaIcon/VtaMic.ico");
                      ui->VtaVoiceTable->item(r,0)->setIcon(ic);

                  }
                  else
                  {
                     QIcon ic(qApp->applicationDirPath()+"/VtaIcon/VtaDelete.ico");
                      ui->VtaVoiceTable->item(r,0)->setIcon(ic);
                  }

                  ui->VtaVoiceTable->item(r,3)->setText(Txt.data());
                 // qDebug()<<Txt.data();
               }
              else
              {
               // QDomText Bytearr = e.firstChild().toText();
               // ImgByteList.operator <<(QByteArray::fromBase64(Bytearr.toText().data().toAscii()));
              }
            }

            dn1 = dn1.nextSibling();
        }

     Dn = Dn.nextSibling();
 }

}
bool VtaSetting::CompareGramStr(const QString& str)
{
    QStringList sl = str.split(QRegExp("\\s+"),QString::SkipEmptyParts);
    for(int i=0;i<sl.length();i++)
    {
        if(!CompareWord(sl.at(i)))
        {
            QMessageBox::warning(this,"Woraning"," Word : "+sl.at(i)+" Not find in VtaVoice Dectionary ");
            return  false;
        }
    }

    return true;
}

void VtaSetting::on_BtnAdd_clicked()
{

    bool isOk = true;
    if(ui->TxtVtaVoice->text().isEmpty())
    {
        QMessageBox::warning(this,"Enter Voice Command","Enter Voice Command");
        return;
    }
     QStringList sl = ui->TxtVtaVoice->text().split(QRegExp("\\s+"),QString::SkipEmptyParts);
     for(int i=0;i<sl.length();i++)
     {
         if(!CompareWord(sl.at(i)))
         {
             QMessageBox::warning(this,"Woraning"," Word : "+sl.at(i)+" Not find in VtaVoice Dectionary ");
             isOk = false;
         }
     }

   if(ui->CommandType->currentText() == "DoubleClick")
   {
      if(ui->TxtVtaCommand->text().isEmpty())
      {
          QMessageBox::warning(this,"Select File Frist","Select file frist");
          return;
      }
   }


    int r = ui->VtaVoiceTable->rowCount();
 AddRow();
   QIcon ic(qApp->applicationDirPath()+"/VtaIcon/VtaMic.ico");
   QIcon icd(qApp->applicationDirPath()+"/VtaIcon/VtaDelete.ico");

   ui->VtaVoiceTable->item(r,1)->setText( ui->TxtVtaVoice->text());

   if(ui->CommandType->currentText() == "DoubleClick" || ui->CommandType->currentText() == "SingleClick" )
   {
       ui->VtaVoiceTable->item(r,2)->setIcon(QIcon(QPixmap(qApp->applicationDirPath()+"/VtaImage/"+ui->TxtVtaCommand->text()).scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
       ui->VtaVoiceTable->item(r,2)->setText(ui->TxtVtaCommand->text());
   }
   else
   {
       ui->VtaVoiceTable->item(r,2)->setText(ui->TxtVtaCommand->text());

   }

   ui->VtaVoiceTable->item(r,0)->setText( ui->CommandType->currentText());
   ui->VtaVoiceTable->item(r,0)->setCheckState(Qt::Unchecked);


  if(isOk)
  {
      ui->VtaVoiceTable->item(r,3)->setText("Ok");
      ui->VtaVoiceTable->item(r,0)->setIcon(ic);

  }
  else
  {
      ui->VtaVoiceTable->item(r,3)->setText("NotOk");
      ui->VtaVoiceTable->item(r,0)->setIcon(icd);

  }

  CreatVtaCommandFile();
  ReadCommand();
  WriteVtaGram();

}
void VtaSetting::on_BtnSetImage_clicked()
{
   if((ui->CommandType->currentText() == "DoubleClick") || (ui->CommandType->currentText() == "SingleClick"))
    {
      if(ui->TxtVtaCommand->text().isEmpty())
      {
         ui->LblSettingOutPut->setText("Please Enter Image Name........");
         return;
      }
      else
      {
          QString Txt = ui->TxtVtaCommand->text()+".png";
           m_imageCropper = new ImageCropper(Txt);
         // m_imageCropper->resize( 600, 600 );
          m_imageCropper->setProportion(QSize(4,3));

          QScreen *s = QGuiApplication::primaryScreen();
          if(s)
          {  // QPixmap  p = s->grabWindow(QApplication::desktop()->winId());
              m_imageCropper->setImage(QPixmap(s->grabWindow(QApplication::desktop()->winId())));

          }
          else
          {
              return;
          }


          m_imageCropper->setBackgroundColor(Qt::blue );
          m_imageCropper->setCroppingRectBorderColor( Qt::magenta);
          m_imageCropper->show();
          ui->TxtVtaCommand->setText(Txt);

          while(m_imageCropper->isVisible())
          {
              QTest::qWait(200);
              qApp->processEvents();
          }
           on_BtnAdd_clicked();

      }
   }


}
bool VtaSetting::CompareWord(const QString& str)
{
    bool c  = false;
    for(int i=0;i<slist.length();i++)
    {
        QString s = slist.at(i);
        if(QString::compare(str,s,Qt::CaseInsensitive) == 0)
        {
            c = true;
        }
    }

    return c;
}
void VtaSetting::on_VtaVoiceTable_cellDoubleClicked(int row, int column)
{
    if(ui->VtaVoiceTable->item(row,0)->text() == "DoubleClick" || ui->VtaVoiceTable->item(row,0)->text() == "SingleClick")
    {
         QFile F(qApp->applicationDirPath()+"/VtaImage/"+ui->VtaVoiceTable->item(row,2)->text());
         F.open(QIODevice::ReadWrite);
         F.remove();
    }
     ui->VtaVoiceTable->removeRow(row);

     CreatVtaCommandFile();
    ReadCommand();
    WriteVtaGram();

}
void VtaSetting::ReadCommand()
{
    VtaCommandTo.clear();
    VtaVoice.clear();
    VtaArgument.clear();
    VtaIsVoice.clear();
    CheckedStat.clear();

    for(int i = 0;i<ui->VtaVoiceTable->rowCount();i++)
    {
        VtaCommandTo<<ui->VtaVoiceTable->item(i,0)->text();
        VtaVoice<<ui->VtaVoiceTable->item(i,1)->text();
        VtaArgument<<ui->VtaVoiceTable->item(i,2)->text();
        VtaIsVoice<<ui->VtaVoiceTable->item(i,3)->text();
        CheckedStat<<ui->VtaVoiceTable->item(i,0)->checkState();
    }





}
QPoint VtaSetting::GetVtaLoc()
{
   return Loc;
}

void VtaSetting::on_BtnExportCommand_clicked()
{
     QString str =  QFileDialog::getSaveFileName(this,"Export Command");
     QFile::copy(qApp->applicationDirPath()+"/VtaFiles/VtaCommand.Vta",str);
}

void VtaSetting::on_BtnImportCommand_clicked()
{
    QString ImgFile =  QFileDialog::getOpenFileName(this,"Select Image","","All(*.Vta)");
    QFile::copy(ImgFile,qApp->applicationDirPath()+"/VtaFiles/VtaCommand.Vta");
}

void VtaSetting::on_CommandType_currentTextChanged(const QString &arg1)
{
    if(arg1 == "SendKey")
    {
        QStringList KeyList;
        KeyList<<""<<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G"<<"H"<<"I"<<"J"<<"K"<<"L"<<"M"<<"N"<<"O"<<"P"<<"Q"<<"R"<<"S"<<"T"<<"U"<<"V"<<"W"<<"X"<<"Y"<<"Z";

        QStringList sl;
        QFile file(qApp->applicationDirPath()+"/VtaFiles/WindowsKey.Vta");
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,"Error!",qApp->applicationDirPath()+"/VtaFiles/WindowsKey.Vta File Not Find");
        }
        QTextStream t(&file);
        while(!t.atEnd())
        {
           sl<<t.readLine();
        }
        sl.append(KeyList);
        ui->CBKey->addItems(sl);
        KeyList.append(sl);
        ui->CBKeyChar->addItems(KeyList);

        ui->CBKey->show();
        ui->CBKeyChar->show();
        ui->BtnSetImage->hide();
    }
     else
    {
       ui->CBKey->hide();
       ui->CBKeyChar->hide();
       ui->BtnSetImage->hide();

       if((ui->CommandType->currentText() == "DoubleClick") || (ui->CommandType->currentText() == "SingleClick"))
       {
          ui->BtnSetImage->show();
       }
    }

}

QString VtaSetting::GetVtaGetUpStr()
{
     return ui->VtaGetUpTxt->text();
}
QString VtaSetting::GetVtaSleepStr()
{
     return ui->VtaGetSleepTxt->text();
}
QString VtaSetting::GetHindiTypingTxt()
{
     return ui->TxtHindiTyping->text();
}
QString VtaSetting::GetEnglishTypingTxt()
{
     return ui->TxtEnglishTyping->text();
}
QString VtaSetting::GetDictionaryTxt()
{
     return ui->TxtHindiDictionary->text();
}

bool VtaSetting::GetStartChat()
{
     return ui->CHChatRecog->isChecked();
}
quint64 VtaSetting::GetVtaSleepTime()
{
     return ui->VtaSleepAfter->text().toULongLong();
}

void VtaSetting::on_BtnSave_clicked()
{

    WriteVtaGram();
    writeSettings();
}

void VtaSetting::on_VtaVoiceTable_itemClicked(QTableWidgetItem *item)
{
    CreatVtaCommandFile();
    ReadCommand();
}
void VtaSetting::on_CBKey_currentTextChanged(const QString &arg1)
{
    if(ui->CommandType->currentText() == "SendKey")
    {
      QString str = ui->TxtVtaCommand->text();
      ui->TxtVtaCommand->setText(str+arg1+"+");
    }
}

void VtaSetting::on_CBKeyChar_currentTextChanged(const QString &arg1)
{

    if(ui->CommandType->currentText() == "SendKey")
    {
        QString str = ui->TxtVtaCommand->text();
        ui->TxtVtaCommand->setText(str+arg1+";");
    }
}

void VtaSetting::on_CHRecog_clicked()
{
    WriteVtaGram();

}

void VtaSetting::on_CHChatRecog_clicked()
{

    WriteVtaGram();


}
