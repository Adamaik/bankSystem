#include "BankSystem.h"
#include<iostream>
#include<string>
using namespace std;

BankSystem::BankSystem()
{
	fstream AccountFile;
	AccountFile.open(AccountFileName, ios::in | ios::out | ios::binary);
	if (!AccountFile.is_open())
	{
		cout << "Account.code open failed!" << endl;
		exit(0);
		AccountFile.close();
	}
	vector<bool> temp;   //存储二进制数据
	char m;    //temperary
	while (AccountFile.get(m))
	{
		temp.push_back(static_cast<bool>(m));
	}
	AllAccount = Code().decode(temp);
	AccountFile.close();
}

void BankSystem::saveAdd() {
	fstream AccountFile;
	AccountFile.open(AccountFileName, ios::app | ios::binary);
	if (!AccountFile.is_open()) {
		cout << "Account.code open failed!" << endl;
		exit(0);
	}
	vector<bool> temp = Code().code(AddAccount);
	for (bool i : temp)
	{
		AccountFile << i;
	}
	AccountFile.close();
	AllAccount.insert(AllAccount.end(), AddAccount.begin(), AddAccount.end());
	AddAccount.clear();
}

void BankSystem::clearAll() {
	ofstream AccountFile(AccountFileName);
	if (AccountFile.is_open()) {
		cout << "AccountFile has been cleared!" << endl;
	}
	else {
		cout << "AccountFile clear failed!" << endl;
	}
	AccountFile.close();
}