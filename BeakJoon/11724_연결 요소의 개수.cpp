// 20.11.09. 월
// 11724: 연결 요소의 개수 https://www.acmicpc.net/problem/11724
// BFS.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int answer = 0;
	int n, m;
	cin >> n >> m;
	vector<bool> visit(n + 1, false);
	vector<vector<int> > link(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		link[u][v] = link[v][u] = 1;
	}

	while (1)
	{
		queue<int> q;
		int start = 1;
		for (int i = 1; i < n + 1; ++i)
		{
			if (!visit[i])
			{
				start = i;
				break;
			}
		}
		if (visit[start]) break;

		answer++;
		visit[start] = true;

		for (int i = 1; i < n + 1; ++i)
		{
			if (link[start][i] == 1)
			{
				q.push(i);
				link[start][i] = link[i][start] = 0;
			}
		}

		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			visit[temp] = true;
			for (int i = 1; i < n + 1; ++i)
			{
				if (link[temp][i] == 1 && !visit[i])
				{
					q.push(i);
					link[temp][i] = link[i][temp] = 0;
				}
			}
		}

	}
	cout << answer;

	return 0;
}