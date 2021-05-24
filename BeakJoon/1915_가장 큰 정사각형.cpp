// 21.05.24. 월
// 1915: 가장 큰 정사각형 https://www.acmicpc.net/problem/1915
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_2225
{
	constexpr int div = 1000000000;

	int GetDP(vector<vector<int> >& pann, int n, int m)
	{
		int res = pann[0][0];
		vector<vector<int> >dp(n, vector<int>(m, 0));

		for (int i = 0; i < n; ++i) dp[i][0] = pann[i][0];
		for (int j = 0; j < m; ++j) dp[0][j] = pann[0][j];

		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < m; ++j)
			{
				if (pann[i][j] == 0) continue;
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
				res = max(res, dp[i][j]);
			}
		}

		return res * res;
	}

	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int> > pann(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%1d", &pann[i][j]);
			}
		}

		cout << GetDP(pann, n, m);
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	BOJ_2225::Solution();

	return 0;
}