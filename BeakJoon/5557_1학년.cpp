// 21.05.25. 화
// 5557: 1학년 https://www.acmicpc.net/problem/5557
// DP.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_5557
{
	// 결과값 범위를 항상 조심하십시오.
	long long GetDP(int n, vector<int>& nums)
	{
		// 왼쪽 숫자부터 하나씩 결과값 저장해나감.
		int dpSize = n - 1;
		vector<vector<long long> > dp(dpSize, vector<long long>(21, 0));
		dp[0][nums[0]]++;

		for (int i = 0; i < dpSize - 1; ++i)
		{
			for (int j = 0; j <= 20; ++j)
			{
				if (dp[i][j] == 0) continue;
				int number = nums[i + 1];
				if (j + number <= 20) dp[i + 1][j + number] += dp[i][j]; // +.
				if (j - number >= 0)  dp[i + 1][j - number] += dp[i][j]; // -.
			}
		}

		return dp[dpSize - 1][nums.back()];
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

		cout << GetDP(n, nums);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_5557::Solution();

	return 0;
}