// 20.11.20. 금
// 14888:연산자 끼워넣기 https://www.acmicpc.net/problem/14888
// 백트래킹
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> nums;
vector<int> ans;
string cul, tempCul;
int maxAns = -1e9, minAns = 1e9;
int tempAns;

void calcul(int a, int& b, char& c)
{
	switch (c)
	{
		case '+': b = a + b; break;
		case '-': b = a - b; break;
		case '*': b = a * b; break;
		case '/': b = a / b; break;
	}
}

void makeAnswer(int count )
{
	if (count == n - 1)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			if (ans[i + 1] == 0 && tempCul[i] == '/')
			{ 
				ans = nums;
				return;
			}
			calcul(ans[i], ans[i + 1], tempCul[i]);
		}
		maxAns = max(maxAns, ans[n - 1]);
		minAns = min(minAns, ans[n - 1]);
		ans = nums;
		return;
	}

	for (int i = 0; i < cul.size(); ++i)
	{
		tempCul += cul[i];
		cul.erase(cul.begin() + i);
		makeAnswer(count + 1);
		cul.insert(cul.begin() + i, tempCul.back());
		tempCul.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	ans = nums;
	for (int i = 0; i < 4; ++i)
	{
		int temp;
		cin >> temp;
		if (temp != 0)
		{
			if (i == 0) while (temp--) cul += "+";
			else if (i == 1) while (temp--) cul += "-";
			else if (i == 2) while (temp--) cul += "*";
			else while (temp--) cul += "/";
		}
	}

	makeAnswer(0);

	cout << maxAns << "\n" << minAns;

	return 0;
}