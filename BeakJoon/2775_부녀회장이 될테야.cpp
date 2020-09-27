// 20.09.27 일
// 2775: 부녀회장이 될테야 https://www.acmicpc.net/problem/2775
// DP
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int k, n;
		cin >> k >> n;
		vector<vector<int>> zf(k+1, vector<int>(n + 1));
		for (int i = 1; i <= n; ++i)
		{
			zf[0][i] = i;
		}
		for (int i = 1; i <= k; ++i)
		{
			zf[i][1] = 1;
		}

		for (int i = 1; i <= k; ++i)
		{
			for (int j = 2; j <= n; ++j)
			{
				zf[i][j] = zf[i][j - 1] + zf[i - 1][j];
			}
		}

		cout << zf[k][n] << "\n";
	}

	return 0;
}