// 20.09.05 토
// 1932: 정수 삼각형 https://www.acmicpc.net/problem/1932
// DP
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;
	int sum[500][500] = { 0, };

	// 맨 처음 수는 그냥 받고,
	cin >> sum[0][0];
	// 그 다음 수부터 받자마자 밑에 꺼랑 계산해줌.
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> sum[i][j];
			if (j == 0) sum[i][j] += sum[i - 1][j];
			else if (j == i) sum[i][j] += sum[i - 1][j - 1];
			// 양 끝 자리가 아니면 밑에 양 옆 수중에서 결과 큰걸로 저장.
			else sum[i][j] += max(sum[i - 1][j - 1], sum[i - 1][j]);
		}
	}

	// 그럼 다 더한것들중 제일 큰값을 찾으면 되겠져?!
	int maxValue = sum[n - 1][0];
	for (int i = 1; i < n; ++i)
	{
		maxValue = max(maxValue, sum[n - 1][i]);
	}
	cout << maxValue;
}