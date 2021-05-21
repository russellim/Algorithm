// 21.05.21. 금
// 7579: 앱 https://www.acmicpc.net/problem/7579
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_7579
{
	void Solution()
	{
		int n, m;
		cin >> n >> m;

		vector<int> mem(n);
		for (int& x : mem) cin >> x;

		vector<int> cost(n);
		int sum = 0;
		for (int& x : cost)
		{
			cin >> x;
			sum += x;
		}

		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int limit = sum; limit >= cost[i]; --limit)
			{
				int diff = limit - cost[i];
				dp[limit] = max(dp[limit], dp[diff] + mem[i]);
			}
		}

		int answer;
		for (answer = 0; dp[answer] < m; ++answer);
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_7579::Solution();

	return 0;
}