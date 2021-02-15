// 21.02.15. 월
// 1074: Z https://www.acmicpc.net/problem/1074
// 분할정복, 재귀.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace Z
{
	int powN, r, c, num = -1;
	bool IsFind = false;

	void WriteZ(int a, int b)
	{
		for (int i = a; i < a + 2; ++i)
		{
			for (int j = b; j < b + 2; ++j)
			{
				num++;
				if (i == r && j == c)
				{
					IsFind = true;
					return;
				}
			}
		}
	}

	void Divide(int n, int a, int b)
	{
		// 검사할 범위에 없으면 통째로 더하고 스킵.
		if (!(r >= a && r < a + n && c >= b && c < b + n))
		{
			num += pow(n, 2);
			return;
		}

		if (n == 2)
		{
			WriteZ(a, b);
			return;
		}

		int half = n / 2;
		for (int i = a; i <= a + half; i += half)
		{
			for (int j = b; j <= b + half; j += half)
			{
				Divide(half, i, j);
				if (IsFind) return;
			}
		}
	}

	void Input()
	{
		int N;
		cin >> N >> r >> c;
		powN = pow(2, N);
	}
	void Output()
	{
		cout << num;
	}
}

int main()
{
	Z::Input();
	Z::Divide(Z::powN, 0, 0);
	Z::Output();

	return 0;
}