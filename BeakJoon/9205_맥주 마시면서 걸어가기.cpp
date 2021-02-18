// 21.02.18. 목
// 9205: 맥주 마시면서 걸어가기 https://www.acmicpc.net/problem/9205
// BFS.
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

namespace BOJ_9205
{
#define DRINKLIMIT 1000
	struct Coord
	{
		int x;
		int y;
	};

	int Distance(Coord& a, Coord& b)
	{
		return abs(a.x - b.x) + abs(a.y - b.y);
	}

	void BFS(vector<Coord>& mapp, int size)
	{
		if (Distance(mapp[0], mapp[size - 1]) <= DRINKLIMIT)
		{
			cout << "happy\n";
			return;
		}
		bool visit[102]{ false };
		queue<Coord> q;
		q.push(mapp[0]);
		visit[0] = true;

		while (!q.empty())
		{
			Coord now = q.front();
			q.pop();

			for (int i = 0; i < size; ++i)
			{
				if (visit[i]) continue;
				if (Distance(now, mapp[i]) <= DRINKLIMIT)
				{
					if (i == size - 1)
					{
						cout << "happy\n";
						return;
					}
					visit[i] = true;
					q.push(mapp[i]);
				}
			}
		}
		cout << "sad\n";
	}

	void Solution()
	{
		int t;
		cin >> t;
		while (t--)
		{
			int n, x, y;
			cin >> n;
			vector<Coord> mapp(n + 2);
			for (int i = 0; i < n + 2; ++i)
			{
				cin >> x >> y;
				mapp[i] = { x, y };
			}
			BFS(mapp, n + 2);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_9205::Solution();

	return 0;
}