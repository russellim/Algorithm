// 21.04.16. 금
// 2473: 세 용액 https://www.acmicpc.net/problem/2473
// 투 포인트.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

namespace BOJ_2473
{
	typedef long long LL;

	void Solution()
	{
		int n;
		LL minSum = LLONG_MAX;
		vector<LL> answer(3);
		cin >> n;
		vector<LL> arr(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];

		sort(arr.begin(), arr.end());
		// 하나 먼저 픽해놓고 투포인트.
		for (int i = 0; i < n; ++i)
		{
			int left = 0, right = n - 1;
			while (left < right)
			{
				if (left == i) ++left;
				if (right == i) --right;
				if (left >= right) break;

				LL sum = arr[i] + arr[left] + arr[right];
				if (minSum > abs(sum))
				{
					minSum = abs(sum);
					answer = { arr[i], arr[left], arr[right] };
				}
				if (sum < 0) left++;
				else right--;
			}
		}

		// output.
		sort(answer.begin(), answer.end());
		for (int x : answer) cout << x << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2473::Solution();

	return 0;
}