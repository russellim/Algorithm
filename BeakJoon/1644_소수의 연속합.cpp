// 21.06.16. 수
// 1644: 소수의 연속합 https://www.acmicpc.net/problem/1644
// 소수판별, 두 포인터.

// vector<bool>을 사용하는것보다 vector<int>가 더 빨랐다.
// bool은 1비트지만 c++에서 최소 자료형의 크기는 8비트라 큰 vector<bool>을 사용하면 낭비?!
// vector<bool>이 실제 bool 값을 담고 있는게 아니라 압축된 형태로 표현한다.
// 그래서 처리과정이 더 필요해 속도가 더 느린걸지도. 되도록 사용x.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_1644
{
	vector<int> psum(1, 0);

	// 소수의 psum 구하기 (에라토스테네스의 체 이용).
	void GetPrimeNumber(int n)
	{
		vector<int> isPrime(n + 1, 1);
		int size = 1;

		for (int i = 2; i <= n; ++i)
		{
			if (isPrime[i] == 0) continue;
			++size;
			psum.push_back(psum[size - 2] + i);
			for (int j = 2 * i; j <= n; j += i)
			{
				isPrime[j] = 0;
			}
		}
	}

	void Solution()
	{
		int n, answer = 0;
		cin >> n;

		GetPrimeNumber(n);

		// 두 포인터.
		int i = 0, j = 0;
		int size = psum.size();
		while (j < size)
		{
			int sum = psum[j] - psum[i];
			if (sum == n) ++answer;

			if (j == size - 1 && sum < n) break;

			if (sum <= n) ++j;
			else ++i;
		}

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1644::Solution();

	return 0;
}