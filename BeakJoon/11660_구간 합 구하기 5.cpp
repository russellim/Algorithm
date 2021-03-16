// 21.03.16. 화
// 11660: 구간 합 구하기 5 https://www.acmicpc.net/problem/11660
// DP, 누적합.
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_11660
{
	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int> > v(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> v[i][j];
				if (i == 0 && j == 0) continue;
				else if (i == 0) v[i][j] += v[i][j - 1];
				else if (j == 0) v[i][j] += v[i - 1][j];
				else v[i][j] += v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
			}
		}

		while (m--)
		{
			int x1, y1, x2, y2, sum = 0;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--; y1--; x2--; y2--;	// 문제는 (1, 1) 부터 시작해서 -1.
			if (x1 == 0 && y1 == 0)
			{
				cout << v[x2][y2] << "\n";
			}
			else if (x1 == 0)
			{
				cout << v[x2][y2] - v[x2][y1 - 1] << "\n";
			}
			else if (y1 == 0)
			{
				cout << v[x2][y2] - v[x1 - 1][y2] << "\n";
			}
			else
			{
				cout << v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1] << "\n";
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_11660::Solution();

	return 0;
}