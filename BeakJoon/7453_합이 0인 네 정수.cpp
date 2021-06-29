// 21.06.29. 화
// 7453: 합이 0인 네 정수 https://www.acmicpc.net/problem/7453
// 중간에서 만나기, 이분탐색.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_7453
{
	void Solution()
	{
		int n;
		long long answer = 0;
		cin >> n;
		vector<int> a(n), b(n), c(n), d(n);
		for(int i=0; i<n; ++i)
		{ 
			cin >> a[i] >> b[i] >> c[i] >> d[i];
		}

		vector<int> pre_sum;
		// a, b 반으로 먼저 더한 값 만들어 놓기.
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				pre_sum.push_back(a[i] + b[j]);
			}
		}

		sort(pre_sum.begin(), pre_sum.end());

		// c, d 더한값에 미리 구한 값 더해서 0되는 인덱스들을 이분탐색으로 구하기.
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				answer += (upper_bound(pre_sum.begin(), pre_sum.end(), -1 * (c[i] + d[j])) - pre_sum.begin()) -
					(lower_bound(pre_sum.begin(), pre_sum.end(), -1 * (c[i] + d[j])) - pre_sum.begin());
			}
		}

		cout << answer;

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_7453::Solution();
	return 0;
}