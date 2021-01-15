// 21.01.15. 금
// 10026: 적록색약 https://www.acmicpc.net/problem/10026
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Coord;
typedef vector<vector<char> > Print;
int n;

bool IsRange(Coord c)
{
    if (c.first >= 0 && c.second >= 0 && c.first < n && c.second < n) return true;
    return false;
}

// R - G / B.
// 적록색맹 전용. 같은 색인지.
bool IsSameColor(char next, char color)
{
    if (next == '0') return false;

    if (color == 'B' && next == 'B') return true;
    else if (color != 'B' && next != 'B') return true;
    return false;
}

Coord FindStart(Print& p, int i, int j)
{
    for (i; i < n; ++i)
    {
        for (j; j < n; ++j)
        {
            if (p[i][j] != '0')
            {
                return { i, j };
            }
        }
        j = 0;
    }
    return { -1, -1 };
}

int BFS(Print p, bool rg) // rg : 색맹여부.
{
    int answer = 0;
    int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    Coord start = { 0, 0 };
    queue<Coord> q;
    char color;
    while (1)
    {
        start = FindStart(p, start.first, start.second);
        if (start.first == -1) break;
        answer++;
        color = p[start.first][start.second];
        p[start.first][start.second] = '0';
        q.push(start);

        while (!q.empty())
        {
            Coord now = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                Coord next = { now.first + direction[i][0], now.second + direction[i][1] };
                if (IsRange(next) && ((rg && IsSameColor(p[next.first][next.second], color)) || (!rg && p[next.first][next.second] == color)))
                {
                    q.push(next);
                    p[next.first][next.second] = '0';
                }
            }
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    Print print(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> print[i][j];
        }
    }

    cout << BFS(print, false) << " " << BFS(print, true);

    return 0;
}