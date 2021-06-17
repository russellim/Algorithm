// 21.06.17. 목
// 12015: 가장 긴 증가하는 부분 수열 2 https://www.acmicpc.net/problem/12015
// 이분탐색.

// LIS 문제를 n^2 -> nlogn으로 풀수 있게 되었다.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_12015
{
	// 증가되는 수열이 저장되는 곳.
	// 결과가 답의 수열은 아님!
	vector<int> store;

	// 이분탐색으로 새로 들어온 수의 자리를 찾음.
	int FindIndex(int num)
	{
		int start = 0, end = store.size() - 1;

		while (start < end)
		{
			int mid = (start + end) / 2;
			if (num > store[mid]) start = mid + 1;
			else end = mid;
		}

		return start;
	}

	void Solution()
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;

			if (store.empty() || store.back() < num)
			{
				store.emplace_back(num);
			}
			else
			{
				int index = FindIndex(num);
				store[index] = num;
			}
		}

		cout << store.size();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_12015::Solution();

	return 0;
}