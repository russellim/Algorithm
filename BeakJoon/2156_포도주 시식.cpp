// 20.09.16 화
// 2156: 포도주 시식 https://www.acmicpc.net/problem/2156
// DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> vec(n + 1, 0);
	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> vec[i];
	}

	sum[1] = vec[1];
	sum[2] = vec[1] + vec[2];

	// 1. 이전의 합 (지금은 건너뜀, 앞으로 두번 연속 가능)
	// 2. 지금 + 이전전의 합 (이전을 건너뜀, 앞으로 한번 연속 가능)
	// 3. 지금 + 이전 + 이전전전의 합 (이전전을 건너뜀, 이제 연속 불가)
	// 이중에 큰 값.
	for (int i = 3; i <= n; ++i)
	{
		sum[i] = max({ sum[i - 1], vec[i] + sum[i - 2], vec[i] + vec[i - 1] + sum[i - 3] });
	}

	cout << sum[n];
}