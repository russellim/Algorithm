// 21.04.28. 수
// 1167: 트리의 지름 https://www.acmicpc.net/problem/1167
// BFS, 트리.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

namespace BOJ_1167
{
	struct Conn { int from, cost; };
	int v;
	vector<vector<Conn> > conn;

	// 제일 먼 거리 구하기.
	// {노드번호, 거리} 반환.
	pair<int, int> bfs(int start)
	{
		int resCost = 0, endNode;
		vector<bool> visit(v + 1, false);
		queue<pair<int, int> > q;
		q.push({ start, 0 });
		visit[start] = true;

		while (!q.empty())
		{
			int nowPos = q.front().first;
			int nowCost = q.front().second;
			q.pop();

			for (int i = 0; i < conn[nowPos].size(); ++i)
			{
				int nextPos = conn[nowPos][i].from;
				if (visit[nextPos]) continue;

				int nextCost = conn[nowPos][i].cost + nowCost;

				q.push({ nextPos, nextCost });
				visit[nextPos] = true;
				resCost = max(resCost, nextCost);
				if (resCost == nextCost) endNode = nextPos;
			}
		}

		return { endNode, resCost };
	}

	void Solution()
	{
		// input.
		int answer = 0;
		cin >> v;
		conn.assign(v + 1, vector<Conn>());

		int vCount = v;
		while (vCount--)
		{
			int node;
			cin >> node;
			while (1)
			{
				int from, cost;
				cin >> from;
				if (from == -1) break;
				cin >> cost;
				conn[node].push_back({ from, cost });
			}
		}

		// logic.
		// 1. 아무 노드 하나를 잡고 거기서 제일 먼 노드를 구하기.
		// 2. 그 노드에서 제일 먼 거리 구하면 끝! (쌍당히 멋있다).
		int farNode = bfs(1).first;
		answer = bfs(farNode).second;

		// output.
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1167::Solution();

	return 0;
}
