// 21.02.20. 토
// 17626: Four Squares https://www.acmicpc.net/problem/17626
// DP.
// 2294: 동전 2 같이 풀었습니다. (제곱들은 동전단위, n은 총 액수)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_17626
{
	void Solution()
	{
		int n;
		cin >> n;
		vector<int> dp(n + 1, 1e9), store;
		for (int i = 1; ; ++i)
		{
			if (i * i > n) break;
			store.emplace_back(i * i);
		}
		dp[0] = 0;
		for (int number = 1; number <= n; ++number)
		{
			for (int j = 0; j < store.size(); ++j)
			{
				if (number - store[j] >= 0)
				{
					dp[number] = min(dp[number], dp[number - store[j]] + 1);
				}
			}
		}

		// output.
		cout << dp[n];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_17626::Solution();

	return 0;
}