
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include<string>
#include "dialoguser.h"
#include "dialogclerk.h"
#include "ui_dialoguser.h"
#include "ui_dialoguserwithdraw.h"
#include "ui_dialogusertransfer.h"
#include "ui_dialoguserdeposit.h"
#include "ui_dialoguseradd.h"
#include "ui_dialogclerk.h"
#include "ui_dialogclerkopen.h"
#include "ui_dialogclerkclose.h"
#include "dialoguserdeposit.h"
#include "dialoguserwithdraw.h"
#include "dialoguserwithdraw.h"
#include "dialogusertransfer.h"
#include "dialoguseradd.h"
#include "dialogclerkopen.h"
#include "dialogclerkclose.h"
#include "BankSystem.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   void AmySignal();
private:
    Ui::MainWindow *ui;
    Dialog diauser;
    dialogclerk diaclerk;
    dialogclerkopen diaclerk_open;
    dialogusertransfer diauser_transfer;
    dialoguserwithdraw diauser_withdraw;
    dialoguserdeposit  diauser_deposit;
    dialogclerkclose diaclerk_close;
    dialoguseradd diauser_add;
    BankSystem banksystem;
    vector<int>temp;
    QString sid;
    QString spassword;
    QString s_name;
    QString s_id;
    QString s_phone;
    string sidtemp;
    string spasswordtemp;
    SavingAccount* savingaccount;
    AdminAccount* adminaccount;
};

#endif // MAINWINDOW_H
