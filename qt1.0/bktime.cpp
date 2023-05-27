#include "bktime.h"
#include <ctime>
using namespace std;

long bktime::timeGet()
{
	time_t t = time(NULL);
	long output = t;
	return output;
}

int bktime::days(long t1, long t2)
{
	int output = (t2 - t1) / 86400;
	return output;
}