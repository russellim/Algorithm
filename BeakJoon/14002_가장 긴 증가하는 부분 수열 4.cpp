// 21.06.01. 화
// 14002: 가장 긴 증가하는 부분 수열 4 https://www.acmicpc.net/problem/14002
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_14002
{
	// 가장 긴 증가하는 부분 수열의 끝 인덱스 반환.
	int GetDP(int n, vector<int>& arr, vector<int>& dp)
	{
		int index = 0;
		int value = 1;

		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (arr[i] >= arr[j]) continue;
				dp[j] = max(dp[j], dp[i] + 1);
				if (value < dp[j])
				{
					value = dp[j];
					index = j;
				}
			}
		}

		return index;
	}

	void Solution()
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<int> dp(n, 1);
		for (int& x : arr) cin >> x;

		int index = GetDP(n, arr, dp);

		// 역으로 부분 수열 배열 구하기.
		vector<int> answer;
		answer.push_back(arr[index]);
		for (int i = index - 1; i >= 0; --i)
		{
			if (dp[i] == dp[index] - 1 && arr[i] < arr[index])
			{
				answer.push_back(arr[i]);
				index = i;
			}
		}

		// output.
		cout << answer.size() << "\n";
		for (int i = answer.size() - 1; i >= 0; --i)
		{
			cout << answer[i] << " ";
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_14002::Solution();

	return 0;
}