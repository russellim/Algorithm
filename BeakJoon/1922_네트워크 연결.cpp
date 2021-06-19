// 21.06.19. 토
// 1922: 네트워크 연결 https://www.acmicpc.net/problem/1922
// MST.

// failed.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

namespace BOJ_14226
{
	struct Conn { int from, cost; };
	vector<vector<Conn> > conn;
	vector<int> parent;

	int FindParent(int child)
	{
		if (child = parent[child]) return child;
		return parent[child] = FindParent(parent[child]);
	}

	bool IsCycle(int from, int to)
	{
		from = FindParent(from);
		to = FindParent(to);

		if (from == to) return true;

		parent[from] = to;
		return false;
	}

	void Solution()
	{
		int n, m;
		cin >> n >> m;
		conn.assign(n + 1, vector<Conn>());
		for (int i = 0; i < m; ++i)
		{
			int a, b, cost;
			cin >> a >> b >> cost;
			conn[a].push_back({ b, cost });
			conn[b].push_back({ a, cost });
		}
		parent.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			parent[i] = i;
		}

		int answer = 0;
		vector<bool> visit(n + 1, false);
		priority_queue<pair<int, int> > q;
		q.push({ 0, 1 });
		visit[1] = true;

		while (!q.empty())
		{
			int nowCost = q.top().first;
			int nowPos = q.top().second;
			q.pop();

			for (auto& next : conn[nowPos])
			{
				int nextPos = next.from;
				if (visit[nextPos]) continue;
				if (IsCycle(nowCost, nextPos)) continue;
				int nextCost = next.cost;
				visit[nextPos] = true;
				answer += nextCost;
				q.push({ nextCost, nextPos });
			}
		}

		cout << answer;
	}
}

int main()
{
	BOJ_14226::Solution();
										
	return 0;
}