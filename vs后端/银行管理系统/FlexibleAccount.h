#pragma once
#include<string>
#include"User.h"
class FlexibleAccount:public User
{
protected:
	string money;
public:
	bool getMoney(int);

};

