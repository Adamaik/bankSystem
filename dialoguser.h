#ifndef DIALOGUSER_H
#define DIALOGUSER_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public:
    Ui::Dialog *ui;
};

#endif // DIALOGUSER_H
