// 20.12.26. 토
// 9020: 골드바흐의 추측 https://www.acmicpc.net/problem/9020
// 소수.
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n% i == 0) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n, temp;
	cin >> t;
	while (t--)
	{
		cin >> n;
		temp = n / 2;

		for (int i = temp; i >= 2; --i)
		{
			if (IsPrime(i) && IsPrime(n - i))
			{
				cout << i << " " << n - i << "\n";
				break;
			}
		}
	}

	return 0;
}