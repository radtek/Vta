#include "vtakeyboard.h"
#include "ui_vtakeyboard.h"

VtaKeyBoard::VtaKeyBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VtaKeyBoard)
{
    ui->setupUi(this);

    ke = new VtaKey();

}

VtaKeyBoard::~VtaKeyBoard()
{
    delete ui;
}

void VtaKeyBoard::keyPressEvent(QKeyEvent *event)
{
    //ui->InputText->setText(ke->PopedString);
}
