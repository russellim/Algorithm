// 21.02.16. 화
// 2630: 색종이 만들기 https://www.acmicpc.net/problem/2630
// 분할정복
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_2630
{
	int n;
	vector<vector<int> > paper;
	int color[2];

	void Divide(int size, int starti, int startj);

	void CheckColor(int size, int starti, int startj)
	{
		int FirstColor = paper[starti][startj];
		for (int i = starti; i < starti + size; ++i)
		{
			for (int j = startj; j < startj + size; ++j)
			{
				if (FirstColor != paper[i][j])
				{
					Divide(size, starti, startj);
					return;
				}
			}
		}
		color[FirstColor]++;
	}

	void Divide(int size, int starti, int startj)
	{
		int half = size / 2;
		CheckColor(half, starti, startj);
		CheckColor(half, starti, startj + half);
		CheckColor(half, starti + half, startj);
		CheckColor(half, starti + half, startj + half);
	}

	void Input()
	{
		cin >> n;
		paper.assign(n, vector<int>(n));
		bool IsAllSameColor = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> paper[i][j];
				if (paper[0][0] != paper[i][j]) IsAllSameColor = false;
			}
		}
		if (!IsAllSameColor) Divide(n, 0, 0);
		else color[paper[0][0]]++;
	}

	void Output()
	{
		cout << color[0] << "\n" << color[1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2630::Input();
	BOJ_2630::Output();

	return 0;
}