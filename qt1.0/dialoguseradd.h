#ifndef DIALOGUSERADD_H
#define DIALOGUSERADD_H

#include <QDialog>

namespace Ui {
class dialoguseradd;
}

class dialoguseradd : public QDialog
{
    Q_OBJECT

public:
    explicit dialoguseradd(QWidget *parent = nullptr);
    ~dialoguseradd();

public:
    Ui::dialoguseradd *ui;
};

#endif // DIALOGUSERADD_H
