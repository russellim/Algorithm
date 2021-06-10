// 21.06.10. 목
// 2169: 로봇 조종하기 https://www.acmicpc.net/problem/2169
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

namespace BOJ_2169
{
	constexpr int MIN = INT_MIN;

	int n, m;
	vector<vector<int> > arr;
	vector<vector<int> > dp;

	void CheckRight(int r)
	{
		int store = dp[r - 1][0] + arr[r][0];
		for (int c = 1; c < m; ++c)
		{
			dp[r][c - 1] = max(dp[r][c - 1], store);
			store = max(store, dp[r - 1][c]) + arr[r][c];
		}
		dp[r][m - 1] = max(dp[r][m - 1], store);
	}

	void CheckLeft(int r)
	{
		int store = dp[r - 1][m - 1] + arr[r][m - 1];
		for (int c = m - 2; c >= 0; --c)
		{
			dp[r][c + 1] = max(dp[r][c + 1], store);
			store = max(store, dp[r - 1][c]) + arr[r][c];
		}
		dp[r][0] = max(dp[r][0], store);
	}

	void Solution()
	{
		cin >> n >> m;
		arr.assign(n, vector<int>(m));
		dp.assign(n, vector<int>(m, MIN));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> arr[i][j];
			}
		}

		dp[0][0] = arr[0][0];
		for (int j = 1; j < m; ++j)
		{
			dp[0][j] = dp[0][j-1] + arr[0][j];
		}

		for (int i = 1; i < n; ++i)
		{
			CheckRight(i);
			if (i == n - 1) break;
			CheckLeft(i);
		}

		//cout << endl;
		//for (int i = 0; i < n; ++i)
		//{
		//	for (int j = 0; j < m; ++j)
		//	{
		//		cout << dp[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		cout << dp[n - 1][m - 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2169::Solution();

	return 0;
}