// 20.12.31. 목
// 1699: 제곱수의 합 https://www.acmicpc.net/problem/1699
// DP.
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int Solution(int n)
{
    int* dp = new int[n + 1];

    // 제곱근 딱 떨어지는 애들은 1.
    for (int i = 1; i * i <= n; ++i)
    {
        dp[i * i] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        if (sqrt(i) == round(sqrt(i))) continue; // 위에서 구한애들(1)은 스킵.
        dp[i] = i;
        for (int j = 1; j * j <= i; ++j)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;

    cin >> n;
    cout << Solution(n);

    return 0;
}