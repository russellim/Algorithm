// 21.04.23. 금
// 11779: 최소비용 구하기 2 https://www.acmicpc.net/problem/11779
// 다익스트라.
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

// 다익스트라.
// 생각보다 메모리 많이 안먹어서 놀람.
namespace BOJ_11779
{
	constexpr int MAX = INT_MAX;
	struct Dest { int from, cost; };
	int n, m;
	vector<vector<Dest> > route;

	void Dijkstra(int start, int end)
	{
		// { 비용, 루트(vector) }.
		vector<pair<int, vector<int> > > minCost(n + 1, { MAX, {} });
		priority_queue<pair<int, vector<int> >, vector<pair<int, vector<int> > >, greater<pair<int, vector<int> > > > pq;
		pq.push({ 0, {start} });

		while (!pq.empty())
		{
			int nowCost = pq.top().first;
			auto nowRoute = pq.top().second;
			int nowPos = nowRoute.back();
			pq.pop();

			for (int i = 0; i < route[nowPos].size(); ++i)
			{
				int nextCost = nowCost + route[nowPos][i].cost;
				int newPos = route[nowPos][i].from;

				if (nextCost >= minCost[newPos].first) continue;
				auto newRoute = nowRoute;
				newRoute.push_back(newPos);

				minCost[newPos] = { nextCost, newRoute };
				pq.push({ nextCost, newRoute });
			}
		}

		// output.
		cout << minCost[end].first << "\n";
		cout << minCost[end].second.size() << "\n";
		for (int x : minCost[end].second) cout << x << " ";
	}

	void Solution()
	{
		cin >> n >> m;
		route.assign(n + 1, vector<Dest>());
		for (int i = 0; i < m; ++i)
		{
			int to, from, cost;
			cin >> to >> from >> cost;
			route[to].push_back({ from, cost });
		}

		int start, end;
		cin >> start >> end;
		Dijkstra(start, end);
	}
}

// 플로이드 와샬
// 코드도 복잡하고 메모리 초과남.
namespace BOJ_11779_Legacy
{
	constexpr int MAX = INT_MAX;
	int n, m;
	vector<vector<int> > cost;
	vector<vector<vector<int> > > route;

	void Solution()
	{
		cin >> n >> m;
		cost.assign(n + 1, vector<int>(n + 1, MAX));
		route.assign(n + 1, vector<vector<int> >(n + 1));
		for (int i = 0; i < m; ++i)
		{
			int to, from, c;
			cin >> to >> from >> c;
			cost[to][from] = min(cost[to][from], c);
		}

		for (int k = 1; k <= n; ++k)
		{
			for (int i = 1; i <= n; ++i)
			{
				if (i == k || cost[i][k] == MAX) continue;
				for (int j = 1; j <= n; ++j)
				{
					if (i == j || j == k) continue;
					if (cost[k][j] == MAX) continue;
					if (cost[i][j] > cost[i][k] + cost[k][j])
					{
						cost[i][j] = cost[i][k] + cost[k][j];

						if (route[i][k].size() > route[k][j].size())
						{
							route[i][j] = route[i][k];
							route[i][j].push_back(k);
						}
						else
						{
							route[i][j].push_back(k);
							route[i][j].insert(route[i][j].end(), route[k][j].begin(), route[k][j].end());
						}
					}
				}
			}
		}

		// output.
		int start, end;
		cin >> start >> end;
		cout << cost[start][end] << "\n";
		cout << route[start][end].size() + 2 << "\n";
		cout << start << " ";
		for (int i = 0; i < route[start][end].size(); ++i)
		{
			cout << route[start][end][i] << " ";
		}
		cout << end;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_11779::Solution();

	return 0;
}
