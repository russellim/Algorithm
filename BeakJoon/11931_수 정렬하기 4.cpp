// 20.10.31. 토
// 11931_수 정렬하기 4 https://www.acmicpc.net/problem/11931
// 힙정렬, 병합정렬, 퀵정렬 (내림차순)
// 병합 정렬만 성공함 (나머지 시간 초과).
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void heapSort(int* arr, int size)
{
    if (size <= 1) return;
    for (int j = size; j >= 0; --j)
    {
        if (j != size) swap(arr[0], arr[j]);

        for (int i = 0; i < j; ++i)
        {
            int child = i;
            do
            {
                int root = (child - 1) / 2;
                if (arr[child] < arr[root])
                {
                    swap(arr[child], arr[root]);
                    child = root;
                }
                else
                    break;
            } while (child != 0);
        }
    }
}

void mergeSort(int* arr, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    int* store = new int[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j]) store[k++] = arr[i++];
        else store[k++] = arr[j++];
    }

    while (i <= mid) store[k++] = arr[i++];
    while (j <= end) store[k++] = arr[j++];

    for (int t = start, k = 0; t <= end; ++t)
    {
        arr[t] = store[k++];
    }
    delete[] store;
}


void quickSort(int* arr, int start, int end)
{
    if (start >= end) return;
    int pivot = start;
    int i = start + 1, j = end;

    while (i <= j)
    {
        while (i <= end && arr[i] >= arr[pivot]) ++i;
        while (j > start&& arr[j] <= arr[pivot]) --j;

        if (i <= j)
            swap(arr[i], arr[j]);
        else
            swap(arr[j], arr[pivot]);
    }

    quickSort(arr, start, j - 1);
    quickSort(arr, j + 1, end);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    //quickSort(arr, 0, n - 1);
    mergeSort(arr, 0, n - 1);
    //heapSort(arr, n);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << "\n";
    }

    delete[] arr;

    return 0;
}