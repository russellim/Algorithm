qk// 20.09.20 일
// 10844: 쉬운 계단 수 https://www.acmicpc.net/problem/10844
// DP
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;
	long long arr[101][11] = { 0 };

	for (int i = 0; i <= 9; ++i)
	{
		arr[1][i] = 1;
	}


	for (int i = 2; i <= n; ++i)
	{
		arr[i][0] = arr[i - 1][1];
		for (int j = 1; j <= 9; ++j)
		{
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
			//cout << arr[i][j] << endl;
		}
	}

	long long sum = 0;
	for (int i = 1; i < 10; ++i)
	{
		sum += arr[n][i];
	}
	cout << sum % 1000000000;


	return 0;
}