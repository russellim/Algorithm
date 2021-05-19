// 21.05.19. 수
// 2239: 스도쿠 https://www.acmicpc.net/problem/2239
// 백트래킹.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_2239
{
	struct Coord { int x, y; };
	vector<vector<int> > pann;
	vector<Coord> empty;
	bool IsFull = false;

	bool CheckRow(int r, int num)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (pann[r][i] == num) return false;
		}
		return true;
	}
	bool CheckCol(int c, int num)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (pann[i][c] == num) return false;
		}
		return true;
	}
	bool CheckCube(Coord& coord, int num)
	{
		int sr = coord.x / 3 * 3;
		int sc = coord.y / 3 * 3;
		for (int i = sr; i < sr + 3; ++i)
		{
			for (int j = sc; j < sc + 3; ++j)
			{
				if (pann[i][j] == num) return false;
			}
		}
		return true;
	}

	void CheckNum(int emptyIndex)
	{
		if (emptyIndex == empty.size())
		{
			IsFull = true;
			return;
		}

		Coord now = empty[emptyIndex];
		for (int num = 1; num <= 9; ++num)
		{
			if (!(CheckRow(now.x, num) && CheckCol(now.y, num) && CheckCube(now, num))) continue;
			pann[now.x][now.y] = num;
			CheckNum(emptyIndex + 1);
			if (IsFull) return;
			pann[now.x][now.y] = 0;
		}
	}

	void Solution()
	{
		pann.assign(9, vector<int>(9, 0));
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				scanf("%1d", &pann[i][j]);
				if (pann[i][j] == 0) empty.push_back({ i, j });
			}
		}

		CheckNum(0);

		for (auto& x : pann)
		{
			for (int& y : x)
			{
				cout << y;
			}
			cout << "\n";
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	BOJ_2239::Solution();

	return 0;
}