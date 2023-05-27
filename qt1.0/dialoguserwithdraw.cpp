#include "dialoguserwithdraw.h"
#include "ui_dialoguserwithdraw.h"

dialoguserwithdraw::dialoguserwithdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialoguserwithdraw)
{
    ui->setupUi(this);
}

dialoguserwithdraw::~dialoguserwithdraw()
{
    delete ui;
}
