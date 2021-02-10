// 21.02.10. 수
// 1520: 내리막 길 https://www.acmicpc.net/problem/1520
// 우선순위 큐 BFS.

// 우선순위 큐에 {맵의 숫자, 위치} 넣음. 이미 큐에 올라간 위치를 탐색하면 큐에 올리지 않고 카운트만 올려줌.
// dp보다는 느리지만 우선순위큐 짱.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace Solution
{
	typedef pair<int, int> Coord;
	int m, n;
	vector<vector<int> > mapp, countMap;

	bool IsRange(int i, int j)
	{
		return (i >= 0 && j >= 0 && i < m && j < n);
	}

	void Search()
	{
		int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
		priority_queue<pair<int, Coord> > q, tempq, emptyq;
		q.push({ mapp[0][0], { 0,0 } });

		while (!q.empty())
		{
			int nowNum = q.top().first;
			Coord nowPos = q.top().second;
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				Coord nextPos = { nowPos.first + direction[k][0], nowPos.second + direction[k][1] };
				if (!IsRange(nextPos.first, nextPos.second)) continue;

				int nextNum = mapp[nextPos.first][nextPos.second];
				if (mapp[nowPos.first][nowPos.second] > nextNum)
				{
					bool IsFind = false;
					while (!q.empty())
					{
						if (q.top().second == nextPos) IsFind = true;
						tempq.push(q.top());
						q.pop();
					}
					q = tempq;
					tempq = emptyq;

					countMap[nextPos.first][nextPos.second] += countMap[nowPos.first][nowPos.second];
					if (!IsFind)
					{
						q.push({ nextNum, nextPos });
					}
				}
			}
		}
	}

	void Output()
	{
		cout << countMap[m - 1][n - 1];
	}
	void Input()
	{
		cin >> m >> n;
		mapp.assign(m, vector<int>(n));
		countMap.assign(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> mapp[i][j];
			}
		}
		countMap[0][0] = 1;
	}
}

int main()
{
	Solution::Input();
	Solution::Search();
	Solution::Output();
}