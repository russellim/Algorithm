// 21.04.22. 목
// 2960: 에라토스테네스의 체 https://www.acmicpc.net/problem/2960
// 소수판별.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_2960
{
	void Solution()
	{
		int n, k;
		cin >> n >> k;
		vector<bool> nums(n + 1, true);
		int p;

		while (1)
		{
			for (int i = 2; i <= n; ++i)
			{
				if (nums[i])
				{
					p = i;
					nums[i] = false;
					k--;
					break;
				}
			}
			if (k == 0)
			{
				cout << p;
				return;
			}

			for (int i = 2; i <= n / p; ++i)
			{
				if (!nums[p * i]) continue;
				nums[p * i] = false;
				k--;
				if (k == 0)
				{
					cout << p * i;
					return;
				}
			}

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2960::Solution();

	return 0;
}
