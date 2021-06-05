// 21.06.05. 토
// 5582: 공통 부분 문자열 https://www.acmicpc.net/problem/5582
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_5582
{
	void Solution()
	{
		int answer = 0;
		string a, b;
		cin >> a >> b;
		vector<vector<int> > dp(b.size() + 1, vector<int>(a.size() + 1, 0));

		for (int i = 1; i <= b.size(); ++i)
		{
			for (int j = 1; j <= a.size(); ++j)
			{
				// 연속돼야함!.
				if (a[j - 1] == b[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				answer = max(answer, dp[i][j]);
			}
		}

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_5582::Solution();

	return 0;
}