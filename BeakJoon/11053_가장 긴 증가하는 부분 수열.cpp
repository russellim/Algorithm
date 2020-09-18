// 20.09.18 금
// 11053: 가장 긴 증가하는 부분 수열 https://www.acmicpc.net/problem/11053
// DP
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, sum = 0;
	cin >> n;
	int* dp = new int[n + 1];
	int* arr = new int[n + 1];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		sum = max(sum, dp[i]);
	}
	cout << sum << endl;

	return 0;
}