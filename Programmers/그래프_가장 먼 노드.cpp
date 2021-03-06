// 21.03.06. 토
// 그래프_가장 먼 노드 https://programmers.co.kr/learn/courses/30/lessons/49189
// 그래프, BFS.
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > conn;
vector<int> dist;

void FindDistance()
{
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty())
	{
		int pos = q.front();;
		q.pop();
		for (int i = 0; i < conn[pos].size(); ++i)
		{
			int nextPos = conn[pos][i];
			if (dist[nextPos] <= dist[pos] + 1) continue;
			dist[nextPos] = dist[pos] + 1;
			q.push(nextPos);
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	conn.assign(n + 1, vector<int>());
	dist.assign(n + 1, 1e9);
	for (int i = 0; i < edge.size(); ++i)
	{
		conn[edge[i][0]].push_back(edge[i][1]);
		conn[edge[i][1]].push_back(edge[i][0]);
	}

	FindDistance();

	int far = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (far > dist[i]) continue;
		else if (far == dist[i]) answer++;
		else
		{
			far = dist[i];
			answer = 1;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution(6, { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });

	return 0;
}