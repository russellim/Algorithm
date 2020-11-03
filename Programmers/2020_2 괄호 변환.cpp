// 20.11.03. 화 update.
// 2020_괄호 변환 https://programmers.co.kr/learn/courses/30/lessons/60058
// 재귀. IDE 사용 금지.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 201103 new 버전!
string MakeUV(string p)
{
	if (p == "") return "";
	string u = "", v = "";
	int stack = 0;
	bool notfair = false; // u가 "올바른" 괄호형인지 확인.

	// u, v 분리와 u 올바른 괄호형 확인을 한번에.
	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == '(') stack++;
		else if (p[i] == ')') stack--;

		if (stack < 0) notfair = true;

		if (stack == 0)
		{
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}

	// 재귀로 v가 "" 일때까지.
	v = MakeUV(v);

	// u가 올바른 괄호형이 아니면 변환후 반환해주세여.
	if (notfair)
	{
		string temp;
		temp = "(" + v + ")";
		u = u.substr(1, u.size() - 2);
		for (int i = 0; i < u.size(); ++i)
		{
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		return temp + u;
	}
	// u가 올바른 괄호형이면 그냥 반환.
	return u + v;
}

string solution(string p) {
	if (p == "") return "";
	string answer = "";

	answer = MakeUV(p);

	return answer;
}




// 200915 old 버전.
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