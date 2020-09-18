// 20.09.18 금
// 1912: 연속합 https://www.acmicpc.net/problem/1912
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

	int temp, sum = 0, maxsum = 0;
	cin >> sum;
	maxsum = sum;
	for (int i = 1; i < n; ++i)
	{
		cin >> temp;
		// 입력 값과 연속된 합을 비교.
		// 입력 값이 더 크면 연쇄가 끊기는거임!.
		sum = max(temp, temp + sum);

		// 젤 큰 합을 저장.
		if (sum > maxsum) maxsum = sum;
		//cout << i << ":" << sum << " " << maxsum << endl;
	}
	cout << maxsum;

	return 0;
}