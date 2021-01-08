// 21.01.08. 금
// 2217: 로프 https://www.acmicpc.net/problem/2217
// 그리디.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, answer = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
        answer = max(answer, v[i] * (n - i));

    cout << answer;

    return 0;
}