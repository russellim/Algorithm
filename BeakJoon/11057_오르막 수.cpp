// 20.12.04. 금
// 11057: 오르막 수 https://www.acmicpc.net/problem/11057
// DP.
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int* arr = new int[n + 1];
	// f(n) = f(n-1) + 수열의 합(plus).
	int* plus = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };
	arr[1] = 10;
	for (int i = 2; i <= n; ++i)
	{
		int ans = plus[1];
		for (int j = 2; j <= 9; ++j)
		{
			ans += plus[j]; // 수열의 합.
			// 다음 수열 구하기.
			plus[j] = (plus[j - 1] + plus[j]) % 10007;
		}
		arr[i] = (arr[i - 1] + ans) % 10007;
	}

	cout << arr[n];

	delete[] arr;
	delete[] plus;

	return 0;
}