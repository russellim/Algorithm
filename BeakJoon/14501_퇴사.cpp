// 20.09.28 월
// 14501: 퇴사 https://www.acmicpc.net/problem/14501
// DP
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, t, p, maxValue = 0;;
	cin >> n;

	// 배열 크기 주의!.
	// 밑의 주석은 안됩니다.
	//int* tarr = new int[n + 1];
	//int* parr = new int[n + 1];
	//int* sumarr = new int[n + 1];
	int tarr[17] = { 0, };
	int parr[17] = { 0, };
	int sumarr[17] = { 0, };

	for (int i = 1; i <= n; ++i)
	{
		cin >> t >> p;
		// 정한 날짜 넘는 일은 페이 없다고 칩니다.
		if (i + t - 1 > n)
		{
			t = 1;
			p = 0;
		}
		tarr[i] = t;
		parr[i] = p;
	}

	for (int i = 1; i <= n; ++i)
	{
		// 일 시작날의 합과 일 끝난날의 합 비교해서 큰거로 넣어주기.
		sumarr[i] += parr[i];
		if(sumarr[i + tarr[i]] < sumarr[i])
			sumarr[i + tarr[i]] = sumarr[i];

		// (예제 4번) 중간에 쉬는날 있을 수 있으므로 주의!.
		// 지금까지의 합을 앞으로의 합과 비교해서 큰거를 넣어줍니다.
		for (int j = i + tarr[i]+1; j <= n; ++j)
		{
			if (sumarr[j] < sumarr[i])
				sumarr[j] = sumarr[i];
		}

		if (sumarr[i + tarr[i]] > maxValue)  maxValue = sumarr[i + tarr[i]];
	}

	cout << maxValue;

	return 0;
}