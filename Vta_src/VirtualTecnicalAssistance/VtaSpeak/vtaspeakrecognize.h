#ifndef VTASPEAKRECOGNIZE_H
#define VTASPEAKRECOGNIZE_H

#include <QtGui>

class VtaSpeakRecognize
{
public:
    VtaSpeakRecognize();

     bool StopRecognize();
     bool StartRecognize();

     QProcess *SpeakRecoProcess;

private :
     QString RLanguage;

};

#endif // VTASPEAKRECOGNIZE_H
