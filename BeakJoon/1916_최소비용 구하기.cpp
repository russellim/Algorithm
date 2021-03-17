// 21.03.17. 수
// 1916: 최소비용 구하기 https://www.acmicpc.net/problem/1916
// 다익스트라.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

namespace BOJ_1916
{
	struct Dest
	{
		int cost, from;
	};

	// 다익스트라.
	int GetMinCost(int& n, vector<vector<Dest> >& dest, int start, int end)
	{
		priority_queue<pair<int, int>> pq;
		vector<int> minCost(n + 1, INT_MAX);
		minCost[start] = 0;
		pq.push({ 0, start });

		while (!pq.empty())
		{
			int nowCost = pq.top().first;
			int nowPos = pq.top().second;
			pq.pop();
			for (int i = 0; i < dest[nowPos].size(); ++i)
			{
				int nextCost = dest[nowPos][i].cost;
				int nextPos = dest[nowPos][i].from;
				if (nowCost + nextCost >= minCost[nextPos]) continue;
				minCost[nextPos] = nowCost + nextCost;
				pq.push({ minCost[nextPos] , nextPos });
			}
		}

		return minCost[end];
	}

	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<vector<Dest> > dest(n + 1, vector<Dest>());
		for (int i = 0; i < m; ++i)
		{
			int to, from, cost;
			cin >> to >> from >> cost;
			dest[to].push_back({ cost, from });
		}
		int start, end;
		cin >> start >> end;
		cout << GetMinCost(n, dest, start, end);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1916::Solution();

	return 0;
}