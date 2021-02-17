// 21.02.17. 수
// 6064: 카잉 달력 https://www.acmicpc.net/problem/6064
// 중국인의 나머지 정리
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 예> 10 12 3 9
// x≡3 (mod 10), x≡9 (mod 12)
namespace BOJ_6064
{
	int M, N, x, y;
	void Output(int year);

	int ModInverse(int a, int mod, int rem, int plus)
	{
		for (int i = 1; i < mod; ++i)
		{
			if ((a * i) % mod == rem) return a * i + plus;
		}
		return -1;
	}

	void Solution()
	{
		if (x == y && x <= M && y <= N)
		{
			Output(x);
			return;
		}
		int inverse;
		inverse = x > y ? ModInverse(N, M, x - y, y) : ModInverse(M, N, y - x, x);
		Output(inverse);
	}

	void Input()
	{
		int t;
		cin >> t;
		while (t--)
		{
			cin >> M >> N >> x >> y;
			Solution();
		}
	}

	void Output(int year)
	{
		cout << year << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_6064::Input();

	return 0;
}