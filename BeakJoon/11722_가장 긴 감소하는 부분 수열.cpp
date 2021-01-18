// 21.01.18. 월
// 11722: 가장 긴 감소하는 부분 수열 https://www.acmicpc.net/problem/11722
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, answer = 1;
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (v[i] < v[j] && dp[j] >= dp[i])
                dp[i]++;
        }
        answer = max(answer, dp[i]);
    }

    cout << answer;

    return 0;
}