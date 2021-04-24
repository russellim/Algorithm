// 21.04.02. 금
// 13172: Σ https://www.acmicpc.net/problem/13172
// math, 모듈러 역원.
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

namespace BOJ_13172
{
	typedef unsigned long long ULL;
	constexpr unsigned int mod = 1000000007;

	pair<ULL, pair<ULL, ULL> > xGCD(ULL a, ULL b)
	{
		if (b == 0) return { a, {1, 0} };
		auto res = xGCD(b, a % b);
		ULL g = res.first;
		ULL x, y;
		tie(x, y) = res.second;
		return { g, {y, x - (a / b) * y} };
	}

	ULL ModeInverse(ULL N)
	{
		auto res = xGCD(N, mod);
		if (res.first > 1) return -1; // 서로소 검사. (이 문제에서는 사용x).
		return (res.second.first + mod) % mod; // +mod는 음수 처리. (이 문제에서는 사용x).
	}

	ULL CalculMod(ULL N, ULL S)
	{
		return (S * ModeInverse(N)) % mod;
	}

	// 최대공약수.
	template<class T>
	T GCD(T a, T b)
	{
		while (b != 0)
		{
			T r = a % b;
			a = b;
			b = r;
		}
		return a;
	}

	void Solution()
	{
		int m, n, s;
		cin >> m;

		ULL answer = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> n >> s;
			int gcd = GCD<int>(n, s);	// 기약분수로.
			answer += (CalculMod(n / gcd, s / gcd));
			answer %= mod;
		}

		// output.
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_13172::Solution();

	return 0;
}