#include "SavingAccount.h"
#include"stdlib.h"
using namespace std;

bool SavingAccount::getmoney(double x)
{
	if (stold(money) >= static_cast<double>(x))
	{
		money = to_string(stod(money) - static_cast<double>(x));
		return 1;
	}
	return 0;//Ç®²»¹»
}

bool SavingAccount::getSavingMoney(double x)
{
	if (stold(savingMoney) >= static_cast<double>(x))
	{
		savingMoney = to_string(stod(savingMoney) - static_cast<double>(x));
		return 1;
	}
	return 0;
}

bool SavingAccount::savemoney(double x)
{
	money = to_string(stod(money) + static_cast<double>(x));
	return 1;
}

bool SavingAccount::saveSavingMoney(double x)
{
	savingMoney = to_string(stod(savingMoney) + static_cast<double>(x));
	return 1;
}

bool SavingAccount::transfertm(double x)
{
	if (stold(savingMoney) >= static_cast<double>(x))
	{
		money = to_string(stod(money) + static_cast<double>(x));
		savingMoney = to_string(stod(savingMoney) - static_cast<double>(x));
		return 1;
	}
	return 0;
}

bool SavingAccount::transfertsm(double x)
{
	if (stold(money) >= static_cast<double>(x))
	{
		money = to_string(stod(money) - static_cast<double>(x));
		savingMoney = to_string(stod(savingMoney) + static_cast<double>(x));
		return 1;
	}
	return 0;
}

void SavingAccount::update()
{
	long time_now = bktime().timeGet();
	int days= bktime().days(savingTime, time_now);
	savingMoney = to_string(fuc(stod(savingMoney) * ((double)1 + (double)rate / (double)365)*days));
	savingTime= time_now;
}

double SavingAccount::fuc(double x)
{
	int temp = x * (double)100 + 0.5;
	return (double)temp / (double)100;
}

string SavingAccount::fuc2(double x)
{
	return "";
}
