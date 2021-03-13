// 21.03.13. 토
// 이분탐색_입국심사 https://programmers.co.kr/learn/courses/30/lessons/43238
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <memory>

using namespace std;

typedef long long LL;

LL solution(int n, vector<int> times) {
	LL size = times.size();
	sort(times.begin(), times.end());

	LL start = (LL)n / size * (LL)times[0];	// 다 공평하게 나눈거를 제일 작은 값에 곱한 값.
	LL end = (LL)times[size - 1] * (LL)n;	// 제일 큰 값이 독식.

	while (start < end)
	{
		LL mid = (start + end) / 2;
		LL temp = 0;

		for (int i = 0; i < size; ++i)
		{
			temp += mid / times[i];
		}

		if (temp < n) start = mid + 1;
		else end = mid;
	}

	return start;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution(6, { 7, 10 }) << "\n"; // 28.
	cout << solution(10, { 2,3,5 }) << "\n"; // 10.
	cout << solution(6, { 1, 10 }) << "\n"; // 6.
	cout << solution(6, { 1, 5 }) << "\n"; // 5.
	cout << solution(4, { 1,2,3,4 }) << "\n"; // 3.
	cout << solution(5, { 1,2,3,4 }) << "\n"; // 3.

	return 0;
}

// 이분탐색 안쓴거 실패!
//long long solution(int n, vector<int> times) {
//	long long answer = LLONG_MAX, tempAnswer = 0;
//	int index = 0;
//	int size = times.size();
//	sort(times.begin(), times.end());
//	unique_ptr<int[]> nums = make_unique<int[]>(times.size());
//	int tempN = n;
//	for (int i = 0; i < size; ++i)
//	{
//		if (i == size - 1) nums[i] = tempN;
//		else nums[i] = tempN / 2 + tempN % 2;
//		tempN -= nums[i];
//	}
//
//	while (1)
//	{
//		tempAnswer = 0;
//		for (int i = size - 1; i >= 0; --i)
//		{
//			if (tempAnswer < (long long)nums[i] * times[i])
//			{
//				index = i;
//				tempAnswer = (long long)nums[i] * times[i];
//			}
//		}
//		if (answer < tempAnswer) break;
//		answer = tempAnswer;
//		if (index == 0) break;
//		nums[index]--;
//		nums[0]++;
//	}
//
//	return answer;
//}