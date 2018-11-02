#include "vtaspeak.h"

VtaSpeak::VtaSpeak()
{
   Process = new QProcess();
}
void VtaSpeak::StopSpeakProcess()
{
     Process->close();
}
void VtaSpeak::StartSpeak(const QString& str)
{
    if(Process->isReadable())
        Process->close();

      Process->start(qApp->applicationDirPath()+"/tts.exe",QStringList()<<str);
}
void VtaSpeak::StartSpeakV(const QString &str)
{
    QProcess *P1 = new QProcess();
    P1->start(qApp->applicationDirPath()+"/tts.exe",QStringList()<<str);
}
