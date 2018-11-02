#include "vtakeyboard.h"
#include <QApplication>
#include "getactivewindow.h"
#include "vtakey.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VtaKey  w;
    w.show();
    VtaWindowId = GetForegroundWindow();

    return a.exec();
}
