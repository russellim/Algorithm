// 21.04.08. 목
// 9252: LCS 2 https://www.acmicpc.net/problem/9252
// DP, LCS.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_9252
{
	void Solution()
	{
		string a, b, answer;
		cin >> a >> b;
		int aSize = a.size(), bSize = b.size();

		// LCS.
		vector<vector<int> > dp(bSize + 1, vector<int>(aSize + 1, 0));
		for (int i = 1; i <= bSize; ++i)
		{
			for (int j = 1; j <= aSize; ++j)
			{
				if (b[i - 1] == a[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}

		// output 1.
		cout << dp[bSize][aSize];

		// 부분수열 뒤로 가면서 찾기.
		if (dp[bSize][aSize] != 0)
		{
			int i = bSize, j = aSize;
			while (i != 0 && j != 0)
			{
				if (b[i - 1] == a[j - 1])
				{
					answer = b[i - 1] + answer;
					--i; --j;
				}
				else
				{
					if (dp[i - 1][j] == dp[i][j]) --i;
					else --j;
				}
			}

			// output 2.
			cout << "\n" << answer;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_9252::Solution();

	return 0;
}