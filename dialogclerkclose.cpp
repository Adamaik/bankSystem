#include "dialogclerkclose.h"
#include "ui_dialogclerkclose.h"

dialogclerkclose::dialogclerkclose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogclerkclose)
{
    ui->setupUi(this);
}

dialogclerkclose::~dialogclerkclose()
{
    delete ui;
}
