// 21.02.05. 금
// 13460: 구슬 탈출 2 https://www.acmicpc.net/problem/13460
// BFS.

// 시간초과! 반례도 다시 살펴볼것.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Coord;
Coord operator+(Coord& a, Coord& b)
{
    return { a.first + b.first, a.second + b.second };
}
struct CoordState
{
    Coord R;
    Coord B;
    int d;
    int count;
};
// {방향, 반대방향 인덱스}.
pair<Coord, int> direction[4] = { {{0,1}, 1}, {{0,-1}, 0}, {{1, 0}, 3}, {{-1, 0}, 2} };
int n, m;
vector<vector<char> > mapp;
Coord InitR, InitB;

CoordState MoveObj(Coord R, Coord B, int d)
{
    bool RGoal = false;
    while (1)
    {
        bool IsMove = false;
        Coord nextR = R + direction[d].first;
        Coord nextB = B + direction[d].first;

        while (nextR != B && (mapp[nextR.first][nextR.second] == '.' || mapp[nextR.first][nextR.second] == 'O'))
        {
            if (mapp[nextR.first][nextR.second] == 'O')
            {
                RGoal = true;
                R = { -1, -1 };
                break;
            }
            IsMove = true;
            R = nextR;
            nextR = R + direction[d].first;
        }
        while (nextB != R && (mapp[nextB.first][nextB.second] == '.' || mapp[nextB.first][nextB.second] == 'O'))
        {
            if (mapp[nextB.first][nextB.second] == 'O') return { R, B, d, -1 };
            IsMove = true;
            B = nextB;
            nextB = B + direction[d].first;
        }
        if (RGoal) return { R, B, d, 1 };
        if (!IsMove) return { R, B, d, 0 };
    }
}

int bfs()
{
    pair<Coord, int> direction[4] = { {{0,1}, 1}, {{0,-1}, 0}, {{1, 0}, 3}, {{-1, 0}, 2} }; // {방향, 반대방향 인덱스}.
    queue<CoordState> q; // {현재 좌표, 왔던 방향}
    q.push({ InitR, InitB , 0, 0 });
    bool bIsFirstSearch = true;

    while (!q.empty())
    {
        Coord nowR = q.front().R;
        Coord nowB = q.front().B;
        int d = q.front().d;
        int count = q.front().count;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            // 0. 온 방향의 반대방향은 탐색 X.
            if (!bIsFirstSearch && i == d) continue;
            // 1. 뚫린 방향 찾기.
            Coord next = nowR + direction[i].first;
            if (mapp[next.first][next.second] == '#') continue;
            // 2. 찾은 방향으로 R B 이동.
            CoordState CurState = MoveObj(nowR, nowB, i);
            if (CurState.count == 0)
            {
                if (nowR == CurState.R && nowB == CurState.B) continue;
                q.push({ CurState.R, CurState.B, direction[i].second, count + 1 });
            }
            else if (CurState.count == 1) return count + 1;
        }
        bIsFirstSearch = false;
    }
    return -1;
}

void InputMapp()
{
    cin >> n >> m;
    mapp.assign(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mapp[i][j];
            if (mapp[i][j] == 'R')
            {
                InitR = { i,j };
                mapp[i][j] = '.';
            }
            if (mapp[i][j] == 'B')
            {
                InitB = { i,j };
                mapp[i][j] = '.';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    InputMapp();
    cout << bfs();

    return 0;
}