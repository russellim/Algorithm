// 21.05.30. 일
// 10942: 팰린드롬? https://www.acmicpc.net/problem/10942
// DP.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_10942
{
	// dp[i][j]: i번부터 j번까지 팰린드롬 여부.
	// 3자리 이상부터 i번과 j번이 같고, i+1번에서 j-1번까지가 팰린드롬이면 true.
	// ex> 1 2 1 3 1 -> 1 == 1 (T) / 2 1 3 (F).
	void GetDP(int n, vector<int>& arr, vector<vector<bool> >& dp)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			dp[i][i + 1] = (arr[i] == arr[i + 1]);
		}

		for (int k = 2; k < n; ++k)
		{
			for (int i = 0; i + k < n; ++i)
			{
				int j = i + k;
				dp[i][j] = (arr[i] == arr[j] && dp[i + 1][j - 1]);
			}
		}
	}

	void Solution()
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<vector<bool> > dp(n, vector<bool>(n, true));
		for (int& x : arr) cin >> x;
		GetDP(n, arr, dp);

		int t;
		cin >> t;
		while (t--)
		{
			int start, end;
			cin >> start >> end;
			if (dp[start - 1][end - 1]) cout << "1\n";
			else cout << "0\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_10942::Solution();

	return 0;
}