// 21.01.25. 월
// 1927: 최소 힙 https://www.acmicpc.net/problem/1927
// 우선순위 큐.
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, cmd;
    cin >> n;
    priority_queue<int> q;

    for (int i = 0; i < n; ++i)
    {
        cin >> cmd;
        if (cmd == 0)
        {
            if (q.empty())
            {
                cout << "0\n";
                continue;
            }
            cout << -q.top() << "\n";
            q.pop();
            continue;
        }
        q.push(-cmd);
    }

    return 0;
}