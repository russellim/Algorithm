// 20.11.30. 월
// 1018: 체스판 다시 칠하기 https://www.acmicpc.net/problem/1018
// 브루트포스
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char> > copyBoard;
int answer = 1e9;

// 시작점부터 8x8만 검사.
void CheckBoard(int iStart, int jStart)
{
	int wb = 0, bw = 0;
	for (int i = iStart; i < 8 + iStart; ++i)
	{
		for (int j = jStart; j < 8 + jStart; ++j)
		{
			if ((i + j) % 2 == 0)
			{
				if (copyBoard[i][j] == 'W') wb++;
				else bw++;
			}
			else
			{
				if (copyBoard[i][j] == 'B') wb++;
				else bw++;
			}
		}
	}
	answer = min({ answer, wb, bw });
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, wb = 0, bw = 0;
	cin >> n >> m;
	vector<vector<char> > board(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i <= n - 8; ++i)
	{
		for (int j = 0; j <= m - 8; ++j)
		{
			copyBoard = board;
			CheckBoard(i, j);
		}
	}

	cout << answer;

	return 0;
}