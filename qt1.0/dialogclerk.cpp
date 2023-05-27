#include "dialogclerk.h"
#include "ui_dialogclerk.h"

dialogclerk::dialogclerk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogclerk)
{
    ui->setupUi(this);
}

dialogclerk::~dialogclerk()
{
    delete ui;
}
