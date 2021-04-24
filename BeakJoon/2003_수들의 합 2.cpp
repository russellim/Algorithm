// 21.03.30. 화
// 2003: 수들의 합 2 https://www.acmicpc.net/problem/2003
// 부분합.
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_2003
{
	void Solution()
	{
		int n, m, answer = 0;
		cin >> n >> m;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
			if (i != 0) nums[i] += nums[i - 1];
			if (nums[i] == m) answer++;

			for (int j = i - 1; j >= 0; --j)
			{
				if (nums[i] - nums[j] == m) answer++;
				else if (nums[i] - nums[j] > m) break;
			}
		}

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2003::Solution();

	return 0;
}