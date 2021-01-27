// 21.01.26. 화
// 2294: 동전 2 https://www.acmicpc.net/problem/2294
// DP.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1e9

// 방법1. 재귀 (시간초과!!!!)
//int solution(vector<int>& coins, int InitBalance, int curindex)
//{
//    int answer = MAX;
//    int firstCoinMaxCount = InitBalance / coins[curindex];
//
//    for (int i = firstCoinMaxCount; i >= 0; --i)
//    {
//        int balance = InitBalance, div = coins[curindex], count = 0;
//        count = i;
//        balance -= (div * i);
//
//        if (balance == 0)
//        {
//            answer = min(answer, count);
//            return answer;
//        }
//
//        if (curindex != 0)
//        {
//            div = coins[curindex - 1];
//            count += solution(coins, balance, curindex - 1);
//        }
//
//        if (curindex == 0 && balance != 0) continue;
//
//        answer = min(answer, count);
//    }
//    return answer;
//}

// 방법2. DP
int solutionDP(vector<int>& coins, int balance)
{
    vector<int> dp(balance + 1, MAX);
    dp[0] = 0;

    // 1원부터 필요한 최소동전 세보기.
    for (int i = 1; i <= balance; ++i)
    {
        for (int j = 0; j < coins.size(); ++j)
        {
            if (i - coins[j] >= 0)
            {
                // 이전 값에서 동전하나 추가.
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[balance];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, answer = MAX;
    cin >> n >> k;
    vector<int> coins;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        if (temp == k)
        {
            cout << "1";
            return 0;
        }
        if (temp < k) coins.push_back(temp);
    }
    //sort(coins.begin(), coins.end());
    //coins.erase(unique(coins.begin(), coins.end()), coins.end());
    // 방법 1. 재귀.
    //answer = min(answer, solution(coins, k, coins.size()-1));

    // 방법 2. DP.
    answer = solutionDP(coins, k);

    if (answer >= MAX) cout << "-1";
    else cout << answer;

    return 0;
}