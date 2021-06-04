// 21.06.04. 금
// 14426: 이모티콘 https://www.acmicpc.net/problem/14426
// DP.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_14226
{
	vector<int> dp;

	// 나눠 떨어지는 수에서 복붙하면?.
	void FindMin(int num)
	{
		for (int i = num / 2; i >= 2; --i)
		{
			if (num % i == 0)
			{
				dp[num] = min(dp[num], dp[i] + (num / i));
			}
		}
	}

	void Solution()
	{
		int s;
		cin >> s;

		if (s <= 5)
		{
			cout << s;
			return;
		}

		dp.assign(1005, 100);
		// 소수는 짝수번 먼저 구하고 홀수번을 구한다. (그래서 검사 끝을 다르게).
		// +2 는 구한 값이 전전값까지 영향을 줄 수 있기 때문.
		int end = (s % 2 == 0 ? s : s + 1) + 2;

		// 2~5.
		for (int i = 2; i <= 5; ++i) dp[i] = i;

		// 6~ 기본값 세팅 ( 2개로 붙여넣기 )
		for (int i = 6; i <= end; i += 2)
		{
			dp[i] = dp[i - 2] + 1;
		}
		// 6~.
		for (int i = 6; i <= end; i += 2)
		{
			FindMin(i);
			dp[i - 1] = min(dp[i - 1], dp[i] + 1);
			FindMin(i - 1);

			// 구한 i-1 값이 i-3 까지 영향을 줄 수 있음 (삭제로).
			if (dp[i - 1] < dp[i - 2])
			{
				dp[i - 2] = dp[i - 1] + 1;
				dp[i - 3] = min(dp[i - 3], dp[i - 2] + 1);
			}
		}


		// output.
		cout << dp[s];
		//for (int i = 2; i <= 1000; ++i)
		//	cout << i << " " << dp[i] << "\n";
	}
}

int main()
{
	BOJ_14226::Solution();
	return 0;
}