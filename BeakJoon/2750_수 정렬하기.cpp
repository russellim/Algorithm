// 20.08.25 TUE
// 2750: 수 정렬 https://www.acmicpc.net/problem/2750
// 정렬

// 퀵정렬, 힙정렬, 내가 정리해본 힙정렬.

#include <iostream>
using namespace std;

void quick_sort(int* arr, int start, int end)
{
	// 평균속도 빠름.
	// 정렬이 미리 된 배열은 안됨.
	if (start >= end) return;
	int pivot = start;
	int i = start + 1, j = end;
	int temp;

	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot]) i++;
		while (j >= start && arr[j] >= arr[pivot]) j--;
		if (i > j)
		{
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = temp;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void heap_sort(int* arr, int size)
{
	// 한번 힙 구조 만들고 자식 크기 비교하며 정렬.
	// 최대 힙 구조로 만듦.
	for (int i = 1; i < size; ++i)
	{
		int child = i;
		do
		{
			int root = (child - 1) / 2;
			if (arr[root] < arr[child])
			{
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		} while (child != 0);
	}
	// 젤앞에 있는 젤 큰 값을 뒤로 보냄.
	for (int i = size - 1; i >= 0; --i)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		int child;
		int root = 0;
		do
		{
			child = 2 * root + 1;
			//자식 중에 더 큰 값 찾기.
			if (arr[child] < arr[child + 1] && child < i - 1)
			{
				child++;
			}
			// 루트보다 자식이 더 크면 교환.
			if (arr[root] < arr[child] && child < i)
			{
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			root = child;
		} while (child < i);
	}

}

// 나가 다시 만들어보는 힙 정렬.
// 반복횟수 줄여서 8ms -> 0ms.
void SJ_HeapSort(int* arr, int size)
{
	if (size <= 1) return;
	for (int j = size; j >= 0; --j)
	{
		if (j != size)
		{
			int temp = arr[0];
			arr[0] = arr[j];
			arr[j] = temp;
		}

		for (int i = 1; i < j; ++i)
		{
			int child = i;
			do
			{
				int root = (child - 1) / 2;
				if (arr[root] < arr[child])
				{
					//cout << "바꿔!: " << arr[root] << " " << arr[child] << endl;
					int temp = arr[root];
					arr[root] = arr[child];
					arr[child] = temp;
					child = root;
				}
				else
				{
					// 바뀌는 일이 없다면 root위로는 다시 검사 할필요없잔헝.
					break;
				}
			} while (child != 0);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int a;
	cin >> a;
	int *arr = new int[a];
	for (int i = 0; i < a; ++i)
	{
		cin >> arr[i];
	}

	// 방법 1: stl의 sort쓰는게 제일 간단.
	// 방법 2: quick_sort(arr, 0, a);
	// 방법 3: heap_sort(arr, a);

	// 방법 4 (방법 3 변형): 
	SJ_HeapSort(arr, a);

	for (int i = 0; i < a; ++i)
	{
		cout << arr[i] << "\n";
	}
}
