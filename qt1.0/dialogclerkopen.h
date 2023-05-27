#ifndef DIALOGCLERKOPEN_H
#define DIALOGCLERKOPEN_H

#include <QDialog>

namespace Ui {
class dialogclerkopen;
}

class dialogclerkopen : public QDialog
{
    Q_OBJECT

public:
    explicit dialogclerkopen(QWidget *parent = nullptr);
    ~dialogclerkopen();

public:
    Ui::dialogclerkopen *ui;
};

#endif // DIALOGCLERKOPEN_H
