#include "RussUtil.h"

vector<string> RussUtil::cutStringbySpace(string str)
{
	vector<string> res;
	string token;
	for (stringstream ss(str); (ss >> token); )
	{
		res.push_back(token);
	}
	return res;
}
