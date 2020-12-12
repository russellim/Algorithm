// 20.12.12. 토
// 1476: 날짜 계산 https://www.acmicpc.net/problem/1476
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int e, s, m;    // 15 ,28, 19.
    cin >> e >> s >> m;
    int answer = 1;
    while (1)
    {
        if ((e - answer) % 15 == 0 && (s - answer) % 28 == 0 && (m - answer) % 19 == 0)
        {
            cout << answer;
            break;
        }
        answer++;
    }

    return 0;
}