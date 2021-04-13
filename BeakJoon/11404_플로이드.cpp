// 21.04.13. 화
// 11404: 플로이드 https://www.acmicpc.net/problem/11404
// 플로이드 와샬 알고리즘.
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

namespace BOJ_11404
{
	constexpr int MAX = 1e9;

	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int> > costs(n + 1, vector<int>(n + 1, MAX));
		while (m--)
		{
			int i, j, cost;
			cin >> i >> j >> cost;
			costs[i][j] = min(costs[i][j], cost);
		}

		// 한번에 가는 것보다 경유해서 가는 것(i->k, k->j)이 더 빠른가?
		for (int k = 1; k <= n; ++k)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					if (i == j || i == k || j == k) continue;
					costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (costs[i][j] == MAX) cout << "0 ";
				else cout << costs[i][j] << " ";
			}
			cout << "\n";
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_11404::Solution();

	return 0;
}