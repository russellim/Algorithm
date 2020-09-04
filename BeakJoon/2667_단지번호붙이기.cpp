// 20.09.04 금
// 2667: 단지번호붙이기 https://www.acmicpc.net/problem/2667
// BFS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int square[27][27];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%1d", &square[i][j]);
		}
	}

	int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	queue<pair<int, int>> q;
	pair<int, int> cur;
	vector<int> countvec;

	int ii = 0, jj = 0;
	int count = 0;
	while (true)
	{
		// 시작점 찾기.
		bool startok = false;
		for (int i = ii; i < n; ++i)
		{
			for (int j = jj; j < n; ++j)
			{
				if (square[i][j] == 1)
				{
					ii = i; jj = j;
					q.push(make_pair(i, j));
					startok = true;
					count++;
					countvec.push_back(1);
					square[i][j] = 0;
					break;
				}
			}
			if (startok) break;
			jj = 0;
		}

		if (!startok) break;

		// BFS.
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = cur.first + direction[i][0];
				int ny = cur.second + direction[i][1];
				if (nx >= 0 && ny >= 0 && nx < n && ny < n && square[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny));
					countvec[count - 1]++;
					square[nx][ny] = 0;
				}
			}
		}
	}

	if (!countvec.empty())
	{
		sort(countvec.begin(), countvec.end());
	}
	cout << count << "\n";
	for (int i = 0; i < countvec.size(); ++i)
	{
		cout << countvec[i] << "\n";
	}
}