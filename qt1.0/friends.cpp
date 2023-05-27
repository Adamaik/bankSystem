#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include "friends.h"

friends::friends()
{


	fstream friendsfile;
	friendsfile.open(FriendsFileName, ios::in | ios::out | ios::binary);
	if (!friendsfile.is_open())
	{
		cout << "Friends.code open failed!(line 12)" << endl;
		exit(0);
		friendsfile.close();
	}
	char temp1;
	bool temp2;
 frimix.resize(1);
	int n = 0;
	while (friendsfile.get(temp1))
	{
		if (temp1 == ' ')
		{
			++n;
			frimix.resize(n+1);
			continue;
		}
		else if (temp1 == '\n')
		{
			frimix.resize(n);
			break;
		}
		temp2 = (int)(temp1 - '0');
		frimix[n].push_back(temp2);
	}
	friendsfile.close();
}

friends::~friends()
{
	ofstream friendsfile(FriendsFileName);
	if (!friendsfile.is_open())
	{
		cout << "Friends.code open failed!(line 12)" << endl;
		exit(0);
		friendsfile.close();
	}
	else
	{
		cout << "Friends.code has been cleared!" << endl;
	}
	friendsfile.close();
	friendsfile.open(FriendsFileName, ios::in | ios::out | ios::binary);
	for (vector<bool>i : frimix)
	{
		for (bool j : i)
		{
			friendsfile << j;
		}
		friendsfile << ' ';
	}
	friendsfile << '\n';
	friendsfile.close();
}

void friends::registers()
{
    sum += 1;
}
void friends::set(int x,int y)
{
    frimix.resize(sum);
    temp.resize(sum);
    for (int i = 0; i < sum; i++)
    {
        frimix[i].resize(sum);
        temp[i].resize(sum);
    }
	this->frimix[x][y] = 1;
	this->frimix[y][x] = 1;
	carr();
}
void friends::cancellation(int item)
{
	int n = sum;
	for (int i=item; i<n-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			frimix[i][j] = frimix[i + 1][j];
		}
	}
	n -= 1;
	for (int i = item; i < sum-1; i++)
	{
		for (int j = 0; j < sum; j++)
		{
			frimix[j][i] = frimix[j][i+1];
		}
	}
	sum -= 1;
}
bool friends::isfriend(int x, int y)
{
	if (frimix[x][y]) return 1;
	else return 0;
}

void friends::carr()
{
    for (int p = 1; p < sum-1; p++)
	{
		temp = frimix;
        for (int i = 0; i < sum-1; i++)
		{
            for (int j = 0; j < sum-1; j++)
			{
                for (int k = 0; k < sum-1; k++)
				{
					temp[i][j] = this->frimix[i][k] * this->frimix[k][j] + temp[i][j];
				}
			}
		}
		this->frimix = temp;
	}
    for (int i = 0; i < sum-1; i++)
	{
		frimix[i][i] = 1;
	}
}
