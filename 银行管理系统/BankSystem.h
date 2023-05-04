#pragma once
#include<fstream>
#include"Code.h"
class BankSystem
{
public:
	BankSystem();
	void saveAdd();
	void clearAll();
	void Register();
private:
	const std::string AccountFileName="Account.code";//账户文件的存储路径
	std::vector<char> AllAccount;  //存储所有账户的信息
	std::vector<char> AddAccount;
};

