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

	// dp[k]는 k개 샀을때 최대값.
	// 카드 N개를 만들어야하니까 DP로 1~N개 될때의 최대값을 구함.

	// (q, w) == q개 샀을때 최대값, w개 가격.
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			// i개 샀을때의 최대값을 구하는 것.
			// max()라 복잡해보이지 예를들어 3개 샀을때 최대값을 구하려면
			// (2, 1)=a (1, 2)=b (0, 3)=c.  구한 a, b, c 중 제일 큰 값을 찾는 것이당.
			// n = 4, 마지막 dp[i - j] + p[j] -> (3, 1), (2, 2), (1, 3), (0, 4).
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	//for (int i = 0; i <= n; ++i)
	//{
	//	cout << dp[i] << " ";
	//}
	//cout << endl;
	cout << dp[n];

	return 0;
}