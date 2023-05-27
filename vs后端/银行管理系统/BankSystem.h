#pragma once
#include<fstream>
#include"friends.h"
#include"Code.h"
#include"AdminAccount.h"
#include"SavingAccount.h"
using namespace std;
class BankSystem//注意：任何不正常的关闭程序都可能导致后端的析构函数未正常调用，这将导致内存的数据丢失！
{
public:
	string solvemomey(string);
	friends friendsys;
	BankSystem();
	~BankSystem();
	bool saveall();
	bool clearAll();
	void change(std::vector<char>&);
	void change2(std::vector<char>&);
	bool registerAccount(bool judge,string name,string password,string id,string phone,
		bool judge2=0 , double rate = 0, string workid = "",  string money = "0", string savingMoney = "0", string email = "");
	//judge代表是否为admin账户，judge2代表是否开启储蓄账户
	//rate代表利率，利率最小为4位小数，大于0，需要验证输入的合法性
	vector<int> login(string id, string password);
	bool deleteUserAccount(int);
	bool deleteAdminAccount(int);
	void save();
	SavingAccount* getUserAccount(int);
	AdminAccount* getAdminAccount(int);
	int transfer(SavingAccount*, string, double);
	//return 0代表账户不存在，1代表转账成功，2代表余额不足
private:
	const std::string AccountFileName="D:\\cppsave\\UserAccount.code";//账户加密文件的存储路径
	const std::string AccountFileName2 = "D:\\cppsave\\AdminAccount.code";
	std::vector<SavingAccount>* SavingAccounts;
	std::vector<AdminAccount>* AdminAccounts;
};

