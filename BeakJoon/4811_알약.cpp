// 21.05.27. 목
// 4811: 알약 https://www.acmicpc.net/problem/4811
// DP.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_4811
{
	typedef long long LL;
	vector < vector < LL > > dp;
	LL GetDP(int w, int h)
	{
		if (w < 0) return 0;
		if (dp[w][h] > 0) return dp[w][h];
		if (w == 0 && h == 0) return 1;

		if (w > 0) dp[w][h] += GetDP(w - 1, h + 1);
		if (h > 0)dp[w][h] += GetDP(w, h - 1);

		return dp[w][h];
	}

	void Solution()
	{
		int num;
		dp.assign(31, vector<LL>(33, 0));
		while (1)
		{
			cin >> num;
			if (num == 0) return;
			cout << GetDP(num, 0) << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_4811::Solution();

	return 0;
}