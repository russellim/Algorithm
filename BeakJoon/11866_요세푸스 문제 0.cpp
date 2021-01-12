// 21.01.12. 화
// 11866: 요세푸스 문제 0 https://www.acmicpc.net/problem/11866
// 큐.
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        q.push(i + 1);
    }

    cout << "<";
    while (q.size() != 1)
    {
        for (int i = 0; i < k - 1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";

    return 0;
}