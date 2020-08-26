// 20.08.26 WED
// 1463: 1로 만들기 https://www.acmicpc.net/problem/1463
// 다이나믹 프로그래밍.

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int* arr = new int[1000001];
	int a;
	cin >> a;

	arr[1] = 0;

	// DP니까 거꾸로 생각하셈. 어캐 나눠야 되는가가 아니라 1부터 차례대로 어캐 곱하면 만들어지는지.
	// arr[i]은 조건에 따라 arr[i-1], arr[i-2], arr[i-3]에서 한번더 연산해서 만들수인.
	// 2의 배수도 3의 배수도 아닌 수는 그 전 단계에서 1만 더하면 됨 (방법3: -1).
	// 2의 배수이거나 3의 배수인 수는 2나 3 한번 나누면 그 전단계가 뭔지 알수있죠?! (방법1,2: /2, /3).
	// 예외가 있을지도 모르니 전단계+1과 연산해준걸 비교해줍시다. (10 이 예외였음)
	for (int i = 2; i <= a; ++i)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
	}

	cout << arr[a];
}