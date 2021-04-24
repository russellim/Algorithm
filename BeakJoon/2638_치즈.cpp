// 21.04.09. 금
// 2638: 치즈 https://www.acmicpc.net/problem/2638
// BFS.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace BOJ_2638
{
	struct Coord
	{
		int x, y;
		friend Coord operator+(Coord& a, Coord& b)
		{
			return { a.x + b.x, a.y + b.y };
		}
	};
	constexpr int EMPTY = 0;
	constexpr int CHEESE = 1;
	constexpr int AIR = 2;
	constexpr int DIR = 4;
	int n, m;
	vector<vector<int> >paper;
	vector<Coord> cheese;
	Coord direction[DIR] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

	bool IsRange(Coord& pos)
	{
		return (pos.x >= 0 && pos.y >= 0 && pos.x < n&& pos.y < m);
	}

	void SetExternalAir(int x, int y)
	{
		queue<Coord> q;
		q.push({ x, y });
		paper[x][y] = AIR;

		while (!q.empty())
		{
			Coord now = q.front();
			q.pop();
			for (int i = 0; i < DIR; ++i)
			{
				Coord next = now + direction[i];
				if (!IsRange(next)) continue;
				if (paper[next.x][next.y] == EMPTY)
				{
					paper[next.x][next.y] = AIR;
					q.push(next);
				}
			}
		}
	}

	bool IsExternalCheese(Coord& nowCheese)
	{
		int emptyCount = 0;
		for (int i = 0; i < DIR; ++i)
		{
			auto AroundPos = nowCheese + direction[i];
			if (paper[AroundPos.x][AroundPos.y] == AIR)
			{
				emptyCount++;
				if (emptyCount == 2) return true;
			}
		}
		return false;
	}

	void EraseCheese(vector<int>& externalCheeseIndex)
	{
		for (int i = externalCheeseIndex.size() - 1; i >= 0; --i)
		{
			int index = externalCheeseIndex[i];
			SetExternalAir(cheese[index].x, cheese[index].y);
			cheese.erase(cheese.begin() + index);
		}
	}

	void SearchCheese()
	{
		vector<int> externalCheeseIndex;
		for (int i = 0; i < cheese.size(); ++i)
		{
			if (!IsExternalCheese(cheese[i])) continue;

			externalCheeseIndex.push_back(i);
		}

		EraseCheese(externalCheeseIndex);
	}

	void Solution()
	{
		int answer = 0;
		// input.
		cin >> n >> m;
		paper.assign(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> paper[i][j];
				if (paper[i][j] == CHEESE) cheese.push_back({ i, j });
			}
		}

		// logic.
		SetExternalAir(0, 0);

		while (!cheese.empty())
		{
			SearchCheese();
			answer++;
		}

		// output.
		cout << answer;

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2638::Solution();

	return 0;
}