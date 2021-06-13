// 21.06.13. 일
// 1256: 사전 https://www.acmicpc.net/problem/1256
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_1256
{
	constexpr long long K_MAX = 1000000000;

	void Solution()
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<long long> > dp(n + 1, vector<long long>(m + 1, 1));
		dp[0][0] = 0;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				dp[i][j] = min(K_MAX, dp[i - 1][j] + dp[i][j - 1]);
			}
		}

		//for (int i = 0; i <= n; ++i)
		//{
		//	for (int j = 0; j <= m; ++j)
		//	{
		//		cout << dp[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		if (dp[n][m] < k)
		{
			cout << -1 << " ";
			return;
		}

		int a_idx = n;
		int z_idx = m;
		for (int i = 0; i < n + m; ++i)
		{

			if (a_idx == 0)
			{
				cout << "z";
				--z_idx;
				continue;
			}
			else if (z_idx == 0)
			{
				cout << "a";
				--a_idx;
				continue;
			}

			int a = dp[a_idx - 1][z_idx];
			int z = dp[a_idx][z_idx - 1];

			if (k <= a)
			{
				cout << "a";
				--a_idx;
			}
			else
			{
				k -= a;
				cout << "z";
				--z_idx;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1256::Solution();

	return 0;
}