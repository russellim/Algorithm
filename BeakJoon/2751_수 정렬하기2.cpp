// 20.08.27 THU
// 2751: 수 정렬하기 2 https://www.acmicpc.net/problem/2751
// 병합정렬
#include <iostream>
using namespace std;

int a;
int* store;

void mergeSort(int* arr, int start, int end)
{
	if (start >= end) return;

	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	int i = start, j = mid + 1, k = start;

	while(i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			store[k] = arr[i++];
		}
		else
		{
			store[k] = arr[j++];
		}
		k++;
	}
	if (i > mid)
	{
		for (int t = j; t <= end; ++t)
		{
			store[k] = arr[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= mid; ++t)
		{
			store[k] = arr[t];
			k++;
		}
	}
	
	for (int t = start; t <= end; ++t)
	{
		arr[t] = store[t];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> a;
	int* arr = new int[a];
	store = new int[a];
	for (int i = 0; i < a; ++i)
	{
		cin >> arr[i];
	}

	mergeSort(arr, 0, a-1);

	for (int i = 0; i < a; ++i)
	{
		cout << arr[i] << "\n";
	}
}