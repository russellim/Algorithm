// 21.04.21. 수
// 6588: 골드바흐의 추측 https://www.acmicpc.net/problem/6588
// 소수판별.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

namespace BOJ_6588
{
	bool IsPrime(int n)
	{
		if (n == 1) return false;
		if (n == 2) return true;
		for (int i = 2; i <= sqrt(n); ++i)
		{
			if (n % i == 0) return false;
		}
		return true;
	}

	void Solution()
	{
		int n;
		while (1)
		{
			cin >> n;
			if (n == 0) break;
			bool IsFind = false;
			for (int i = 1; i <= n / 2; ++i)
			{
				if (IsPrime(i) && IsPrime(n - i))
				{
					cout << n << " = " << i << " + " << n - i << "\n";
					IsFind = true;
					break;
				}
			}
			if (!IsFind)
			{
				cout << "Goldbach's conjecture is wrong." << "\n";
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_6588::Solution();

	return 0;
}