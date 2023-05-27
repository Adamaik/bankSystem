#include<iostream>
#include<vector>
using namespace std;
class friends
{
public:
	friends();
	~friends();
	void registers();
	void cancellation(int);
	bool isfriend(int, int);
    void set(int,int);
    vector<vector<bool>>frimix;
    vector<vector<bool>>temp;
    int sum;
private:
	const std::string FriendsFileName = "D:\\cppsave\\Friends.code";
	void carr();
};
