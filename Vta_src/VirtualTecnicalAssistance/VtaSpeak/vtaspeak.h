#ifndef VTASPEAK_H
#define VTASPEAK_H

#include <QtGui>

class VtaSpeak
{
public:
    VtaSpeak();

    void StopSpeakProcess();
    void StartSpeak(const QString& str);
    static void StartSpeakV(const QString &str);

    QProcess *Process;

};

#endif // VTASPEAK_H
