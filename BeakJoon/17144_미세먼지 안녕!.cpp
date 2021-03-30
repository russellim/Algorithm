// 21.03.25. 목
// 17144: 미세먼지 안녕! https://www.acmicpc.net/problem/17144
// 구현.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_17144
{
	struct Coord { int x, y; };
	typedef vector<vector<int> > vvi;
	constexpr int AIR_CLEANER = -1;
	constexpr int EMPTY_AREA = 0;
	constexpr int NEARBY_COUNT = 4;

	int r, c;
	int nearby[NEARBY_COUNT][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };
	vector<Coord> airCleanerPos;

	bool IsRange(int x, int y)
	{
		return (x >= 0 && y >= 0 && x < r&& y < c);
	}

	int CheckDiffusibleArea(vvi& area, vvi& diffuseDust, int& x, int& y, int div)
	{
		int count = 0;
		for (int i = 0; i < NEARBY_COUNT; ++i)
		{
			int newX = x + nearby[i][0], newY = y + nearby[i][1];
			if (!IsRange(newX, newY) || area[newX][newY] == AIR_CLEANER) continue;
			count++;
			diffuseDust[newX][newY] += div;
		}
		return count;
	}

	// 먼지 확산.
	void DiffuseDustArea(vvi& area, vvi& diffuseDust)
	{
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (area[i][j] == AIR_CLEANER || area[i][j] == EMPTY_AREA) continue;
				int div = area[i][j] / 5;
				int nearCount = CheckDiffusibleArea(area, diffuseDust, i, j, div);
				area[i][j] -= (div * nearCount);
			}
		}

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				area[i][j] += diffuseDust[i][j];
				diffuseDust[i][j] = 0;
			}
		}
	}

	// 공기청정기 작동.
	int WorkAirCleaner(vvi& area)
	{
		int DestroyDust = 0;
		int x = airCleanerPos[0].x, y = airCleanerPos[0].y;
		int prevDust = 0;
		// 위 작동.
		while (++y < c) swap(prevDust, area[x][y]);
		--y;
		while (--x >= 0) swap(prevDust, area[x][y]);
		++x;
		while (--y >= 0) swap(prevDust, area[x][y]);
		++y;
		while (++x < airCleanerPos[0].x) swap(prevDust, area[x][y]);
		DestroyDust += prevDust;

		x = airCleanerPos[1].x, y = airCleanerPos[1].y;
		prevDust = 0;
		// 아래 작동.
		while (++y < c) swap(prevDust, area[x][y]);
		--y;
		while (++x < r) swap(prevDust, area[x][y]);
		--x;
		while (--y >= 0) swap(prevDust, area[x][y]);
		++y;
		while (--x > airCleanerPos[1].x) swap(prevDust, area[x][y]);
		DestroyDust += prevDust;

		return DestroyDust;
	}

	void InputArea(vvi& area, int& AllofDust)
	{
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin >> area[i][j];
				if (area[i][j] == AIR_CLEANER)
					airCleanerPos.push_back({ i, j });
				AllofDust += area[i][j];
			}
		}
	}

	void Solution()
	{
		int t, answer = 2;	// 공기청정기 -1 * 2 제외.
		cin >> r >> c >> t;
		vvi area(r, vector<int>(c, 0));
		auto diffuseDust = area;
		InputArea(area, answer);

		while (t--)
		{
			DiffuseDustArea(area, diffuseDust);
			answer -= WorkAirCleaner(area);
		}

		// output.
		cout << answer;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_17144::Solution();

	return 0;
}