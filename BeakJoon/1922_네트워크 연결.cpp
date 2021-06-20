// 21.06.19. 토
// 1922: 네트워크 연결 https://www.acmicpc.net/problem/1922
// MST(프림).

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

namespace BOJ_1922
{
	struct Conn { int from, cost; };
	vector<vector<Conn> > conn;

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

		int answer = 0;
		vector<bool> visit(n + 1, false);
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

		for (auto& x : conn[1])
		{
			q.push({ x.cost, x.from });
		}
		visit[1] = true;

		while (!q.empty())
		{
			int nowCost = q.top().first;
			int nowPos = q.top().second;
			q.pop();

			if (visit[nowPos]) continue;
			visit[nowPos] = true;
			answer += nowCost;

			for (auto& next : conn[nowPos])
			{
				q.push({ next.cost, next.from });
			}
		}

		cout << answer;
	}
}

int main()
{
	BOJ_1922::Solution();

	return 0;
}