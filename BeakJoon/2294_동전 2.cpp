// 21.01.26. 화
// 2294: 동전 2 https://www.acmicpc.net/problem/2294
// DP.

// 재귀는 시간초과.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1e9

int solution(vector<int>& coins, int InitBalance, int curindex)
{
    int answer = MAX;
    int firstCoinMaxCount = InitBalance / coins[curindex];

    for (int i = firstCoinMaxCount; i >= 0; --i)
    {
        int balance = InitBalance, div = coins[curindex], count = 0;
        count = i;
        balance -= (div * i);

        if (balance == 0)
        {
            answer = min(answer, count);
            return answer;
        }

        if (curindex != 0)
        {
            div = coins[curindex - 1];
            count += solution(coins, balance, curindex - 1);
        }

        if (curindex == 0 && balance != 0) continue;

        answer = min(answer, count);
    }
    return answer;
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
    sort(coins.begin(), coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end());

    answer = min(answer, solution(coins, k, coins.size() - 1));

    if (answer >= MAX) cout << "-1";
    else cout << answer;

    return 0;
}