// 20.12.28. 월
// 14503: 로봇 청소기 https://www.acmicpc.net/problem/14503
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, r, c, d, clean = 0;
    cin >> n >> m >> r >> c >> d;
    // 각 방향의 왼쪽좌표, 다음 방향. ( 0: 북, 1: 동, 2: 남, 3: 서).
    int rotate[4][3] = { {0, -1, 3}, {-1, 0, 0}, {0, 1, 1}, {1, 0, 2} };
    // 각 방향의 후진좌표. 방향은 유지.
    int backward[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
    vector<vector<int> > room(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> room[i][j];
        }
    }

    while (1)
    {
        if (room[r][c] == 0) // 현재 위치 청소.
        {
            room[r][c] = 2;
            clean++;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nextr = r + rotate[d][0];
            int nextc = c + rotate[d][1];

            // 방 테두리는 벽이니까 좌표 범위 검사는 안합니다.

            if (room[nextr][nextc] == 0)
            {
                d = rotate[d][2];
                r = nextr;
                c = nextc;
                break;
            }
            d = rotate[d][2];

            // 네방향 청소할 곳 없음.
            if (i == 3)
            {
                nextr = r + backward[d][0];
                nextc = c + backward[d][1];
                if (room[nextr][nextc] == 1) // 뒤에 벽(종료).
                {
                    cout << clean;
                    return 0;
                }
                r = nextr;
                c = nextc;
            }
        }
    }

    return 0;
}