// 21.05.31. 월
// 11049: 행렬 곱셈 순서 https://www.acmicpc.net/problem/11049
// DP.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_11049
{
	struct Matrix { int r, c; };
	typedef long long LL;

	void GetDP(int n, vector<Matrix>& arr, vector<vector<pair<Matrix, LL> > >& dp)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			auto a = dp[i][i].first;
			auto b = dp[i + 1][i + 1].first;
			dp[i][i + 1] = { {a.r, b.c}, a.r * a.c * b.c };
		}

		for (int plus = 2; plus < n; ++plus)
		{
			for (int i = 0; i + plus < n; ++i)
			{
				int j = i + plus;
				for (int k = 0; k < j; ++k)
				{
					auto a = dp[i][k];
					auto b = dp[k + 1][j];
					LL value = (a.first.r * a.first.c * b.first.c) + a.second + b.second;
					if (dp[i][j].second == 0 || dp[i][j].second > value)
					{
						dp[i][j] = { {a.first.r, b.first.c}, value };
					}
				}
			}
		}
	}

	void Solution()
	{
		int n;
		cin >> n;
		vector<Matrix> arr(n);
		vector<vector<pair<Matrix, LL> > > dp(n, vector<pair<Matrix, LL>>(n));
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i].r >> arr[i].c;
			dp[i][i] = { { arr[i].r, arr[i].c }, 0 };
		}

		GetDP(n, arr, dp);

		// output.
		cout << dp[0][n - 1].second;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_11049::Solution();

	return 0;
}