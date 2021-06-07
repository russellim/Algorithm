// 21.06.07. 월
// 13398: 연속합 2 https://www.acmicpc.net/problem/13398
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_13398
{
	void Solution()
	{
		int n, answer = 0;
		cin >> n;
		vector<int> arr(n);
		// [0][]은 삭제x, [1][] 삭제o.
		vector<vector<int> > dp(2, vector<int>(n));

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		answer = dp[0][0] = dp[0][1] = arr[0];

		for (int i = 1; i < n; ++i)
		{
			dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
			dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i]);
			answer = max({ answer, dp[0][i], dp[1][i] });
		}

		//for (auto& x : dp)
		//{
		//	for (int& y : x) cout << y << " ";
		//	cout << endl;
		//}

		cout << answer;

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_13398::Solution();

	return 0;
}