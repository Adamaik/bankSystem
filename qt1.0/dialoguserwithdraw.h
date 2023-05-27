#ifndef DIALOGUSERWITHDRAW_H
#define DIALOGUSERWITHDRAW_H

#include <QDialog>

namespace Ui {
class dialoguserwithdraw;
}

class dialoguserwithdraw : public QDialog
{
    Q_OBJECT

public:
    explicit dialoguserwithdraw(QWidget *parent = nullptr);
    ~dialoguserwithdraw();

public:
    Ui::dialoguserwithdraw *ui;
};

#endif // DIALOGUSERWITHDRAW_H
