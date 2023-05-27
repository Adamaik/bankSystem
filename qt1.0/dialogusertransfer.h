#ifndef DIALOGUSERTRANSFER_H
#define DIALOGUSERTRANSFER_H

#include <QDialog>

namespace Ui {
class dialogusertransfer;
}

class dialogusertransfer : public QDialog
{
    Q_OBJECT

public:
    explicit dialogusertransfer(QWidget *parent = nullptr);
    ~dialogusertransfer();

public:
    Ui::dialogusertransfer *ui;
};

#endif // DIALOGUSERTRANSFER_H
