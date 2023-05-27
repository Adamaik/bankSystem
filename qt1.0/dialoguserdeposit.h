#ifndef DIALOGUSERDEPOSIT_H
#define DIALOGUSERDEPOSIT_H

#include <QDialog>

namespace Ui {
class dialoguserdeposit;
}

class dialoguserdeposit : public QDialog
{
    Q_OBJECT

public:
    explicit dialoguserdeposit(QWidget *parent = nullptr);
    ~dialoguserdeposit();

public:
    Ui::dialoguserdeposit *ui;
};

#endif // DIALOGUSERDEPOSIT_H
