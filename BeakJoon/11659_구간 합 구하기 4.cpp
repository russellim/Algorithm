// 20.10.29. 목
// 11659_구간 합 구하기 4 https://www.acmicpc.net/problem/11659
// 부분합. IDE 사용 금지.
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, i, j;
    cin >> n >> m;
    int* arr = new int[n];
    int* store = new int[n];
    cin >> arr[0];
    store[0] = arr[0];
    for (int k = 1; k < n; ++k)
    {
        cin >> arr[k];
        store[k] = store[k - 1] + arr[k];
    }
    for (int k = 0; k < m; ++k)
    {
        cin >> i >> j;
        if (i == 1) cout << store[j - 1] << "\n";
        else cout << store[j - 1] - store[i - 2] << "\n";
    }
    delete[] arr;
    delete[] store;
}