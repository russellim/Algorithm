// 21.05.22. 토
// 15486: 퇴사 2 https://www.acmicpc.net/problem/15486
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_15486
{
	struct Job { int time, pay; };
	void Solution()
	{
		int n, answer = 0;
		cin >> n;
		vector<Job> job(n);
		for (auto& x : job)
			cin >> x.time >> x.pay;
		vector<int> dp(n + 1, 0);

		for (int i = 0; i < n; ++i)
		{
			if (i != 0 && dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
			int endNextDay = i + job[i].time;
			if (endNextDay > n) continue;
			dp[endNextDay] = max(dp[endNextDay], dp[i] + job[i].pay);
			answer = max(answer, dp[endNextDay]);
		}

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_15486::Solution();

	return 0;
}