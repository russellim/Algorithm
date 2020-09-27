// 20.09.27 일
// 2231: 분해합 https://www.acmicpc.net/problem/2231
// Brute Force
#include <iostream>
using namespace std;

int main()
{
	int n, sum;
	cin >> n;

	if (n == 1)
	{
		cout << "0";
		return 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		int temp = i;
		sum = temp;
		while (1)
		{
			sum += temp % 10;
			temp /= 10;
			if (temp == 0) break;
		}
		
		if (sum == n)
		{
			cout << i;
			break;
		}

		if (i == n) cout << "0";
	}

	return 0;
}