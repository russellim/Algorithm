// 21.01.27. 수
// 2206: 벽 부수고 이동하기 https://www.acmicpc.net/problem/2206
// BFS.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define EMPTY 0
#define WALL -1
#define MAX 1e9
#define DirectionCount 4

int n, m;
vector<vector<int> > maze;

typedef pair<int, int> Coord;
Coord operator+(Coord& a, Coord& b)
{
    return { a.first + b.first, a.second + b.second };
}

struct WalkState
{
    Coord pos;              // 현재위치.
    bool isDestroyBlock;    // 벽 부쉈는지 여부.
    int walkCount;          // 현재까지 걸음 수.

    WalkState(Coord pos, bool isDestroyBlock, int walkCount) : pos(pos), isDestroyBlock(isDestroyBlock), walkCount(walkCount) { }
};

bool IsRange(Coord coord)
{
    return (coord.first >= 0 && coord.second >= 0 && coord.first < n&& coord.second < m);
}

int BFS()
{
    int answer = 1;
    Coord direction[DirectionCount] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    queue<WalkState> q;
    q.push(WalkState({ 0, 0 }, false, 1));

    while (!q.empty())
    {
        WalkState now = q.front();
        q.pop();

        for (int i = 0; i < DirectionCount; ++i)
        {
            Coord next = now.pos + direction[i];
            if (!IsRange(next)) continue;


            if (maze[next.first][next.second] == WALL && !now.isDestroyBlock)
            {
                q.push(WalkState(next, true, now.walkCount + 1));
            }
            else if (maze[next.first][next.second] == EMPTY || maze[next.first][next.second] > now.walkCount + 1)
            {
                if (now.isDestroyBlock && maze[next.first][next.second] == MAX) continue;

                q.push(WalkState(next, now.isDestroyBlock, now.walkCount + 1));
                if (!now.isDestroyBlock) maze[next.first][next.second] = now.walkCount + 1;
                else maze[next.first][next.second] = MAX;
            }

            if (next.first == n - 1 && next.second == m - 1)
                return now.walkCount + 1;
        }
    }

    return maze[n - 1][m - 1] == 0 ? MAX : answer;
}

void MakeMaze()
{
    char input;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> input;
            if (input == '1')
            {
                maze[i][j] = WALL;
            }
            else
            {
                maze[i][j] = EMPTY;
            }
        }
    }
    maze[0][0] = 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int answer = MAX;
    cin >> n >> m;
    maze.assign(n, vector<int>(m));

    MakeMaze();

    answer = BFS();

    cout << (answer == MAX ? -1 : answer);

    return 0;
}