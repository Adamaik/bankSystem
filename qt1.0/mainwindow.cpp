#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMainWindow>
#include<QDialog>
#include<QMessageBox>
#include<QPushButton>
#include<QListWidget>
#include<QString>
#include<qdebug>
#include<string>
#include<QFont>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(765,550);
    //banksystem.registerAccount(1,"徐硕洋","1","2306808419","18888888888");
    setWindowTitle("智慧银行管理系统");
    connect(ui->actionchk,&QAction::triggered,[=](){QMessageBox::information(this,"版本信息","设计者：徐硕洋 王梓\n版本号：2.2.5");});
    QFont FontWord( "Microsoft YaHei", 12, 500);//第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    QFont FontTitle( "Microsoft YaHei", 35, 100000);
    ui->label->setFont(FontWord);
    ui->label_2->setFont(FontWord);
    ui->label_4->setFont(FontTitle);
    connect(ui->pushButtonin,&QPushButton::clicked,[=](){
       sid = ui->lineEdit->displayText().toUtf8().data();
       spassword=ui->lineEdit_2->displayText().toUtf8().data();
       sidtemp=sid.toStdString();
       spasswordtemp=spassword.toStdString();
       qDebug()<<sidtemp;
       temp=banksystem.login(sidtemp,spasswordtemp);
       if ((!temp[0])&&temp[3])
       {
           QMessageBox::critical(this,"提示","密码错误");
       }
       else if(!temp[3])
       {
           QMessageBox::critical(this,"提示","账户不存在");
       }
    if (temp[0]&&!temp[1])//用户界面
    {
    diauser.setWindowTitle("欢迎进入用户使用界面");
    diauser.resize(720,380);
    savingaccount=banksystem.getUserAccount(temp[2]);
    s_name=QString::fromStdString(savingaccount->name);
    s_id=QString::fromStdString(savingaccount->id);
    s_phone=QString::fromStdString(savingaccount->phone);
    diauser.ui->label_name->setText(s_name);
    QFont FontWelcome( "Microsoft YaHei", 30, 1000);
    QFont FontWord( "Microsoft YaHei", 10, 500);
    diauser.ui->label->setFont(FontWelcome);
    diauser.ui->label_name->setFont(FontWelcome);
    diauser.ui->label_6->setFont(FontWord);
    diauser.ui->label_2->setFont(FontWord);
    diauser.exec();
    }
    if (temp[0]&&temp[1])//职员界面
    {
    diaclerk.setWindowTitle("欢迎进入员工界面");
    diaclerk.resize(720,370);
    adminaccount=banksystem.getAdminAccount(temp[2]);
    s_name=QString::fromStdString(adminaccount->name);
    s_id=QString::fromStdString(adminaccount->id);
    s_phone=QString::fromStdString(adminaccount->phone);
    diaclerk.ui->label_name_2->setText(s_name);
    QFont Font( "Microsoft YaHei", 30, 1000);
    diaclerk.ui->label_2->setFont(Font);
    diaclerk.ui->label_name_2->setFont(Font);
    diaclerk.exec();
    }
});
    connect(diauser.ui->pushfindnumber,&QPushButton::clicked,[=](){QMessageBox::information(this,"手机号码",s_phone);});
    connect(diauser.ui->pushfindpay,&QPushButton::clicked,[=](){
        QString spay1=QString::fromStdString(banksystem.solvemomey(savingaccount->money));
        QMessageBox::information(this,"活期账户余额",spay1);
    });
    connect(diauser.ui->pushButton,&QPushButton::clicked,[=](){
        QString spay2=QString::fromStdString(banksystem.solvemomey(savingaccount->savingMoney));
        QMessageBox::information(this,"储蓄账户余额",spay2);
    });
    connect(diauser.ui->pushButton_4,&QPushButton::clicked,[=](){
        diauser_withdraw.setWindowTitle("欢迎进入取款界面");
        diauser_withdraw.resize(700,265);
        QFont FontTitle( "Microsoft YaHei", 28, 10000);
        QFont FontWord( "Microsoft YaHei", 10, 600);
        diauser_withdraw.ui->label_2->setFont(FontWord);
        diauser_withdraw.ui->label_7->setFont(FontTitle);
        diauser_withdraw.exec();
    });
    connect(diauser_withdraw.ui->pushButton,&QPushButton::clicked,[=](){
        QString spay = diauser_withdraw.ui->lineEdit->displayText().toUtf8().data();
        QString spassowrd = diauser_withdraw.ui->lineEdit_2->displayText().toUtf8().data();
        bool bx=diauser_withdraw.ui->comboBox->currentIndex();
        string sis=diauser_withdraw.ui->lineEdit_2->displayText().toUtf8().data();
        vector<int>temp1=banksystem.login(sidtemp,sis);
            if (temp1[0])
            {
                if (!bx)
                {
                    string spayx = spay.toStdString();
                    if(savingaccount->getmoney(stod(spayx)))
                    {
                        QMessageBox::information(this,"提示","取款成功");
                        diauser_withdraw.close();
                    }
                    else
                    {
                        QMessageBox::critical(this,"提示","余额不足");
                        diauser_withdraw.exec();
                    }
                }
                if (bx)//储蓄取款
                {
                    string spayy = spay.toStdString();
                    if(savingaccount->getSavingMoney(stod(spayy)))
                    {
                        QMessageBox::information(this,"提示","取款成功");
                        diauser_withdraw.close();
                    }
                    else
                    {
                        QMessageBox::critical(this,"提示","余额不足");
                        diauser_withdraw.exec();
                    }
                }
            }
            if (!temp1[0])//spassword密码错误
            {
                QMessageBox::critical(this,"提示","密码错误");
                diauser_withdraw.exec();
            }
    });
    connect(diauser.ui->pushButton_3,&QPushButton::clicked,[=](){
        diauser_transfer.setWindowTitle("欢迎进入转账界面");
        diauser_transfer.resize(700,265);
        QFont FontTitle( "Microsoft YaHei", 28, 10000);
        QFont FontWord( "Microsoft YaHei", 10, 600);
        diauser_transfer.ui->label->setFont(FontWord);
        diauser_transfer.ui->label_2->setFont(FontWord);
        diauser_transfer.ui->label_3->setFont(FontWord);
        diauser_transfer.ui->label_8->setFont(FontTitle);
        diauser_transfer.exec();
    });
    connect(diauser_transfer.ui->pushButton,&QPushButton::clicked,[=](){
        string spay = diauser_transfer.ui->lineEdit_2->displayText().toUtf8().data();//输入要转账多少钱
        string sid2 = diauser_transfer.ui->lineEdit->displayText().toUtf8().data();//输入要转给哪个账户
        string spassword1=diauser_transfer.ui->lineEdit_3->displayText().toUtf8().data();
        int bx=diauser_transfer.ui->comboBox->currentIndex();//0是活期转储蓄，1是储蓄转活期，2是给他人
        vector<int>temp2=banksystem.login(sidtemp,spassword1);
        vector<int>temp0=banksystem.login(sid2,"");
        if (!(banksystem.friendsys.isfriend(temp0[2],temp2[2])))
        {
           QMessageBox::information(this,"提示","该账户非好友账户");
        }
        if(temp2[0])
        {
            switch(bx)
            {
            case 0:if(savingaccount->transfertsm(stod(spay)))
                {
                    QMessageBox::information(this,"提示","转账成功");
                    diauser_transfer.close();
                }
                else
                {
                    QMessageBox::information(this,"提示","余额不足");
                    diauser_transfer.exec();
                }break;
            case 1:if(savingaccount->transfertm(stod(spay)))
                {
                    QMessageBox::information(this,"提示","转账成功");
                    diauser_transfer.close();
                }
                else
                {
                    QMessageBox::information(this,"提示","余额不足");
                    diauser_transfer.exec();
                }break;
            case 2:
                int temporary=banksystem.transfer(savingaccount,sid2,stod(spay));
                if(temporary==1)
                {
                    QMessageBox::information(this,"提示","转账成功");
                    diauser_transfer.close();
                }
                else if(temporary==0)
                {
                    QMessageBox::information(this,"提示","目标账户不存在");
                    diauser_transfer.exec();
                }
                else
                {
                    QMessageBox::information(this,"提示","余额不足");
                    diauser_transfer.exec();
                }
            }
        }
        else
        {
            QMessageBox::information(this,"提示","密码错误");
            diauser_transfer.exec();
        }
    });
    connect(diauser.ui->pushButton_2,&QPushButton::clicked,[=](){
        diauser_deposit.setWindowTitle("欢迎进入存款界面");
        diauser_deposit.resize(700,265);
        QFont FontWord( "Microsoft YaHei", 10, 600);
        QFont FontTitle( "Microsoft YaHei", 28, 10000);
        diauser_deposit.ui->label_4->setFont(FontTitle);
        diauser_deposit.ui->label_2->setFont(FontWord);
        diauser_deposit.ui->label_3->setFont(FontWord);
        diauser_deposit.exec();
    });
    connect(diauser_deposit.ui->pushButton,&QPushButton::clicked,[=](){
        string spay = diauser_deposit.ui->lineEdit_2->displayText().toUtf8().data();
        string sis=diauser_deposit.ui->lineEdit_3->displayText().toUtf8().data();
        bool bx=diauser_deposit.ui->comboBox->currentIndex();
        vector<int>temp2=banksystem.login(sidtemp,sis);
        if (temp2[0]&&temp2[3])
        {
            if (!bx)
            {
                savingaccount->savemoney(stod(spay));
                QMessageBox::information(this,"提示","存款成功");
                diauser_deposit.close();
            }

            if (bx)
            {
                savingaccount->saveSavingMoney(stod(spay));
                QMessageBox::information(this,"提示","存款成功");
                diauser_deposit.close();
            }
        }
        if (!temp2[0])//spassword密码错误
        {
            QMessageBox::critical(this,"提示","密码错误");
            diauser_deposit.exec();
        }
    });
    connect(diauser.ui->pushButton_5,&QPushButton::clicked,[=](){

        diauser_add.setWindowTitle("欢迎进入好友界面");
        diauser_add.resize(700,265);
        QFont FontTitle( "Microsoft YaHei", 28, 10000);
        QFont FontWord( "Microsoft YaHei", 10, 600);
        diauser_add.ui->label_4->setFont(FontTitle);
        diauser_add.ui->label_2->setFont(FontWord);
        diauser_add.ui->label->setFont(FontWord);
        diauser_add.exec();
    });
    connect(diauser_add.ui->pushButton,&QPushButton::clicked,[=](){
        string sidxx = diauser_add.ui->lineEdit->displayText().toUtf8().data();//输入要转给哪个账户
        string spassowordxx = diauser_add.ui->lineEdit_2->displayText().toUtf8().data();//输入的密码
        vector<int>temp1=banksystem.login(sidtemp,spassowordxx);
        vector<int>temp2=banksystem.login(sidxx,"");

        if (temp1[0])//spassword密码正确
        {

            banksystem.friendsys.set(temp2[2],temp1[2]);
            QMessageBox::information(this,"提示","添加成功");
        }
        if (!temp1[0])//spassword密码错误
        {
            QMessageBox::critical(this,"提示","密码错误");
        }
    });
    connect(diaclerk.ui->pushfindnumber,&QPushButton::clicked,[=](){QMessageBox::information(this,"手机号码",s_phone);});
    connect(diaclerk.ui->pushButton_4,&QPushButton::clicked,[=](){
    diaclerk_open.setWindowTitle("欢迎进入开户界面");
        diaclerk_open.resize(580,500);
        QFont FontTitle( "Microsoft YaHei", 28, 10000);
        QFont FontWord( "Microsoft YaHei", 10, 600);
        diaclerk_open.ui->label_8->setFont(FontTitle);
        diaclerk_open.ui->label_6->setFont(FontWord);
        diaclerk_open.ui->label_7->setFont(FontWord);
        diaclerk_open.ui->label_2->setFont(FontWord);
        diaclerk_open.ui->label_5->setFont(FontWord);
        diaclerk_open.ui->label->setFont(FontWord);
        diaclerk_open.ui->label_3->setFont(FontWord);
        diaclerk_open.ui->label_4->setFont(FontWord);
        diaclerk_open.exec();
    });
    connect(diaclerk_open.ui->pushButton,&QPushButton::clicked,[=](){
        bool sx=diaclerk_open.ui->comboBox->currentIndex();
        bool sisacc=diaclerk_open.ui->comboBox_2->currentIndex();
        string sid=diaclerk_open.ui->lineEdit_2->displayText().toUtf8().data();
        string sname=diaclerk_open.ui->lineEdit_5->displayText().toUtf8().data();
        string spassword=diaclerk_open.ui->lineEdit_3->displayText().toUtf8().data();
        string spasswordx=diaclerk_open.ui->lineEdit_4->displayText().toUtf8().data();
        string sphone=diaclerk_open.ui->lineEdit->displayText().toUtf8().data();
        string srate=diaclerk_open.ui->lineEdit_6->displayText().toUtf8().data();
        vector<int>temp=banksystem.login(sid,"");
        bool bphone=true;
        bool brepeat=temp[3];
        bool bpassword=true;
        for (int i=0;i<sphone.size();i++)
        {
          bphone=!(sphone[i]<'0'||sphone[i]>'9');
          bphone=!(sphone.size()!=11);
        }
        bpassword=spassword==spasswordx;
        if (!bphone) QMessageBox::critical(this,"提示","手机格式错误");
        if (!bpassword) QMessageBox::critical(this,"提示","两次密码不一致");
        if (brepeat)   QMessageBox::critical(this,"提示","该账户已被注册");
        if (bpassword&&bphone&&!brepeat)
        {
        banksystem.registerAccount(sx,sname,spassword,sid,sphone,sisacc,stod(srate));

        QMessageBox::information(this,"提示","开户成功");
        banksystem.friendsys.registers();
        diaclerk_open.ui->lineEdit_2->clear();
        diaclerk_open.ui->lineEdit_5->clear();
        diaclerk_open.ui->lineEdit->clear();
        diaclerk_open.ui->lineEdit_3->clear();
        diaclerk_open.ui->lineEdit_4->clear();
        bool bphone=true;
        bool bpassword=true;
        }
    });
    connect(diaclerk.ui->pushButton_3,&QPushButton::clicked,[=](){
        diaclerk_close.setWindowTitle("欢迎进入销户界面");
        diaclerk_close.resize(380,300);
        QFont FontTitle( "Microsoft YaHei", 28, 10000);
        QFont FontWord( "Microsoft YaHei", 10, 600);
        diaclerk_close.ui->label_2->setFont(FontWord);
        diaclerk_close.ui->label_3->setFont(FontWord);
        diaclerk_close.exec();
    });
    connect(diaclerk_close.ui->pushButton,&QPushButton::clicked,[=](){
        string sid=diaclerk_close.ui->lineEdit_2->displayText().toUtf8().data();
        string spassword=diaclerk_close.ui->lineEdit_3->displayText().toUtf8().data();
        vector<int>deleteaccount=banksystem.login(sid,spassword);
        string sidnow = ui->lineEdit->displayText().toUtf8().data();
        if (deleteaccount[3])
        {
            if (deleteaccount[0])
            {
                if (deleteaccount[1])
                {
                    banksystem.deleteAdminAccount(deleteaccount[2]);
                }
                else
                {
                    banksystem.deleteUserAccount(deleteaccount[2]);
                }
                QMessageBox::information(this,"提示","销户成功");
                if (sid==sidnow)
                {
                   diauser.close();
                }
                else
                {
                   diaclerk_close.close();
                }
            }
            else
            {
                QMessageBox::critical(this,"提示","密码错误");
                diaclerk_close.exec();
            }
        }
        if (!deleteaccount[3])//没有这个人
        {
            QMessageBox::critical(this,"提示","找不到该用户");
            diaclerk_close.exec();
        }
    });
    connect(ui->pushButtonexit,&QPushButton::clicked,[=](){close();});
}
MainWindow::~MainWindow()
{
    delete ui;
}


