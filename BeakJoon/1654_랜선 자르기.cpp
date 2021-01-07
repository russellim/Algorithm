// 21.01.07. 목
// 1654: 랜선 자르기 https://www.acmicpc.net/problem/1654
// BS.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Cut(vector<int>& v, long long div)
{
    int answer = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        answer += v[i] / div;
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long k, n, start = 1, end, mid, answer = 0;
    cin >> k >> n;
    vector<int> lines(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> lines[i];
    }

    end = *max_element(lines.begin(), lines.end());

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (Cut(lines, mid) >= n)
        {
            start = mid + 1;
            answer = mid;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}