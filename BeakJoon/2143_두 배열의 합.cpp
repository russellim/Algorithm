// 21.06.21. 일
// 2143: 두 배열의 합 https://www.acmicpc.net/problem/2143

// failed 다시 볼것.
// upper, lower bound 사용?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_2143
{
	void InputArr(vector<long long>& psum, int size)
	{
		int temp;
		for (int i = 1; i <= size; ++i)
		{
			cin >> temp;
			psum[i] = temp + psum[i - 1];
		}
	}

	void Solution()
	{
		// input.
		long long T, answer = 0;;
		int n, m;
		cin >> T;
		cin >> n;
		vector<long long> apsum(n + 1, 0);
		InputArr(apsum, n);
		cin >> m;
		vector<long long> bpsum(m + 1, 0);
		InputArr(bpsum, m);

		sort(apsum.begin(), apsum.end());
		sort(bpsum.begin(), bpsum.end());

		for (int i = 1; i <= n; ++i)
		{
			int low = lower_bound(bpsum.begin(), bpsum.end(), T - apsum[i]) - bpsum.begin();
			int high = upper_bound(bpsum.begin(), bpsum.end(), T - apsum[i]) - bpsum.begin();

			answer += (high - low);
		}

		cout << answer;
	}
}

int main()
{
	BOJ_2143::Solution();

	return 0;
}