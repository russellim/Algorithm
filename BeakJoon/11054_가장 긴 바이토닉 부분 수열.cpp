// 21.01.13. 수
// 11054: 가장 긴 바이토닉 부분 수열 https://www.acmicpc.net/problem/11054
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
    vector<int> dp(n, 1); // 길이 저장.
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    // 증가 검사.
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // 뒤에 값(v[j])이 더 크고, 현재 길이가 이전까지 길이보다 같거나 작으면 갱신(이전+1). 
            if (v[i] > v[j] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
                answer = max(answer, dp[i]);
            }
        }
    }

    // 감소 검사.
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // 값 비교 부등호만 바꿈.
            if (v[i] < v[j] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
                answer = max(answer, dp[i]);
            }
        }
    }

    cout << answer;

    return 0;
}