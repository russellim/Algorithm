// 20.12.29. 화
// 9251: LCS https://www.acmicpc.net/problem/9251
// DP, Longest Common Subsequence (최장 공통 부분 수열).

// LCS: 두 수열이 주어졌을 때, 부분 수열이 되는 수열 중 가장 긴 것을 찾는다.
// ex> ACAYKP와 CAPCAK의 LCS는 ACAK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    // 각각 문자열 길이+1의 2차원 배열 준비.
    vector<vector<int> > dp(b.size() + 1, vector<int>(a.size() + 1, 0));

    for (int i = 1; i <= b.size(); ++i)
    {
        for (int j = 1; j <= a.size(); ++j)
        {
            // 비교 문자가 같으면, 왼쪽 대각선 위 값 +1
            if (b[i - 1] == a[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            // 비교 문자가 다르면, max(왼쪽 값, 위쪽 값).
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[b.size()][a.size()];

    return 0;
}