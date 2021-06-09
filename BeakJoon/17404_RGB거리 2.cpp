// 21.06.09. 수
// 17404: RGB거리 2 https://www.acmicpc.net/problem/17404
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_17404
{
	constexpr int MAX = 2e9;

	int n;
	vector<vector<int> > costs;

	int GetCost(int firstPick)
	{
		vector<vector<int> > dp(n, vector<int>(3, MAX));
		dp[0][firstPick] = costs[0][firstPick];

		for (int i = 0; i < n - 1; ++i)
		{
			for (int now = 0; now < 3; ++now)
			{
				if (i == 0 && now != firstPick) continue; // 0번사람 시작색만.

				for (int next = 0; next < 3; ++next)
				{
					if (now == next) continue; // 다음은 다른색으로.
					if (i == n - 2 && next == firstPick) continue; // 마지막 색에서는 시작색 빼기.
					dp[i + 1][next] = min(dp[i + 1][next], dp[i][now] + costs[i + 1][next]);
				}
			}
		}

		//cout << endl;
		//for (auto& x : dp)
		//{
		//	for (int y : x) cout << y << " ";
		//	cout << endl;
		//}

		return *min_element(dp[n - 1].begin(), dp[n - 1].end());
	}

	void Solution()
	{
		int answer = MAX;
		cin >> n;
		costs.assign(n, vector<int>(3, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> costs[i][j];
			}
		}

		// 3가지 색으로 각각 시작해보자.
		for (int i = 0; i < 3; ++i)
		{
			answer = min(answer, GetCost(i));
		}

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_17404::Solution();

	return 0;
}