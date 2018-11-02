#include "vtaspeakrecognize.h"

VtaSpeakRecognize::VtaSpeakRecognize()
{
   SpeakRecoProcess = new QProcess();
   RLanguage = "En";
}
bool VtaSpeakRecognize::StartRecognize()
{
    if(SpeakRecoProcess->isOpen())
        SpeakRecoProcess->close();

    SpeakRecoProcess->start("VtaSR.exe",QStringList()<<"-l"<<RLanguage<<"-g"<<"VtaCommand");

    SpeakRecoProcess->waitForStarted();

    if(SpeakRecoProcess->isReadable())
         return true;
    else
        return false;
}
bool VtaSpeakRecognize::StopRecognize()
{
    if(SpeakRecoProcess->isOpen())
        SpeakRecoProcess->close();

    if(SpeakRecoProcess->isReadable())
         return false;
    else
        return true;
}
