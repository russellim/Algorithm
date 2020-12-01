// 20.12.01. 화
// 4948: 베르트랑 공준 https://www.acmicpc.net/problem/4948
// 소수.
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n)
{
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); ++i)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;

	bool prime[123457 * 2];
	for (int i = 2; i <= 123456 * 2; ++i)
	{
		prime[i] = IsPrime(i);
	}

	while (1)
	{
		cin >> n;
		if (n == 0) break;

		int answer = 0;
		for (int i = n + 1; i <= n * 2; ++i)
			if (prime[i]) answer++;

		cout << answer << "\n";
	}

	return 0;
}