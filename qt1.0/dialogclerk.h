#ifndef DIALOGCLERK_H
#define DIALOGCLERK_H

#include <QDialog>

namespace Ui {
class dialogclerk;
}

class dialogclerk : public QDialog
{
    Q_OBJECT

public:
    explicit dialogclerk(QWidget *parent = nullptr);
    ~dialogclerk();

public:
    Ui::dialogclerk *ui;
};

#endif // DIALOGCLERK_H
