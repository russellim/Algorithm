// 20.12.17. 목
// 4963: 섬의 개수 https://www.acmicpc.net/problem/4963
// BFS.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int> > M;
typedef pair<int, int> P;
int w, h;

bool CheckRange(int nextx, int nexty)
{
	if (nextx >= 0 && nexty >= 0 && nextx < h && nexty < w) return true;
	return false;
}

P FindGround(M& m, int i, int j)
{
	for (i; i < h; ++i)
	{
		for (j; j < w; ++j)
		{
			if (m[i][j] == 1)
			{
				m[i][j] = 0;
				return { i, j };
			}
		}
		j = 0;
	}
	return { -1, -1 };
}

void MakeMap(M& m)
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> m[i][j];
		}
	}
}

void BFS(M& m, P& startPoint)
{
	int direction[8][2] = { {1,0},{-1,0},{1,1}, {-1,-1}, {0, 1}, {0, -1}, {1, -1}, {-1, 1} };
	queue<P> q;
	q.push({ startPoint.first, startPoint.second });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nextx = x + direction[i][0];
			int nexty = y + direction[i][1];
			if (CheckRange(nextx, nexty) && m[nextx][nexty] == 1)
			{
				q.push({ nextx, nexty });
				m[nextx][nexty] = 0;
			}
		}
	}
}

void FindIsland()
{
	int answer = 0;
	M mapp(h, vector<int>(w));
	MakeMap(mapp);
	P startPoint = { 0, 0 };
	while (1)
	{
		startPoint = FindGround(mapp, startPoint.first, startPoint.second);
		if (startPoint.first == -1) break;
		answer++;
		BFS(mapp, startPoint);
	}
	cout << answer << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		FindIsland();
	}

	return 0;
}