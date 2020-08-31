// 20.08.30 SUN
// 1260: DFS와 BFS https://www.acmicpc.net/problem/1260
// DFS, BFS

#include <iostream>
#include <queue>
using namespace std;

#define MAX_VALUE 1001	// 정점의 최대 갯수 (문제 지정).
int n, m, v;
int mat[MAX_VALUE][MAX_VALUE];
int visit[MAX_VALUE];

void dfs(int v)
{
	cout << v << " ";
	visit[v] = 1;	//방문한 노드 0 -> 1.
	for (int i = 1; i <= n; ++i)
	{
		if (visit[i] == 1 || mat[v][i] == 0)
		{
			// 방문했거나, 연결돼있지 않으면,
			continue;
		}
		dfs(i);
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visit[v] = 0;	//방문한 노드 1 -> 0.
	while (!q.empty())
	{
		v = q.front();	// 정점 지정.
		cout << v << " ";
		q.pop();
		// 정점 v에서 연결된애 다 검사.
		for (int i = 1; i <= n; ++i)
		{
			if (visit[i] == 0 || mat[v][i] == 0)
			{
				continue;
			}
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int a, b;
	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		mat[a][b] = mat[b][a] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs(v);
}