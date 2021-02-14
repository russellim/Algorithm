// 21.02.14. 일
// 18111: 마인크래프트 https://www.acmicpc.net/problem/18111
// 브루트포스, 구현.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

namespace Minecraft
{
	int N, M, B;
	int time, height;
	vector<vector<int> > ground;
	int hmax, hmin;

	void MatchHeight(int h)
	{
		int copyB = B;
		int timeTmp = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				int diff = ground[i][j] - h;
				copyB += diff;

				if (diff > 0) timeTmp += (2 * diff);	//블록 제거.
				else if (diff < 0) timeTmp += abs(diff);//블록 생성.
			}
		}
		if (copyB < 0) return;	// 최종적으로 B가 음수이면 이번 경우 제외.

		if (timeTmp < time)
		{
			time = timeTmp;
			height = h;
		}
	}

	void Solution()
	{
		// 제일 높은 땅 ~> 제일 낮은 땅.
		for (int i = hmax; i >= hmin; --i)
		{
			MatchHeight(i);
		}
	}

	void Input()
	{
		cin >> N >> M >> B;
		ground.assign(N, vector<int>(M));
		hmax = 0, hmin = time = 1e9;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> ground[i][j];
				hmin = min(hmin, ground[i][j]);
				hmax = max(hmax, ground[i][j]);
			}
		}
	}
	void Output()
	{
		cout << time << " " << height;
	}
}

int main()
{
	Minecraft::Input();
	Minecraft::Solution();
	Minecraft::Output();

	return 0;
}


/*
3 4 66
1 2 3 4
6 5 7 8
9 10 11 12

> 48 9
*/