// 21.02.09. 화
// 1520: 내리막 길 https://www.acmicpc.net/problem/1520
// DP.

// failed
#include <iostream>
#include <vector>

using namespace std;

namespace Solution
{
	int m, n;
	vector<vector<int> > mapp, dp;

	bool IsRange(int i, int j)
	{
		return (i >= 0 && j >= 0 && i < m && j < n);
	}

	void Search(int i, int j)
	{
		int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
		for (int k = 0; k < 4; ++k)
		{
			int searchi = i + direction[k][0];
			int searchj = j + direction[k][1];
			if (!IsRange(searchi, searchj)) continue;
			//DP
		}
	}

	void dpcal()
	{
		int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == 0 && j == 0) continue;
				Search(i, j);
			}
		}
	}

	void Output()
	{
		cout << dp[m - 1][n - 1];
	}
	void Input()
	{
		cin >> m >> n;
		mapp.assign(m, vector<int>(n));
		dp.assign(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> mapp[i][j];
			}
		}
		dp[0][0] = 1;
	}
}

int main()
{
	Solution::Input();
	Solution::dpcal();
	Solution::Output();
}