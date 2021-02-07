// 21.02.07. 일
// 10819: 차이를 최대로 https://www.acmicpc.net/problem/10819
// 백트래킹, 브루트포스.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution
{
#define DONTUSE -200
    int n, answer = 0;
    vector<int> arr, brute;

    int Calcul()
    {
        int result = 0;
        for (int i = 1; i < n; ++i)
        {
            result += abs(brute[i - 1] - brute[i]);
        }
        return result;
    }

    void BT(int count)
    {
        if (count == arr.size())
        {
            answer = max(answer, Calcul());
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == DONTUSE) continue;
            brute.push_back(arr[i]);
            arr[i] = DONTUSE;
            BT(count + 1);
            arr[i] = brute.back();
            brute.pop_back();
        }
    }

    void Output()
    {
        cout << answer;
    }
    void Input()
    {
        cin >> n;
        arr.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Solution::Input();
    Solution::BT(0);
    Solution::Output();

    return 0;
}