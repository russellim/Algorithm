// 21.04.05. 월
// 12852: 1로 만들기 2 https://www.acmicpc.net/problem/12852
// 1. 백트래킹(2016kb, 20ms) 2.DP(10020kb, 8ms)
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_12852_BackTracking
{
	vector<int> tempv, answer;
	int answerCount = 1e9;

	void MakeOne(int n, int count)
	{
		if (count >= answerCount) return;
		if (n == 1)
		{
			if (answerCount > count)
			{
				answerCount = count;
				answer = tempv;
			}
			return;
		}

		tempv.push_back(n);
		if (n % 3 == 0) MakeOne(n / 3, count + 1);
		if (n % 2 == 0) MakeOne(n / 2, count + 1);
		MakeOne(n - 1, count + 1);
		tempv.pop_back();
	}

	void Solution()
	{
		int n;
		cin >> n;
		MakeOne(n, 0);

		cout << answerCount << "\n";
		for (int x : answer) cout << x << " ";
		cout << "1";
	}
}

namespace BOJ_12852_DP
{
	constexpr int MAX = 1e9;

	void output(vector<int>& dp, vector<int>& next, int n)
	{
		cout << dp[n] << "\n";
		while (n != 0)
		{
			cout << n << " ";
			n = next[n];
		}
	}

	void Solution()
	{
		int n;
		cin >> n;
		vector<int> dp(n + 1, MAX);
		auto next = dp;
		dp[1] = next[1] = 0;
		for (int i = 1; i <= (int)sqrt(n); ++i)
		{
			int num = (int)pow(3, i);
			if (num > n) break;
			dp[num] = i;
			next[num] = (int)pow(3, i - 1);
			if (num == n)
			{
				output(dp, next, n);
				return;
			}
		}
		for (int i = 1; i <= (int)sqrt(n); ++i)
		{
			int num = (int)pow(2, i);
			if (num > n) break;
			dp[num] = i;
			next[num] = (int)pow(2, i - 1);
			if (num == n)
			{
				output(dp, next, n);
				return;
			}
		}
		for (int i = 5; i <= n; ++i)
		{
			if (dp[i] != MAX) continue;

			int prev = 0;
			if (i % 3 == 0)
			{
				dp[i] = dp[i / 3] + 1;
				prev = i / 3;
			}
			if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
			{
				dp[i] = dp[i / 2] + 1;
				prev = i / 2;
			}
			if (dp[i] > dp[i - 1] + 1)
			{
				dp[i] = dp[i - 1] + 1;
				prev = i - 1;
			}

			next[i] = prev;

		}

		output(dp, next, n);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_12852_BackTracking::Solution();

	return 0;
}