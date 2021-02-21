// 21.02.21. 일
// 16236: 아기 상어 https://www.acmicpc.net/problem/16236
// BFS, 우선순위큐 커스텀.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

namespace BOJ_16236
{
	struct Coord
	{
		int x;
		int y;

		friend Coord operator+(Coord& a, Coord& b)
		{
			return { a.x + b.x, a.y + b.y };
		}
	};

	struct cmp
	{
		bool operator()(Coord& a, Coord& b)
		{
			if (a.x == b.x)
				return a.y > b.y;
			else
				return a.x > b.x;
		}
	};

	int n, level = 2, count = 0, answer = 0;
	vector<vector<int> > fishBowl;
	Coord baby;

	bool IsRange(Coord& c)
	{
		return (c.x >= 0 && c.y >= 0 && c.x < n&& c.y < n);
	}

	int BFS()
	{
		Coord direction[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
		auto copyBowl = fishBowl;

		// 물고기 찾았을 때, 같은 거리에 다른 물고기 있는지 찾음.
		priority_queue<Coord, vector<Coord>, cmp> fishQ;
		bool bFinfFish = false;
		int resultWalk = 0;

		queue<pair<Coord, int> > q;
		q.push({ baby, 0 });
		copyBowl[baby.x][baby.y] = 1e9;

		while (!q.empty())
		{
			Coord now = q.front().first;
			int walk = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				Coord next = now + direction[i];
				if (!IsRange(next)) continue;
				if (copyBowl[next.x][next.y] > level) continue;
				if (copyBowl[next.x][next.y] < level && copyBowl[next.x][next.y] > 0)
				{
					if (!bFinfFish)
					{
						bFinfFish = true;
						resultWalk = walk + 1;
					}
					if (walk + 1 == resultWalk)
						fishQ.push(next);
					break;
				}
				if (!bFinfFish)
				{
					copyBowl[next.x][next.y] = 1e9;
					q.push({ next, walk + 1 });
				}
			}
		}
		if (bFinfFish)
		{
			Coord choice = fishQ.top();
			fishBowl[choice.x][choice.y] = 0;
			baby = choice;
			count++;
			return resultWalk;
		}
		return -1;
	}

	void Solution()
	{
		// input.
		cin >> n;
		fishBowl.assign(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> fishBowl[i][j];
				if (fishBowl[i][j] == 9)
				{
					baby = { i, j };
					fishBowl[i][j] = 0;
				}
			}
		}

		// bfs.
		while (1)
		{
			int res = BFS();
			if (res == -1) break;
			answer += res;
			if (level == count)
			{
				count = 0;
				level++;
			}
		}

		// output.
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_16236::Solution();

	return 0;
}