#include "dialogusertransfer.h"
#include "ui_dialogusertransfer.h"

dialogusertransfer::dialogusertransfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogusertransfer)
{
    ui->setupUi(this);
}

dialogusertransfer::~dialogusertransfer()
{
    delete ui;
}
