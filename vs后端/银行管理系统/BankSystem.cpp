#include "BankSystem.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;

BankSystem::~BankSystem()
{
	clearAll();
	saveall();
	delete SavingAccounts;
	delete AdminAccounts;
}

BankSystem::BankSystem()
{
	SavingAccounts = new vector<SavingAccount>;
	AdminAccounts= new vector<AdminAccount>;
	fstream AccountFile, AccountFile2;
	AccountFile.open(AccountFileName, ios::in | ios::out | ios::binary);
	if (!AccountFile.is_open())
	{
		cout << "UserAccount.code open failed!(line 12)" << endl;
		exit(0);
		AccountFile.close();
	}
	vector<bool>* temp=new vector<bool>;   //存储二进制数据
	char m;    //temperary
	bool n = 1;
	while (AccountFile.get(m))
	{
		n = 0;
		temp->push_back(m - '0');
	}
	std::vector<char>* AllAccount=new vector<char>;
	if (n)
	{
		goto Lable;
	}
	*AllAccount = Code().decode(*temp, 0);
	change(*AllAccount);
Lable:
	AccountFile.close();
	AccountFile2.open(AccountFileName2, ios::in | ios::out | ios::binary);
	if (!AccountFile2.is_open())
	{
		cout << "AdminAccount.code open failed!(line36)" << endl;
		exit(0);
		AccountFile2.close();
	}
	temp->clear();
	AllAccount->clear();
	n = 1;
	while (AccountFile2.get(m))
	{
		n = 0;
		temp->push_back(m - '0');
	}
	if (n)
	{
		AccountFile2.close();
		return;
	}
	*AllAccount = Code().decode(*temp, 1);
	AccountFile2.close();
	change2(*AllAccount);
	delete temp;
	delete AllAccount;
}

string BankSystem::solvemomey(string input)
{
	for (int i = 0; i < 4; ++i)
	{
		input.pop_back();
	}
	return input;
}

bool BankSystem::saveall()
{
	std::vector<char>* AllAccount=new vector<char>;
	for (auto i : *SavingAccounts)
	{
		string temp1;
		string rate_string;
		if (i.rate < 0.0001)
		{
			rate_string = '0';
		}
		else
		{
			rate_string = to_string(i.rate);
		}
		temp1 = ' ' + i.name + ' ' + i.id + ' ' + i.phone + ' ' +
			i.email + ' ' + i.password + ' ' + i.money + ' '
			+ i.savingMoney + " " + to_string(i.savingTime) + " " + to_string(i.judge) + " " + rate_string;
		for (auto j : temp1)
		{
			AllAccount->push_back(j);
		}
	}
	fstream AccountFile;
	AccountFile.open(AccountFileName, ios::app | ios::binary);
	if (!AccountFile.is_open()) {
		cout << "UserAccount.code open failed!" << endl;
		exit(0);
	}
	vector<bool>* temp = new vector<bool>;
	*temp = Code().newcode(*AllAccount);
	for (bool i : *temp)
	{
		AccountFile << i;
	}
	AccountFile.close();
	AllAccount->clear();
	temp->clear();
	for (auto i : *AdminAccounts)
	{
		string temp1;
		temp1 = ' ' + i.name + ' ' + i.id + ' ' + i.phone + ' ' + i.email + ' ' + i.password + ' ' + i.workid;
		for (auto j : temp1)
		{
			AllAccount->push_back(j);
		}
	}
	AccountFile.open(AccountFileName2, ios::app | ios::binary);
	if (!AccountFile.is_open()) {
		cout << "AdminAccount.code open failed!" << endl;
		exit(0);
	}
	*temp = Code().newcode(*AllAccount);
	for (bool i : *temp)
	{
		AccountFile << i;
	}
	AccountFile.close();
	delete temp;
	delete AllAccount;
}

bool BankSystem::clearAll() {
	ofstream AccountFile(AccountFileName);
	if (AccountFile.is_open()) {
		cout << "UserAccount.code has been cleared!" << endl;
	}
	else {
		cout << "UserAccount.code clear failed!" << endl;
	}
	AccountFile.close();
	ofstream AccountFile2(AccountFileName2);
	if (AccountFile2.is_open()) {
		cout << "AdminAccount.code has been cleared!" << endl;
	}
	else {
		cout << "AdminAccount.code clear failed!" << endl;
	}
	AccountFile2.close();
	return 1;
}

void BankSystem::change(vector<char>& input)//SavingAccount
{
	vector<char>temp;
	input.push_back(' ');
	input.push_back('\n');
	char* ptr = &input[1];//指向字符串中每个账户元素的读取
	SavingAccount temp2;
	while (1)
	{
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
        string str(temp.begin(), temp.end());
        temp2.name = str;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str5(temp.begin(), temp.end());
		temp2.id = str5;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str1(temp.begin(), temp.end());
		temp2.phone = str1;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str2(temp.begin(), temp.end());
		temp2.email = str2;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str3(temp.begin(), temp.end());
		temp2.password = str3;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str4(temp.begin(), temp.end());
		temp2.money = str4;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str6(temp.begin(), temp.end());
		temp2.savingMoney = str6;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str7(temp.begin(), temp.end());
		temp2.savingTime = stol(str7.c_str());
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		temp2.judge = (temp[0] - '0');
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		char x[7]; int n = 0;
		for (int i = 0; i < 6 && i < temp.size(); ++i)
		{
			x[n] = temp[i];
			++n;
		}
		x[n] = '\0';
		temp2.rate = atof(x);
		SavingAccounts->push_back(temp2);
        temp.clear();
		if (*ptr == '\n')
		{
			break;
		}
	}
}

