// 20.11.19. 목
// 1182: 부분수열의 합 https://www.acmicpc.net/problem/1182
// 백트래킹
#include <iostream>

using namespace std;

int arr[20];
int n, s, cnt, answer, sum;

void makeParti(int size, int start)
{
	if (size == cnt)
	{
		if (sum == s) answer++;
		return;
	}

	for (int i = start; i < n; ++i)
	{
		sum += arr[i];
		makeParti(size + 1, i + 1);
		sum -= arr[i];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (cnt = 1; cnt <= n; ++cnt)
	{
		sum = 0;
		for (int i = 0; i <= n - cnt; ++i)
		{
			sum += arr[i];
			makeParti(1, i + 1);
			sum -= arr[i];
		}
	}

	cout << answer;

	return 0;
}