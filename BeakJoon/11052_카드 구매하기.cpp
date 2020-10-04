// 20.10.04. 일
// 11052: 카드 구매하기 https://www.acmicpc.net/problem/11052
// DP
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;
	int* p = new int[n + 1];
	int* dp = new int[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	dp[0] = p[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}
	cout << dp[n];

	return 0;
}