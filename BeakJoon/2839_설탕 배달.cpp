// 20.08.24 Mon
// 2839: 설탕 배달 https://www.acmicpc.net/problem/2839
// 그리디 알고리즘, 다이나믹 프로그래밍

// 큰 수 5로 먼저 나누고, 나머지가 작은 수 3으로 안떨어지면 횟수를 되돌려 3으로 떨어지는지 확인.
// 끝까지 안되면 -1 반환

#include <iostream>
using namespace std;

int main()
{
	int a, count = 0;

	cin >> a;

	count += a / 5;
	a = a % 5;
	while (a > 0)
	{
		if (a % 3 == 0)
		{
			count += a / 3;
			a = a % 3;
		}
		else
		{
			if (count == 0)
			{
				count = -1;
				break;
			}
			count--;
			a += 5;
		}
	}
	cout << count;
}