// 20.08.27 THU
// 2751: 수 정렬하기 2 https://www.acmicpc.net/problem/2751
// 병합정렬
#include <iostream>
using namespace std;

void mergeSort(int* arr, int start, int end)
{
	if (start >= end) return;

	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	// i 왼쪽자른거 시작, j 오른쪽 자른거 시작.
	// k 저장할 배열 인덱스.
	int* store = new int[end - start + 1];
	int i = start, j = mid + 1, k = 0;

	// 한쪽 먼저 끝날때까지 크기비교한거 저장.
	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			store[k++] = arr[i++];
		}
		else
		{
			store[k++] = arr[j++];
		}
	}

	// 남은쪽 다 저장.
	while (i <= mid) store[k++] = arr[i++];
	while (j <= end) store[k++] = arr[j++];

	// 원본에 적용.
	for (int t = start, k = 0; t <= end; ++t)
	{
		arr[t] = store[k++];
		//cout << arr[t] << " ";
	}
	delete[] store; // 해제 중요!
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int a;
	cin >> a;
	int* arr = new int[a];
	for (int i = 0; i < a; ++i)
	{
		cin >> arr[i];
	}

	mergeSort(arr, 0, a - 1);

	for (int i = 0; i < a; ++i)
	{
		cout << arr[i] << "\n";
	}
}