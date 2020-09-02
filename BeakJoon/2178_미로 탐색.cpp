// 20.09.01 TUE
// 2178: 미로 탐색 https://www.acmicpc.net/problem/2178
// BFS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cout.tie(NULL); cin.tie(NULL);
	//scanf를 사용하니까 쓰면안돼.

	int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
	int n, m;
	cin >> n >> m;

	int maze[101][101];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	pair<int, int> cur;
	int nx, ny;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			nx = cur.second + direct[i][0];
			ny = cur.first + direct[i][1];
			if (!(nx == 0 && ny == 0) && nx >= 0 && nx < m && ny >= 0 && ny < n && maze[ny][nx] == 1)
			{
				q.push(make_pair(ny, nx));
				maze[ny][nx] = maze[cur.first][cur.second] + 1;
			}
		}
	}

	cout << maze[n - 1][m - 1];
}