void BankSystem::change2(vector<char>& input)//AdminAccount
{
	vector<char>temp;
	input.push_back(' ');
	input.push_back('\n');
	char* ptr = &input[1];         //指向字符串中每个账户元素的读取
	AdminAccount temp2;
	while (1)
	{
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str(temp.begin(), temp.end());
		temp2.name = str;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str1(temp.begin(), temp.end());
		temp2.id = str1;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str2(temp.begin(), temp.end());
		temp2.phone = str2;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str3(temp.begin(), temp.end());
		temp2.email = str3;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str4(temp.begin(), temp.end());
		temp2.password = str4;
		temp.clear();
		while (1)
		{
			if (*ptr == ' ')
			{
				++ptr; break;
			}
			else
			{
				temp.push_back(*ptr);
			}
			++ptr;
		}
		string str5(temp.begin(), temp.end());
		temp2.workid = str5;
		AdminAccounts->push_back(temp2);
		if (*ptr == '\n')
		{
			break;
		}
	}
}

bool BankSystem::registerAccount(bool judge, string name, string password,
	string id, string phone, bool judge2, double rate, string workid, string money, string savingMoney, string email)
{
	if (judge)
	{
		AdminAccount tempAccount;
		tempAccount.name = name;
		tempAccount.id = id;
		tempAccount.password = password;
		tempAccount.phone = phone;
		tempAccount.email = email;
		tempAccount.workid = workid;
		AdminAccounts->push_back(tempAccount);
		//saveAdd2(tempAccount);
	}
	else
	{
		SavingAccount tempAccount;
		tempAccount.name = name;
		tempAccount.id = id;
		tempAccount.password = password;
		tempAccount.phone = phone;
		tempAccount.email = email;
		tempAccount.rate = rate;
		tempAccount.money = money;
		tempAccount.savingMoney = savingMoney;
		tempAccount.judge = judge2;
		if (!judge2)
		{
			tempAccount.savingTime = 0;
		}
		else
		{
			tempAccount.savingTime = bktime().timeGet();
		}
		SavingAccounts->push_back(tempAccount);
		//saveAdd(tempAccount);
	}
	return 1;
}

vector<int> BankSystem::login(string id, string password)
{
	vector<int> judge;
	judge.push_back(false);
	judge.push_back(false);
	judge.push_back(-1);
	judge.push_back(false);
	judge.push_back(false);
	//judge[0]表示是否登录成功，judge[1]表示是否是管理员，judge[2]表示是第几个账户，judge[3]表示是否存在该账户,judge[4]表示是否开启储蓄账户
	for (int i = 0; i < SavingAccounts->size(); ++i)
	{
		if ((*SavingAccounts)[i].id == id)
		{
			judge[3] = 1;
			judge[2] = i;
			if ((*SavingAccounts)[i].password == password)
			{
				judge[0] = true;
				judge[4] = (*SavingAccounts)[i].judge;
				return judge;
			}
		}
	}
	for (int i = 0; i < (*AdminAccounts).size(); ++i)
	{
		if ((*AdminAccounts)[i].id == id)
		{
			judge[3] = 1;
			judge[2] = i;
			if ((*AdminAccounts)[i].password == password)
			{
				judge[0] = true;
				judge[1] = 1;
				return judge;
			}
		}
	}
	return judge;
}

SavingAccount* BankSystem::getUserAccount(int b)
{
	(*SavingAccounts)[b].update();
	return &(*SavingAccounts)[b];
}

AdminAccount* BankSystem::getAdminAccount(int b)
{
	return &(*AdminAccounts)[b];
}

int BankSystem::transfer(SavingAccount* a, string b, double c)
{
	vector<int>temp = login(b, "");
	if (!temp[3])
	{
		return 0;
    }
    if (!a->getmoney(c))
	{
		return 2;
	}
	(*SavingAccounts)[temp[2]].savemoney(c);
	return 1;
}

bool BankSystem::deleteUserAccount(int x)
{
	SavingAccounts->erase(SavingAccounts->begin() + x);
	SavingAccounts->shrink_to_fit();
	return 1;
}

bool BankSystem::deleteAdminAccount(int x)
{
	AdminAccounts->erase(AdminAccounts->begin() + x);
	AdminAccounts->shrink_to_fit();
	return 1;
}

void BankSystem::save()
{
	clearAll();
	saveall();
}

vector<string> BankSystem::showUsers()
{
	vector<string> output;
	for (auto i : (*SavingAccounts))
	{
		stringstream ss;
		string s = i.judge ? "是" : "否";
		ss << left << setw(11) << i.id << left << setw(8) << i.name << left << setw(13) << i.phone << left << setw(3) << s;
		output.push_back(ss.str());
	}
	return output;
}

vector<string> BankSystem::showAdmins()
{
	vector<string> output;
	for (auto i : (*AdminAccounts))
	{
		stringstream ss;
		ss << left << setw(11) << i.id << left << setw(8) << i.name << left << setw(13) << i.phone << left << setw(6) << "（管理员）";
		output.push_back(ss.str());
	}
	return output;
}