// 21.05.10. 월
// 2098: 외판원 순회 https://www.acmicpc.net/problem/2098
// DP, 비트마스킹.

// 방문처리를 2진법으로 표현.
// n == 4, 0101 => 0번, 2번을 방문함. 1000 => 4번 방문함.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_2098
{
	constexpr int MAX = 2e9;
	vector<vector<int> > cost;
	vector<vector<int> > dp;
	int n, start;

	//Traveling Salesman problem.
	int tsp(int now, int visited)
	{
		if (visited == (1 << n) - 1) // 모두 방문했음.
		{
			if (cost[now][start] == 0) return MAX;
			return cost[now][start];
		}

		if (dp[now][visited] != 0) return dp[now][visited];
		dp[now][visited] = MAX;

		for (int i = 0; i < n; ++i)
		{
			if (cost[now][i] == 0) continue;	// 자기 위치는 안감. ex) 1 -> 1.

			int next = 1 << i;
			// 0001 & 1000 = 0000 // 0001 & 0001 = 0001 > 0.
			if ((visited & next) > 0) continue;	// 중복이 있으면 0보다 커집니다. 제외.

			// 0001 | 1000 = 1001 == 0번, 3번 방문처리 완료.
			dp[now][visited] = min(dp[now][visited], tsp(i, visited | next) + cost[now][i]);
		}

		//cout << now << " " << visited << " " << dp[now][visited];
		return dp[now][visited];
	}

	void Solution()
	{
		cin >> n;
		// 1 << 4  == 10000(2) == 16.
		// 1 << 16 == 10000000000000000(2) == 65536.
		dp.assign(n, vector<int>(1 << n, 0)); // n=4, dp[4][16].
		cost.assign(n, vector<int>(n));
		start = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> cost[i][j];
			}
		}

		// output.
		cout << tsp(start, 1); // 1 == 0001 (0번방문)
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2098::Solution();

	return 0;
}