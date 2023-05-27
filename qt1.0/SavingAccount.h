#pragma once
#include"users.h"
#include"bktime.h"
class SavingAccount:public User
{
private:
	double fuc(double);//四舍五入保留两位小数
	std::string fuc2(double);//转string函数
public:
	std::string money;//活期账户
	std::string savingMoney;//定期账户
	long savingTime;//定期账户时间戳
	bool judge;//判断是否有定期账户
	double rate;//利率
	bool getmoney(double);
	bool getSavingMoney(double);
	bool savemoney(double);
	bool saveSavingMoney(double);
	bool transfertm(double);//return 0表示钱不够
	bool transfertsm(double);
	void update();
};

