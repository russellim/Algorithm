// 21.05.13. 목
// 1062: 가르침 https://www.acmicpc.net/problem/1062
// 백트래킹, 비트마스킹(방문처리에).
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_1062
{
	int n, k, answer = 0;
	int visit = 1 << 27;
	vector<string> str;

	int CharToInt(char c)
	{
		return c - 'a';
	}

	bool CheckWord(string& word)
	{
		for(int i=0; i< word.size(); ++i)
		{
			int cint = CharToInt(word[i]);
				if ((visit & 1 << cint) != 1<< cint) return false;
		}
		return true;
	}

	void LearnWord(int alpha, int count)
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
			if ((visit & 1<<i) != 1<<i) // 해당 알파벳을 아직 안배웠으면.
			{
				visit = visit | 1 << i;
				CountWord(i, count + 1);
				visit = visit & ~(1 << i);
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

		visit = visit | 1 << CharToInt('a') | 1 << CharToInt('n') | 1 << CharToInt('t')
			| 1 << CharToInt('i') | 1 << CharToInt('c');

		LearnWord(0, 0);
		cout << answer;
	}
}

int main()
{
	BOJ_1062::Solution();
	return 0;
}