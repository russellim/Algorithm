// 21.03.04. 목
// 1629: 곱셈 https://www.acmicpc.net/problem/1629
// 분할정복을 이용한 거듭제곱.
#include <iostream>

using namespace std;

namespace BOJ_1629
{
	long long MakePow(int a, int b, int c)
	{
		if (b == 0) return 1;

		long long n = MakePow(a, b / 2, c);
		long long temp = (n * n) % c;

		if (b % 2 == 0) return temp; // 위에서 나눴음.
		else return (a * temp) % c;
	}

	void Solution()
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << MakePow(a, b, c);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1629::Solution();

	return 0;
}