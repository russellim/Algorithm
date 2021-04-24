// 21.04.15. 목
// 1806: 부분합 https://www.acmicpc.net/problem/1806
// 부분합 -> 투 포인트.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_1806
{
    constexpr int MAX = 1e9;
    void Solution()
    {
        int answer = MAX;
        int n, s;
        cin >> n >> s;
        vector<int> nums(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }

        int start = 0, end = 0;
        int sum = 0;
        while (start <= end)
        {
            if (sum >= s)
            {
                answer = min(answer, end - start);
                sum -= nums[start++];
            }
            else if (end == n) break; // 끝.
            else sum += nums[end++];
        }

        // output.
        if (answer == MAX) cout << "0";
        else cout << answer;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    BOJ_1806::Solution();

    return 0;
}