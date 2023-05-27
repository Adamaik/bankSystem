#pragma once
#include<vector>
class Code
{
public:
	std::vector<char> decode(const std::vector<bool>&, bool);
	std::vector<bool> newcode(const std::vector<char>&);
private:
	const std::vector<bool> key = { 1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,1,0 };//共有50位作为密钥
};

