// 21.06.21. 월
// 2143: 두 배열의 합 https://www.acmicpc.net/problem/2143
// 부분합, 이분탐색(lower/upper_bound).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_2143
{
	typedef long long LL;

	// 모든 부분합 조합들 만들기.
	void MakePartialSumArr(vector<LL>& psum, int size)
	{
		vector<LL> arr(size);
		for (int i = 0; i < size; ++i)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < size; ++i)
		{
			int sum = arr[i];
			psum.push_back(sum);
			for (int j = i + 1; j < size; ++j)
			{
				sum += arr[j];
				psum.push_back(sum);
			}
		}
	}

	void Solution()
	{
		// input.
		long long T, answer = 0;;
		int n, m;
		cin >> T;
		cin >> n;
		vector<long long> apsum;
		MakePartialSumArr(apsum, n);
		cin >> m;
		vector<long long> bpsum;
		MakePartialSumArr(bpsum, m);

		// solution.
		sort(apsum.begin(), apsum.end());
		sort(bpsum.begin(), bpsum.end());

		for (int i = 0; i < apsum.size(); ++i) // apsum 기준으로.
		{
			// 이분탐색으로 둘이 합 5 초과 첫 인덱스 - 5 되는 첫 인덱스.
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