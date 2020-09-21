// 20.09.21 월
// 1012: 유기농 배추 https://www.acmicpc.net/problem/1012
// BFS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int t;
	cin >> t;
	while (t > 0)
	{
		t--;
		int m, n, k, x, y, worm = 0;
		cin >> m >> n >> k;
		vector<vector<int>> farm(m, vector<int>(n, 0));
		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			farm[x][y] = 1;
		}

		queue<pair<int, int>> q;
		pair<int, int> cur;
		int direct[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

		while (1)
		{
			// 시작점 찾기.
			int ii = 0, jj = 0;
			bool findStart = false;
			for (int i = ii; i < m; ++i)
			{
				for (int j = jj; j < n; ++j)
				{
					if (farm[i][j] == 1)
					{
						findStart = true;
						ii = i; jj = j;	// 다시 시작점 찾을때 여기부터.
						farm[i][j] = 0;
						q.push(make_pair(i, j));
						worm++;	// 벌레!
						break;
					}
				}
				if (findStart) break;
			}

			// 시작점 못찾았으면 (= 다찾아서 없음) 끝!
			if (!findStart) break;

			while (!q.empty())
			{
				cur = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int dx = cur.first + direct[i][0];
					int dy = cur.second + direct[i][1];
					if (dx >= 0 && dy >= 0 && dx < m && dy < n && farm[dx][dy] == 1)
					{
						farm[dx][dy] = 0;
						q.push(make_pair(dx, dy));
					}
				}
			}
		}
		cout << worm << "\n";
	}

	return 0;
}