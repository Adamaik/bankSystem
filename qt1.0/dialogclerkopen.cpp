#include "dialogclerkopen.h"
#include "ui_dialogclerkopen.h"

dialogclerkopen::dialogclerkopen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogclerkopen)
{
    ui->setupUi(this);
}

dialogclerkopen::~dialogclerkopen()
{
    delete ui;
}
