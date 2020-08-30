// 20.08.30 SUN
// 1260: DFS와 BFS https://www.acmicpc.net/problem/1260
// DFS, BFS

#include <iostream>
using namespace std;

#define MAX_VALUE 1001
int n, m, v;
int mat[MAX_VALUE][MAX_VALUE];
int visit[MAX_VALUE];

void dfs(int v)
{
	cout << v << " ";
	visit[v] = 1; //방문한 노드.
	for (int i = 1; i <= n; ++i)
	{
		if (visit[i] == 1 || mat[v][i] == 0)
		{
			continue;
		}
		dfs(i);
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
	
}