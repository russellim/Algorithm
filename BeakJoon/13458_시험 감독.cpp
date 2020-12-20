// 20.12.20. 일
// 13458: 시험 감독 https://www.acmicpc.net/problem/13458
// Math.
#include <iostream>
using namespace std;

typedef long long LL;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, b, c;
	cin >> n;
	LL answer = n; // int로 하면 틀림. 총감독관은 기본으로 넣어줍시다.
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cin >> b >> c;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] - b <= 0) // 총 감독관으로 커버되면 다음방.
			continue;
		answer += (arr[i] - b) / c;
		if ((arr[i] - b) % c != 0) answer++;
	}

	cout << answer;

	delete[] arr;

	return 0;
}