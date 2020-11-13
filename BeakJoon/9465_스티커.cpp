// 20.11.13. 금
// 9465: 스티커 https://www.acmicpc.net/problem/9465
// DP
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		// n+1 인 이유: max(대각선 한개 or 두개 뛰어 넘었을때) 계산해야됨.
		// 왜 1, 2개만이냐! 3개 건너뛴거부터는 별 의미가 없음!.
		vector<vector<int> > post(2, vector<int>(n+1, 0));
		auto dp = post;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 1; j < n+1; ++j)
			{
				cin >> post[i][j];
			}
		}

		dp[0][1] = post[0][1];
		dp[1][1] = post[1][1];

		for (int j = 2; j < n + 1; ++j)
		{
			dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + post[0][j];
			dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + post[1][j];
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";
	}

	return 0;
}