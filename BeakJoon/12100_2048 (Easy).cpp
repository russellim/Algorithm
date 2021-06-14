// 21.06.14. 월
// 12100: 2048 (Easy) https://www.acmicpc.net/problem/12100
// 백트래킹, 구현.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_12100
{
	constexpr int MAX = 5;
	int n, answer = 0;
	bool findEnd = false;

	void PrintPann(vector<vector<int> >& pann)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << pann[i][j] << " ";
			}
			cout << endl;
		}
	}

	// 판 기울어서 합치기.
	void NextPann(vector<vector<int> >& pann)
	{
		vector<vector<bool> > combi(n, vector<bool>(n, false)); // 합쳐진 위치.
		int r, c;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				r = i, c = j;
				while (c > 0)
				{
					if (pann[r][c - 1] == 0) // 다음칸이 빈칸일때.
					{
						pann[r][c - 1] += pann[r][c];
						pann[r][c] = 0;
						--c;
					}
					else if (pann[r][c - 1] == pann[r][c] && !combi[r][c - 1]) // 다음칸에 합칠수 있을때
					{
						pann[r][c - 1] += pann[r][c];
						pann[r][c] = 0;
						combi[r][c - 1] = true;
						break;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	
	// 판 회전하기.
	// 판 기울이기를 한방향만 만들기 위해.
	void TurnPann(vector<vector<int> >& pann, int count)
	{
		auto res = pann;
		while (count--)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					res[j][n - i - 1] = pann[i][j];
				}
			}
			pann = res;
		}
	}
	// 기울인거 되돌린다.
	void TurnBackPann(vector<vector<int> >& pann, int count)
	{
		auto res = pann;
		while (count--)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					res[n - j - 1][i] = pann[i][j];
				}
			}
			pann = res;
		}
	}

	void Game(int count, vector<vector<int> > pann, int turn)
	{
		if (count == MAX)
		{
			int block = 0;
			for (auto& x : pann)
			{
				for (int& y : x)
				{
					if (y == 0) continue;
					++block;
					answer = max(answer, y);
				}
			}
			if (block == 1) findEnd = true; // 블록 하나남으면 그냥 끝냄.
			return;
		}

		vector<vector<int> > next;
		for (int i = 0; i < 4; ++i)
		{
			if (findEnd) return;
			next = pann;

			TurnPann(next, i);
			NextPann(next);
			TurnBackPann(next, i);

			Game(count + 1, next, i);
		}
	}

	void Solution()
	{
		cin >> n;
		vector<vector<int> > pann(n, vector<int>(n));
		for (auto& x : pann) for (int& y : x) cin >> y;

		Game(0, pann, -1);

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_12100::Solution();

	return 0;
}