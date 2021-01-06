// 21.01.06. 수
// 7569: 토마토 https://www.acmicpc.net/problem/7569
// BFS.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool IsRange(int h, int n, int m, int H, int X, int Y)
{
    if (H >= 0 && H < h && X >= 0 && X < n && Y >= 0 && Y < m)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, n, h, answer = 0;
    bool IsZeroExist = false;
    cin >> m >> n >> h;
    int direction[6][3] = { {-1, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
    vector<vector<vector<int> > > box(h, vector<vector<int> >(n, vector<int>(m)));
    queue < pair<int, pair<int, int> > > q; // 검사할 좌표 큐.
    auto tempQ = q; // 검사해서 나온 안익은 도마도 큐.

    for (int k = 0; k < h; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> box[k][i][j];
                if (box[k][i][j] == 1)
                {
                    box[k][i][j] = -1;
                    q.push({ k, {i, j} });
                }
                // 안익은 토마토 있는지 검사.
                if (!IsZeroExist && box[k][i][j] == 0)
                    IsZeroExist = true;
            }
        }
    }

    // 안익은 토마토가 없을 경우, 바로 끝.
    if (!IsZeroExist)
    {
        cout << "0";
        return 0;
    }

    while (1)
    {
        if (q.empty())
        {
            if (tempQ.empty()) break;
            // 검사할 큐 교체.
            answer++;
            q = tempQ;
            tempQ = {};
        }

        int H = q.front().first;
        int X = q.front().second.first;
        int Y = q.front().second.second;
        q.pop();
        for (int i = 0; i < 6; ++i)
        {
            int nextH = H + direction[i][0];
            int nextX = X + direction[i][1];
            int nextY = Y + direction[i][2];
            if (IsRange(h, n, m, nextH, nextX, nextY) && box[nextH][nextX][nextY] == 0)
            {
                box[nextH][nextX][nextY] = -1;
                tempQ.push({ nextH, {nextX, nextY} });
            }
        }
    }

    // 다 검사하고도 안익은것 있는가?
    for (int k = 0; k < h; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (box[k][i][j] == 0)
                {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    cout << answer;

    return 0;
}