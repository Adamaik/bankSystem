#ifndef DIALOGCLERKCLOSE_H
#define DIALOGCLERKCLOSE_H

#include <QDialog>

namespace Ui {
class dialogclerkclose;
}

class dialogclerkclose : public QDialog
{
    Q_OBJECT

public:
    explicit dialogclerkclose(QWidget *parent = nullptr);
    ~dialogclerkclose();

public:
    Ui::dialogclerkclose *ui;
};

#endif // DIALOGCLERKCLOSE_H
