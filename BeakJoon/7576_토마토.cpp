// 20.09.15 월
// 7576: 토마토 https://www.acmicpc.net/problem/7576
// BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, m;
	cin >> m;
	cin >> n;
	vector<vector<int>>box(n, vector<int>(m, 0));
	queue<pair<int, int>> one;
	int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	int zero = 0;
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> box[i][j];
			if (box[i][j] == 0) zero++;
			else if (box[i][j] == 1)
			{
				one.push(make_pair(i, j));
			}
		}
	}

	pair<int, int> now;
	queue<pair<int, int>> temp;
	while (!one.empty())
	{
		now = one.front();
		one.pop();
		for (int i = 0; i < 4; ++i)
		{
			int tx = now.first + direct[i][0];
			int ty = now.second + direct[i][1];
			if (tx >= 0 && ty >= 0 && tx < n && ty < m && box[tx][ty] == 0)
			{
				box[tx][ty] = 1;
				temp.push(make_pair(tx, ty));
				zero--;
			}
		}
		if (one.empty() && !temp.empty())
		{
			one = temp;
			queue<pair<int, int>> empty;
			swap(temp, empty);
			count++;
		}
	}

	if (zero != 0) cout << "-1";
	else cout << count;

	return 0;
}