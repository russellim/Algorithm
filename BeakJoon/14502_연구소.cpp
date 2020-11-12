// 20.11.12. 목
// 14502: 연구소 https://www.acmicpc.net/problem/14502
// dfs
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 9
int ZeroCnt, maxZero;
int n, m;
queue<pair<int, int> > BaseQ;
int mp[MAX][MAX], temp[MAX][MAX];
int direction[4][2] = { {1,0}, {0,1}, {-1,0}, {0, -1} };

bool isInRange(int row, int col)
{
	return (row >= 0 && row < n) && (col >= 0 && col < m);
}

void bfs(int& zero)
{
	int afterWall[MAX][MAX];
	memcpy(afterWall, temp, sizeof(temp));
	int zC = zero;
	queue<pair<int, int> > q = BaseQ;

	while (!q.empty())
	{
		int currentN = q.front().first;
		int currentM = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextN = currentN + direction[i][0];
			int nextM = currentM + direction[i][1];

			if (isInRange(nextN, nextM) && afterWall[nextN][nextM] == 0)
			{
				afterWall[nextN][nextM] = 2;
				zC--;
				q.push({ nextN, nextM });
			}
		}
	}
	maxZero = max(maxZero, zC);
}

void makeWall(int count, int& zero)
{
	if (count == 3)	// 3개 벽 세워짐.
	{
		bfs(zero);
		return;
	}
	// 비어있는 곳 중 벽 세움.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (temp[i][j] == 0)
			{
				temp[i][j] = 1;
				zero--;
				makeWall(count + 1, zero);
				temp[i][j] = 0;
				zero++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mp[i][j];
			if (mp[i][j] == 0) ZeroCnt++;
			else if (mp[i][j] == 2) BaseQ.push({ i, j });
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mp[i][j] == 0)
			{
				memcpy(temp, mp, sizeof(mp));
				temp[i][j] = 1;
				ZeroCnt--;
				makeWall(1, ZeroCnt);
				temp[i][j] = 0;
				ZeroCnt++;
			}
		}
	}
	cout << maxZero;

	return 0;
}