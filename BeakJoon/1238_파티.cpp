// 21.04.24. 토
// 1238: 파티 https://www.acmicpc.net/problem/1238
// 다익스트라.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace BOJ_1238
{
	struct Dest { int from, cost; };
	constexpr int MAX = 2e9;
	int n, m;
	vector<vector<Dest> > dest;

	void Dijkstra(int start, vector<int>& result)
	{
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push({ 0, start });

		while (!pq.empty())
		{
			int nowCost = pq.top().first;
			int nowPos = pq.top().second;
			pq.pop();

			for (int i = 0; i < dest[nowPos].size(); ++i)
			{
				int nextCost = dest[nowPos][i].cost + nowCost;
				int nextPos = dest[nowPos][i].from;
				if (result[nextPos] <= nextCost) continue;
				
				result[nextPos] = nextCost;
				pq.push({ nextCost, nextPos });
			}
		}
	}

	void Solution()
	{
		int x, answer = 0;
		cin >> n >> m >> x;
		dest.assign(n + 1, vector<Dest>());
		for (int i = 0; i < m; ++i)
		{
			int to, from, cost;
			cin >> to >> from >> cost;
			dest[to].push_back({ from, cost });
		}

		vector<int> XtoHome(n + 1, MAX);
		Dijkstra(x, XtoHome);

		vector<int> HometoX;
		for (int i = 1; i <= n; ++i)
		{
			if (i == x) continue;
			HometoX.assign(n + 1, MAX);
			Dijkstra(i, HometoX);
			answer = max(answer, HometoX[x] + XtoHome[i]);
		}

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1238::Solution();

	return 0;
}