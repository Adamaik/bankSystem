#include<iostream>
#include"BankSystem.h"
using namespace std;

int main()
{
	BankSystem bank;
	/*bank.friendsys.registers();
	bank.friendsys.registers();
	bank.friendsys.registers();
	bank.friendsys.registers();
	bank.friendsys.registers();
	bank.friendsys.registers();
	bank.friendsys.registers();
	bank.friendsys.registers();
	bank.friendsys.set(4, 5);
	bank.friendsys.set(5, 1);*/
string s1 = "Peter";
	//bool b1 = 0;
	bank.registerAccount(0, s1, "123456", "123456", "78945612365",0);
	//vector<int> temp = bank.login("123456", "123456");
	//cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
	//SavingAccount* s =bank.getUserAccount(temp[2]);
	//s->savemoney(100.78);
	//cout << s->money << endl;
	//system("pause");
	vector<string> temp = bank.showUsers();
	cout << temp[0];
}