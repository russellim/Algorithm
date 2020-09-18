// 20.09.18 금
// 2606: 바이러스 https://www.acmicpc.net/problem/2606
// DFS
#include <iostream>
using namespace std;

#define MAX 101
int n, m;
int mat[MAX][MAX];
bool visit[MAX];

void dfs(int v)
{
	visit[v] = true;
	for (int i = 1; i <= n; ++i)
	{
		// 방문했거나, 연결 ㄴㄴ -> 다음꺼 탐색.
		if (visit[i] == true || mat[v][i] == 0)
			continue;
		dfs(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		mat[a][b] = mat[b][a] = 1;
	}

	dfs(1);

	// 처음 시작인 1번은 빼니까 -1.
	int sum = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (visit[i]) sum++;
	}
	cout << sum;

	return 0;
}