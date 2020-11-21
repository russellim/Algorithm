// 20.11.21. 토
// 1010: 다리 놓기 https://www.acmicpc.net/problem/1010
// math(조합 (nCm))

// 30!은 unsinged long long에도 못담는것과
//double -> int 강제 캐스팅하면 소수점이 모두 잘리는것을 알라.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		double ans = 1;
		int n, m, count;
		cin >> n >> m;
		count = n;

		for (int i = 0; i < count; ++i)
		{
			ans *= m--;
			ans /= n--;
		}

		ans = round(ans);
		cout << (int)ans << "\n";
	}

	return 0;
}