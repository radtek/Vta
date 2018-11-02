#ifndef VTAKEYBOARD_H
#define VTAKEYBOARD_H

#include <QMainWindow>
#include <QtGui>
#include <QCompleter>
#include <QLineEdit>
#include "vtakey.h"
namespace Ui {
class VtaKeyBoard;
}

class VtaKeyBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit VtaKeyBoard(QWidget *parent = 0);
    ~VtaKeyBoard();
private slots:
     void keyPressEvent(QKeyEvent *event);


private:
    Ui::VtaKeyBoard *ui;
   VtaKey *ke;

};

#endif // VTAKEYBOARD_H
