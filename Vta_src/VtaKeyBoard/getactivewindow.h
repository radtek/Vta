#ifndef GETACTIVEWINDOWT_H
#define GETACTIVEWINDOWT_H

#include <QtGui>
#include <QThread>
#include "globlevar.h"
#include <windows.h>

class GetActiveWindowT :public QThread
{
public:
    GetActiveWindowT(QString s);
     void run();
private :
    QString name;

};

#endif // GETACTIVEWINDOW_H
