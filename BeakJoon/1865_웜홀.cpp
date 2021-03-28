// 21.03.28. 일
// 1865: 웜홀 https://www.acmicpc.net/problem/1865
// 벨만포드 알고리즘.
// 음수 사이클이 하나라도 있으면 yes.
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_1865
{
	struct edge { int to, cost; };

	bool BellmanFord(int n, vector<vector<edge> >& edges)
	{
		vector<int> dist(n + 1, 0);	// 어디서든 시작할 수 있으니 INF아니고 0.

		// n-1번 돌리고 n번째에 새로 갱신되는지(음수사이클인지) 검사.
		for (int repeat = 1; repeat <= n; ++repeat)
		{
			for (int i = 1; i < edges.size(); ++i)
			{
				for (int j = 0; j < edges[i].size(); ++j)
				{
					int from = i;
					int to = edges[i][j].to;
					int cost = edges[i][j].cost;

					if (dist[to] > dist[from] + cost)
					{
						if (repeat == n) return true;
						dist[to] = dist[from] + cost;
					}
				}
			}
		}
		return false;
	}

	void Solution()
	{
		int tc;
		cin >> tc;
		while (tc--)
		{
			int n, m, w, s, e, t;
			cin >> n >> m >> w;
			vector<vector<edge> > edges(n + 1, vector<edge>());
			while (m--)
			{
				cin >> s >> e >> t;
				edges[s].push_back({ e, t });
				edges[e].push_back({ s, t });
			}
			while (w--)
			{
				cin >> s >> e >> t;
				edges[s].push_back({ e, -t });
			}

			cout << (BellmanFord(n, edges) ? "YES\n" : "NO\n");
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1865::Solution();

	return 0;
}