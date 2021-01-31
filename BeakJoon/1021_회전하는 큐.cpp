// 21.01.31. 일
// 1021: 회전하는 큐 https://www.acmicpc.net/problem/1021
// deque.
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, count = 0, num, index = 0;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 0; i < n; ++i) dq.push_back(i + 1);

    while (m--)
    {
        cin >> num;
        if (dq.front() == num)
        {
            dq.pop_front();
            continue;
        }

        for (auto it = dq.begin(); it != dq.end(); ++it)
        {
            if (*it == num)
            {
                index = it - dq.begin();
                break;
            }
        }

        if (index <= dq.size() / 2)
            while (index--)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
        else
            while (dq.size() - index++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
        dq.pop_front();
    }
    cout << count;

    return 0;
}