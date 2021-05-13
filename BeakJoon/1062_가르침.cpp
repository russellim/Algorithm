// 21.05.13. 목
// 1062: 가르침 https://www.acmicpc.net/problem/1062
// 백트래킹.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_1062
{
	int n, k, answer = 0;
	vector<bool> visit;
	vector<string> str;

	bool CheckWord(string& word)
	{
		for(int i=0; i< word.size(); ++i)
		{
				if (!visit[word[i] - 'a']) return false;
		}
		return true;
	}

	void CountWord(int alpha, int count)
	{
		if (count == k)
		{
			int res = 0;
			for (int i = 0; i < n; ++i)
			{
				if (CheckWord(str[i])) ++res;
			}
			answer = max(answer, res);
			return;
		}

		for (int i = alpha; i < 26; ++i)
		{
			if (!visit[i])
			{
				visit[i] = true;
				CountWord(i, count + 1);
				visit[i] = false;
			}
		}
	}


	void Solution()
	{
		cin >> n >> k;
		if (k < 5)
		{
			cout << "0";
			return;
		}
		if (k == 26)
		{
			cout << n;
			return;
		}

		k -= 5;
		str.assign(n, "");
		for (int i = 0; i < n; ++i)
		{
			cin >> str[i];
			str[i] = str[i].substr(4, str[i].size() - 8);
		}

		visit.assign(26, false);
		visit['a' - 'a'] = visit['n' - 'a'] = visit['t' - 'a'] = visit['i' - 'a'] = visit['c' - 'a'] = true;
		
		CountWord(0, 0);
		cout << answer;
	}
}

int main()
{
	BOJ_1062::Solution();
	return 0;
}