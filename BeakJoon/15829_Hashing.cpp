// 21.02.13. 토
// 15829: Hashing https://www.acmicpc.net/problem/15829
// 해싱, 오버플로우 주의.
#include <iostream>

using namespace std;

namespace Solution
{
	int L;
	unsigned long long num;
	string str;

	void Calcul()
	{
		unsigned long long r = 1, cut = 1234567891; //오버플로우 방지.
		for (int i = 0; i < L; ++i)
		{
			num += (str[i] - 'a' + 1) * r;
			r *= 31;
			num %= cut;
			r %= cut;
		}
	}

	void Input()
	{
		cin >> L >> str;
	}

	void Output()
	{
		cout << num;
	}
}

int main()
{
	Solution::Input();
	Solution::Calcul();
	Solution::Output();

	return 0;
}