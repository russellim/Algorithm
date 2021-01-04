// 21.01.04. 월
// 11055: 가장 큰 증가 부분 수열 https://www.acmicpc.net/problem/11055
// DP.
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
    vector<int> v(n), dp(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        dp[i] = v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[j] + v[i], dp[i]);
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << answer;

    return 0;
}