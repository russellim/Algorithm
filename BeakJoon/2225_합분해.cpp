// 21.05.23. 
// 2225: 합분해 https://www.acmicpc.net/problem/2225
// DP.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_2225
{
	constexpr int div = 1000000000;

	int GetDP(int n, int k)
	{
		if (n == 1) return k;
		if (k == 1) return 1;
		vector<vector<int> > dp(n + 1, vector<int>(k + 1, 1));
		for (int j = 2; j <= k; ++j)
		{
			for (int i = 1; i <= n; ++i)
			{
				if (i == 1) dp[i][j] = j;
				else
				{
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % div;
				}
			}
		}
		return dp[n][k];
	}

	void Solution()
	{
		int n, k;
		cin >> n >> k;

		cout << GetDP(n, k);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2225::Solution();

	return 0;
}