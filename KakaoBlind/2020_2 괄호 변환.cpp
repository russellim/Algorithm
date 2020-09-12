#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string p)
{
	string u, v;
	int left = 0, right = 0;
	
	// 문자열 u, v로 분리.
	// u는 (, ) 수 같게, v는 분리한 나머지.
	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == '(') left++;
		else right++;
		
		if (left == right)
		{
			u = p.substr(0, i+1);
			v = p.substr(i+1);
			break;
		}
	}

	//cout << u << " " << v << endl;

	// u가 올바른 괄호 문자열인지 확인.
	vector<int> checkvec;
	bool uCorrect = true;
	for (int i = 0; i < u.size(); ++i)
	{
		if (u[i] == '(') checkvec.push_back('(');
		else
		{
			if (checkvec.empty())
			{
				uCorrect = false;
				break;
			}
			else checkvec.pop_back();
		}
	}

	// v가 빈 문자열이 아니면 v로 다시 나누러 가즈아.
	if(v != "") v = solution(v);

	// u가 올바른 괄호 문자열이 아니었다면 로직에 따라 재정렬 해줍니다.
	// 맞으면 그냥 u + v 붙이고.
	if (!uCorrect)
	{
		string temp = "(";
		temp +=  v + ")";
		u = u.substr(1, u.size() - 2);
		if (u.size() != 0)
		{
			for (int i = 0; i < u.size(); ++i)
			{
				if (u[i] == '(') u[i] = ')';
				else u[i] = '(';
			}
		}
		u = temp + u;
	}
	else
	{
		u += v;
	}

	//cout << "oh : " << u << endl;

	return u;
}