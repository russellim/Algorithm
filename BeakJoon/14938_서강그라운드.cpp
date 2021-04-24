// 21.04.14. 수
// 14938: 서강그라운드 https://www.acmicpc.net/problem/14938
// BFS.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

namespace BOJ_14938
{
	struct Dest { int destination, cost; };

	int FindRoute(int n, int m, vector<vector<Dest> >& route, vector<int>& items, int start)
	{
		int res = items[start];
		vector<bool> visit(n + 1, false);
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
		q.push({ 0, start });
		visit[start] = true;

		while (!q.empty())
		{
			int nowPos = q.top().second;
			int nowCost = q.top().first;
			q.pop();
			for (int i = 0; i < route[nowPos].size(); ++i)
			{
				int nextCost = route[nowPos][i].cost + nowCost;
				int nextPos = route[nowPos][i].destination;
				if (m < nextCost) continue;
				if (!visit[nextPos])
				{
					visit[nextPos] = true;
					res += items[nextPos];
				}
				q.push({ nextCost, nextPos });
			}
		}
		return res;
	}

	void Solution()
	{
		int n, m, r, answer = 0;
		cin >> n >> m >> r;
		vector<int> items(n + 1);
		vector<vector<Dest> >route(n + 1, vector<Dest>());
		for (int i = 1; i <= n; ++i)
		{
			cin >> items[i];
		}
		for (int i = 0; i < r; ++i)
		{
			int a, b, L;
			cin >> a >> b >> L;
			route[a].push_back({ b, L });
			route[b].push_back({ a, L });
		}

		for (int i = 1; i <= n; ++i)
		{
			answer = max(answer, FindRoute(n, m, route, items, i));
		}
		cout << answer;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_14938::Solution();

	return 0;
}