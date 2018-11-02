#include "windowsfuncations.h"
#include <QApplication>
#include <QDesktopWidget>
#include "opencvfun.h"

WindowsFuncations::WindowsFuncations()
{

}
void WindowsFuncations::SingleClick(int x,int y)
{

        const double XSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CXSCREEN) - 1);
        const double YSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CYSCREEN) - 1);

        POINT cursorPos;
        GetCursorPos(&cursorPos);

        double nx = x * XSCALEFACTOR;
        double ny = y * YSCALEFACTOR;

        INPUT Input={0};
        Input.type = INPUT_MOUSE;

        Input.mi.dx = (LONG)nx;
        Input.mi.dy = (LONG)ny;

        Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;

        SendInput(1,&Input,sizeof(INPUT));


}
void WindowsFuncations::DoubleClick(int x,int y)
{

        const double XSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CXSCREEN) - 1);
        const double YSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CYSCREEN) - 1);

        POINT cursorPos;
        GetCursorPos(&cursorPos);

        double cx = cursorPos.x * XSCALEFACTOR;
        double cy = cursorPos.y * YSCALEFACTOR;

        double nx = x * XSCALEFACTOR;
        double ny = y * YSCALEFACTOR;

        INPUT Input={0};
        Input.type = INPUT_MOUSE;

        Input.mi.dx = (LONG)nx;
        Input.mi.dy = (LONG)ny;

        Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;

        SendInput(1,&Input,sizeof(INPUT));
        SendInput(1,&Input,sizeof(INPUT));

        Input.mi.dx = (LONG)cx;
        Input.mi.dy = (LONG)cy;

        Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

        SendInput(1,&Input,sizeof(INPUT));

}
void WindowsFuncations::SendSingleKey(unsigned short key)
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

                ip.ki.wVk = key;
                ip.ki.dwFlags = 0; // 0 for key press
                SendInput(1, &ip, sizeof(INPUT));

                ip.ki.wVk = key;
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));


                Sleep(10);
}

void WindowsFuncations::SendKey(unsigned short key,unsigned short and_key)
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "Ctrl" key
                ip.ki.wVk = key;
                ip.ki.dwFlags = 0; // 0 for key press
                SendInput(1, &ip, sizeof(INPUT));

                   ip.ki.wVk = and_key;
                ip.ki.dwFlags = 0; // 0 for key press
                SendInput(1, &ip, sizeof(INPUT));

               ip.ki.wVk = and_key;
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));

   // Release the "Ctrl" key
                ip.ki.wVk = key;
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));
    Sleep(1000);
}

QPoint WindowsFuncations::CaptureActiveWindow()
{

    LONG Vta_X,Vta_Y,Vta_H,Vta_W;
    QPoint po;
    RECT r = {0};

    HWND w = GetForegroundWindow();

      GetWindowRect(w,&r);

      Vta_X = r.left;
      Vta_Y = r.top;
      Vta_H = r.bottom;
      Vta_W = r.right;

          QScreen *s = QGuiApplication::primaryScreen();
          if(s)
          {

                 QPixmap  p = s->grabWindow(QApplication::desktop()->winId(),Vta_X,Vta_Y,Vta_W-Vta_X,Vta_H-Vta_Y);
                 p.save(qApp->applicationDirPath()+"/VtaFiles/DesktopActive.png");
          }

          po.setX(Vta_X);
          po.setY(Vta_Y);
       return po;

}

int WindowsFuncations::SendText()
{
  /*
    SetForegroundWindow(AcWindowId);
     // Create a generic keyboard event structure
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;



               // Press the "Ctrl" key
                ip.ki.wVk = VK_CONTROL;
                ip.ki.dwFlags = 0; // 0 for key press
                SendInput(1, &ip, sizeof(INPUT));

                // Press the "V" key
                ip.ki.wVk = 'V';
                ip.ki.dwFlags = 0; // 0 for key press
                SendInput(1, &ip, sizeof(INPUT));

                // Release the "V" key
                ip.ki.wVk = 'V';
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));

                // Release the "Ctrl" key
                ip.ki.wVk = VK_CONTROL;
                ip.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &ip, sizeof(INPUT));

      Sleep(50);  */

}
