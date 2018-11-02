#ifndef WINDOWSFUNCATIONS_H
#define WINDOWSFUNCATIONS_H

#include <windows.h>
#include <QtGui>

class WindowsFuncations
{
public:
    WindowsFuncations();
   static QPoint CaptureActiveWindow();

  static void  DoubleClick(int x,int y);
  static void SingleClick(int x,int y);
  static void  SendKey(unsigned short key,unsigned short and_key);
  static void SendSingleKey(unsigned short key);
  static int   SendText();

private :

};

#endif // WINDOWSFUNCATIONS_H
