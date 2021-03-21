// 21.03.21. 일
// 12865: 평범한 배낭 https://www.acmicpc.net/problem/12865
// DP. 동전문제랑 비슷!
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_12865
{
	struct stuff
	{
		int weight, value;
	};

	void Solution()
	{
		int n, k, w, v;
		cin >> n >> k;
		vector<stuff> values(n);
		vector<int> dp(k + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> w >> v;
			values[i] = { w, v };
		}

		for (int i = 0; i < n; ++i)
		{
			for (int limit = k; limit >= 1; --limit)
			{
				if (limit - values[i].weight >= 0)
				{
					dp[limit] = max(dp[limit], dp[limit - values[i].weight] + values[i].value);
				}
			}
		}

		cout << dp[k];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_12865::Solution();

	return 0;
}