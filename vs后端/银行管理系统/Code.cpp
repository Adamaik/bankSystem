#include "Code.h"
#include<bitset>
std::vector<bool> Code::code(const std::vector<char>&x)
{
	std::vector<bool>x_binary;
	int n = 1;
	for (auto i : x)
	{
		std::bitset<8> temp(i);
		for (int j=0;j<8;j++)
		{
			x_binary.push_back(temp.test(j)^key[ (n-1) % 50]);
			++n;
		}
	}
	return x_binary;
}

std::vector<char> Code::decode(const std::vector<bool>& x)
{
	std::vector<char>x_char;
	int n = 1;
	for (int i = 0; i < x.size(); i += 8)
	{
		std::bitset<8> temp;
		for (int j = 0; j < 8; j++)
		{
			temp.set(j, x[n-1] ^ key[(n - 1) % 50 ]);
			++n;
		}
		x_char.push_back(temp.to_ulong());
	}
	return x_char;
}