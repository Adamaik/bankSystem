#include "FlexibleAccount.h"
using namespace std;

bool FlexibleAccount::getMoney(int x)
{
	money -= x;
	return 1;
}