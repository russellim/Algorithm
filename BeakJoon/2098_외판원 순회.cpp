// 21.05.10. 월
// 2098: 외판원 순회 https://www.acmicpc.net/problem/2098
// DP, 비트마스킹.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_2098
{
	constexpr int MAX = 2e9;
	vector<vector<int> > cost;
	vector<vector<int> > dp;
	int n;

	int tsp(int current, int visited)
	{
		if (visited == (1 << n) - 1)
		{
			if (cost[current][0] == 0) return MAX; // 자기 위치.
			return cost[current][0];
		}

		if (dp[current][visited] != 0) return dp[current][visited];

		dp[current][visited] = MAX;
		for (int i = 0; i < n; ++i)
		{
			int next = 1 << i;
			if (cost[current][i] == 0) continue;
			if ((visited & next) > 0) continue;

			dp[current][visited] = min(dp[current][visited], tsp(i, visited | next) + cost[current][i]);
		}

		return dp[current][visited];
	}

	void Solution()
	{
		cin >> n;
		dp.assign(n, vector<int>(1 << 16));
		cost.assign(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> cost[i][j];
			}
		}

		cout << tsp(0, 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2098::Solution();

	return 0;
}