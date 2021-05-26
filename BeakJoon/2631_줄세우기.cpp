// 21.05.26. 수
// 2631: 줄세우기 https://www.acmicpc.net/problem/2631
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_2631
{
	// 가장 큰 증가하는 부분 수열 구하기. (안건드려도 되는 애들).
	int GetDP(int n, vector<int>& nums)
	{
		int res = 1;
		vector<int> dp(n, 1);
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (nums[i] >= nums[j]) continue;
				dp[j] = max(dp[j], dp[i] + 1);
				res = max(res, dp[j]);
			}
		}

		return res;
	}

	void Solution()
	{
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}

		cout << n - GetDP(n, nums);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2631::Solution();

	return 0;
}