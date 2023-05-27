#include "dialoguserdeposit.h"
#include "ui_dialoguserdeposit.h"

dialoguserdeposit::dialoguserdeposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialoguserdeposit)
{
    ui->setupUi(this);
}

dialoguserdeposit::~dialoguserdeposit()
{
    delete ui;
}
