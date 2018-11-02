#ifndef VTATASK_H
#define VTATASK_H

#include<QtGui>

class VTATask
{
public:
    VTATask();
  //  bool GetTask(QString Str);
    QString SearchTask(QString str);
    QStringList GetCaptureList(int from ,int to);
    QStringList GetCaptureList();
    QStringList GetCaptureListSpilt(int from ,int to);
    QStringList GetCaptureListSpilt();

    QString ErrorStr;

    QStringList CaptureFiles,RExpList;

    typedef struct
    {
        QStringList Sentance;
        QString Task;
    }Tasks;
    QList<Tasks> TaskName;

    int isMatch;
};

#endif // VTATASK_H
