#include "Code.h"
#include<bitset>

std::vector<bool> Code::newcode(const std::vector<char>& x)
{
	int temp2 = 1;
	std::vector<bool>x_binary;
	for (auto i : x)
	{
		std::bitset<8> temp(i);
		for (int j = 0; j < 8; j++)
		{
			x_binary.push_back(temp.test(j) ^ key[(temp2 - 1) % 50]);
			++temp2;
		}
	}
	return x_binary;
}

std::vector<char> Code::decode(const std::vector<bool>& x,bool fuck)
{
	std::vector<char>x_char;
	int n = 1,n2=1;
	if (fuck)
	{
		for (int i = 0; i < x.size(); i += 8)
		{
			std::bitset<8> temp;
			for (int j = 0; j < 8; j++)
			{
				temp.set(j, x[n - 1] ^ key[(n - 1) % 50]);
				++n;
			}
			x_char.push_back(temp.to_ulong());
		}
		return x_char;
	}
	else
	{
		for (int i = 0; i < x.size(); i += 8)
		{
			std::bitset<8> temp;
			for (int j = 0; j < 8; j++)
			{
				temp.set(j, x[n2 - 1] ^ key[(n2 - 1) % 50]);
				++n2;
			}
			x_char.push_back(temp.to_ulong());
		}
		return x_char;
	}
}