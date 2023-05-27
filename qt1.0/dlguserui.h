#ifndef DLGUSER_H
#define DLGUSER_H

#include <QDialog>

namespace Ui {
class Dialoguser;
}

class Dialoguser : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoguser(QWidget *parent = nullptr);
    ~Dialoguser();

public:
    Ui::Dialoguser *ui;
};

#endif // DLGUSER_H
