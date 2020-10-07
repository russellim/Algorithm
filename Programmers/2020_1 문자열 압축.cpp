// 20.09.04 토
// 1932: 정수 삼각형 https://www.acmicpc.net/problem/1932
// DP
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(string s)
{
	if (s.size() == 1) return 1;
	int MinCount = 10000;

	for (int i = 1; i <= s.size() / 2; ++i)
	{
		vector<int> count;
		string store, prev = "";
		for (int j = 0; j < s.size() / i + 1; ++j)
		{
			if (i * j >= s.size()) break;
			string temp = s.substr(i * j, i);
			if (prev != temp)
			{
				store += temp;
				prev = temp;
				count.push_back(1);
			}
			else
			{
				count.back()++;
			}
		}
		int sum = 0;
		for (int j = 0; j < count.size(); ++j)
		{
			if (count[j] != 1)
			{
				store += to_string(count[j]);
			}
		}
		if (MinCount > store.size())
			MinCount = store.size();
	}
	return MinCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	string str;
	cin >> str;
	cout << solution(str);
}