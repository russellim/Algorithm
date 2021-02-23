// 21.02.23. 화
// 2407: 조합 https://www.acmicpc.net/problem/2407
// Math.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace BOJ_2407
{
	void SizeFit(string& str, int zero)
	{
		str = string(zero, '0') + str;
	}

	string BigPlus(string a, string b)
	{
		a.size() > b.size() ? SizeFit(b, a.size() - b.size()) : SizeFit(a, b.size() - a.size());
		int carry = 0;
		string result = "";
		for (int i = a.size() - 1; i >= 0; --i)
		{
			carry += (a[i] - '0') + (b[i] - '0');
			result = to_string(carry % 10) + result;
			carry /= 10;
		}
		if (carry != 0) result = to_string(carry) + result;
		return result;
	}

	void Solution()
	{
		// nCm.
		int n, m;
		cin >> n >> m;
		if (m == 0 || m == n)
		{
			cout << "1";
			return;
		}
		vector<vector<string> > dp(101, vector<string>(101, "1"));
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				dp[i][j] = BigPlus(dp[i - 1][j - 1], dp[i - 1][j]);
				if (i == n && j == m)
				{
					cout << dp[i][j];
					return;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2407::Solution();

	return 0;
}

// 아아ㅡ... "기억" 해 버렸나ㅡ...... 나도 "불합리" 하다고 밖에 생각이 들지 않는구나...