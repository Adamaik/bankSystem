#pragma once
#include<fstream>
#include"Code.h"
#include"AdminAccount.h"
#include"FlexibleAccount.h"
#include"SavingAccount.h"
class BankSystem
{
public:
	BankSystem();
	bool saveAdd();//重写
	bool clearAll();
	bool change(vector<char>);
private:
	const std::string AccountFileName="Account.code";//账户文件的存储路径
	std::vector<FlexibleAccount> FlexibleAccounts;
	std::vector<SavingAccount> SavingAccounts;
	std::vector<AdminAccount> AdminAccounts;
};

