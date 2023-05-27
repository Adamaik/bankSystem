#include "dialoguseradd.h"
#include "ui_dialoguseradd.h"

dialoguseradd::dialoguseradd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialoguseradd)
{
    ui->setupUi(this);
}

dialoguseradd::~dialoguseradd()
{
    delete ui;
}
