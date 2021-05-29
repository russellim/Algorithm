// 21.05.29. 토
// 11066: 파일 합치기 https://www.acmicpc.net/problem/11066
// DP.

// 아직.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_11066
{
	int GetDP(int n, vector<int>& arr, vector<int>& psum)
	{
		vector<vector<int> > dp(n + 1, vector<int>(n + 1, 2e9));
		for (int i = 1; i <= n; ++i) dp[i][i] = arr[i];
		for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = dp[i][i] + dp[i + 1][i + 1];

		for (int p = 2; p < n; ++p)
		{
			for (int i = 1; i + p <= n; ++i)
			{
				int j = i + p;

				for (int k = i; k < j; ++k)
				{
					// 여기 좀더 보수하기.
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + psum[j] - psum[i - 1]);
				}
			}
		}

		cout << endl;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		return dp[1][n];
	}

	void Solution()
	{
		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			vector<int> arr(n + 1, 0);
			vector<int> psum(n + 1, 0);
			for (int i = 1; i <= n; ++i)
			{
				cin >> arr[i];
				psum[i] = psum[i - 1] + arr[i];
			}

			cout << GetDP(n, arr, psum) << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_11066::Solution();

	return 0;
}