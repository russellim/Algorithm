// 21.02.16. 화
// 5525: IOIOI https://www.acmicpc.net/problem/5525
// KMP 알고리즘(만들 사람들 이름 앞글자임)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace BOJ_5525
{
	int n, m, answer;
	string s;

	void MakeToken(string& token)
	{
		for (int i = 0; i < n; ++i)
		{
			token += "IO";
		}
		token += "I";
	}

	// 토큰에도 반복되는 부분이 있는지 찾는다.
	vector<int> GetPi(string token)
	{
		int tsize = token.size(), j = 0;
		vector<int> pi(tsize, 0);
		for (int i = 1; i < tsize; ++i)
		{
			while (j > 0 && token[i] != token[j])
			{
				j = pi[j - 1];
			}
			if (token[i] == token[j])
			{
				pi[i] = ++j;
			}
		}
		return pi;
	}

	void Solution()
	{
		string token;
		MakeToken(token);
		auto pi = GetPi(token);

		int ssize = m, tsize = token.size(), j = 0;
		for (int i = 0; i < ssize; ++i)
		{
			while (j > 0 && s[i] != token[j])
			{
				j = pi[j - 1];
			}
			if (s[i] == token[j])
			{
				if (j == tsize - 1) // token 탐색 끝.
				{
					answer++;
					j = pi[j];
				}
				else
				{
					++j;
				}
			}
		}
	}

	void Input()
	{
		cin >> n >> m >> s;
	}

	void Output()
	{
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_5525::Input();
	BOJ_5525::Solution();
	BOJ_5525::Output();

	return 0;
}