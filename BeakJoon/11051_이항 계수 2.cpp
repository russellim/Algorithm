// 20.12.19. 토
// 11051: 이항 계수 2 https://www.acmicpc.net/problem/11051
// Math: 이항정리, 파스칼의 삼각형, DP
#include <iostream>
#include <cstring>

using namespace std;

int bino(int** dp, int n, int k)
{
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;

			if (i == n && j == k)
			{
				return dp[i][j];
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, k;
	cin >> n >> k;

	// 2차원배열 동적할당.
	int** dp = new int* [n + 1];
	for (int i = 0; i <= n; ++i)
	{
		dp[i] = new int[n + 1];
		memset(dp[i], 0, sizeof(int) * (n + 1));
	}

	cout << bino(dp, n, k);

	for (int i = 0; i <= n; ++i)
	{
		delete[] dp[i];
	}
	delete[] dp;

	return 0;
}