// 20.12.30. 수
// 2583: 영역 구하기 https://www.acmicpc.net/problem/2583
// BFS.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<vector<bool> > B;
typedef pair<int, int> Coord;

bool IsRange(int i, int j, int m, int n)
{
    if (i >= 0 && j >= 0 && i < m && j < n) return true;
    return false;
}

Coord FindBFSStart(B& paper, int m, int n, int i, int j)
{
    for (i; i < m; ++i)
    {
        for (j; j < n; ++j)
        {
            if (paper[i][j] == true)
            {
                paper[i][j] = false;
                return { i, j };
            }
        }
        j = 0;
    }
    return { -1, -1 };
}

void BFS(B& paper, int m, int n)
{
    int direction[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    queue<Coord> q;
    int starti = 0, startj = 0, count = 0, areatemp;
    vector<int> areas;
    while (1)
    {
        q.push(FindBFSStart(paper, m, n, starti, startj));
        if (q.front().first == -1) break;
        areatemp = 1;
        count++;
        starti = q.front().first;
        startj = q.front().second;
        while (!q.empty())
        {
            Coord now = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d)
            {
                Coord next = { now.first + direction[d][0], now.second + direction[d][1] };
                if (IsRange(next.first, next.second, m, n) && paper[next.first][next.second] == true)
                {
                    areatemp++;
                    paper[next.first][next.second] = false;
                    q.push(next);
                }
            }
        }
        areas.push_back(areatemp);
    }
    sort(areas.begin(), areas.end());
    cout << count << "\n";
    for (int x : areas) cout << x << " ";
}

void Punching(B& paper, int k)
{
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; ++i)
        {
            for (int j = x1; j < x2; ++j)
            {
                paper[i][j] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, n, k;
    cin >> m >> n >> k;
    // 직사각형 모양만큼 빼는거니까 구멍인지 아닌지만 판별(bool).
    B paper(m, vector<bool>(n, true));

    Punching(paper, k);
    BFS(paper, m, n);

    return 0;
}