#include "getactivewindow.h"
#include <QtTest/QTest>
GetActiveWindowT::GetActiveWindowT(QString s) : name(s)
{

}
void GetActiveWindowT::run()
{
    char ti[256];

    while(1)
   {
       if(GetForegroundWindow() != VtaWindowId)
       {
            AcWindowId    = GetForegroundWindow();

       }
      QTest::qWait(2000);
   }

}
