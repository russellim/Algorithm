// 20.11.11. 수
// 11728: 배열 합치기 https://www.acmicpc.net/problem/11728
// Merge Sort
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int a, b;
	cin >> a >> b;

	vector<int> arr(a+b);

	for (int i = 0; i < a; ++i) cin >> arr[i];
	for (int i = a; i < a+b; ++i) cin >> arr[i];

	int i = 0, j = a;

	while (i < a && j < a+b)
	{
		if (arr[i] < arr[j]) cout << arr[i++] << " ";
		else cout << arr[j++] << " ";
	}
	while (i < a) cout << arr[i++] << " ";
	while (j < a+b) cout << arr[j++] << " ";

	return 0;
}
}