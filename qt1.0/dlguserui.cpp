#include "dlguserui.h"
#include "ui_dlguser.h"

Dialoguser::Dialoguser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoguser)
{
    ui->setupUi(this);
}

Dialoguser::~Dialoguser()
{
    delete ui;
}
