// 21.04.07. 수
// 2467: 용액 https://www.acmicpc.net/problem/2467
// 이분탐색.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

namespace BOJ_2467
{
	// 사전 검사.
	void CheckMinMix(pair<int, int>& answer, int& minMix, int num, int plus)
	{
		if (minMix > abs(num + plus))
		{
			answer = { num, plus };
			minMix = abs(num + plus);
		}
	}

	pair<int, int> BinarySearch(int n, vector<int>& v)
	{
		pair<int, int> answer;
		int minMix = 2e9;
		for (int k = 0; k < n - 1; ++k)
		{
			int num = v[k], mid;
			int i = k + 1, j = n - 1;

			CheckMinMix(answer, minMix, num, v[i]);
			CheckMinMix(answer, minMix, num, v[j]);

			// 이분탐색.
			while (i < j)
			{
				mid = (i + j) / 2;
				int mix = num + v[mid];
				if (mix < 0) i = mid + 1;
				else j = mid;

				if (minMix > abs(mix))
				{
					minMix = abs(mix);
					answer = { num, v[mid] };
				}
			}
		}

		return answer;
	}

	void Solution()
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		auto answer = BinarySearch(n, v);

		// output.
		cout << answer.first << " " << answer.second;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2467::Solution();

	return 0;
}