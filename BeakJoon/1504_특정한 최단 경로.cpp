// 21.03.27. 토
// 1504: 특정한 최단 경로 https://www.acmicpc.net/problem/1504
// 다익스트라.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

namespace BOJ_1504
{
	constexpr int MAX_COST = INT_MAX;
	struct Edge { int destination, cost; };
	int n, e;
	vector<vector<Edge> > edges;

	int Dijkstra(int start, int end)
	{
		vector<int> costs(n + 1, MAX_COST);
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
		q.push({ 0, start });
		costs[start] = 0;

		while (!q.empty())
		{
			int nowPos = q.top().second;
			int nowCost = q.top().first;
			q.pop();
			for (int i = 0; i < edges[nowPos].size(); ++i)
			{
				int nextPos = edges[nowPos][i].destination;
				int needCost = edges[nowPos][i].cost + nowCost;
				if (costs[nextPos] <= needCost) continue;
				costs[nextPos] = needCost;
				q.push({ needCost, nextPos });
			}
		}

		if (costs[end] == MAX_COST) return -1;
		return costs[end];
	}

	void Solution()
	{
		int station1, station2;
		cin >> n >> e;
		edges.assign(n + 1, vector<Edge>());
		for (int i = 0; i < e; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges[a].push_back({ b, c });
			edges[b].push_back({ a, c });
		}
		cin >> station1 >> station2;

		// (1 ~ station1) + (station1 ~ station2) + (station2 ~ n).
		// (1 ~ station2) + (station2 ~ station1) + (station1 ~ n).
		// 둘 중 최소값.
		int answer[6] = { Dijkstra(1, station1), Dijkstra(station1, station2), Dijkstra(station2, n),
						Dijkstra(1, station2), Dijkstra(station2, station1), Dijkstra(station1, n) };

		if ((answer[0] == -1 || answer[1] == -1 || answer[2] == -1) && (answer[3] == -1 || answer[4] == -1 || answer[5] == -1))
			cout << -1;
		else cout << min(answer[0] + answer[1] + answer[2], answer[3] + answer[4] + answer[5]);
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1504::Solution();

	return 0;
}