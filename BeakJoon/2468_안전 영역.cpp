// 20.12.22. 화
// 2468: 안전 영역 https://www.acmicpc.net/problem/2468
// BFS, 브루트포스.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> FindStart(vector<vector<int> >& v, int size, int i, int j)
{
    for (i; i < size; ++i)
    {
        for (j; j < size; ++j)
        {
            if (v[i][j] == 1)
            {
                v[i][j] = 0;
                return { i, j };
            }
        }
        j = 0;
    }
    return { -1, -1 };
}

int bfs(vector<vector<int> >& safe, int size)
{
    auto copy = safe;   // bfs로 확인할 safe지도 복사.
    queue<pair<int, int> >q;
    pair<int, int>startPoint = { 0, 0 };
    int direction[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    int island = 0;

    while (1)
    {
        startPoint = FindStart(copy, size, startPoint.first, startPoint.second);
        if (startPoint.first == -1) break;
        island++;
        q.push(startPoint);

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nextx = x + direction[i][0];
                int nexty = y + direction[i][1];
                if (nextx >= 0 && nextx < size && nexty >= 0 && nexty < size && copy[nextx][nexty] == 1)
                {
                    copy[nextx][nexty] = 0;
                    q.push({ nextx, nexty });
                }
            }
        }
    }
    return island;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, answer = 1; // 비가 안오는 경우(모든 지역 safe)
    cin >> n;
    vector<vector<pair<int, int> > > depth(101, vector<pair<int, int> >()); //깊이 좌표모음.(1~100)
    vector<vector<int> > mapp(n, vector<int>(n, 1));
    auto safe = mapp;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mapp[i][j];
            depth[mapp[i][j]].push_back({ i, j });
        }
    }

    for (int i = 1; i <= 100; ++i)
    {
        if (depth[i].size() == 0) continue;
        for (int j = 0; j < depth[i].size(); ++j)
        {
            safe[depth[i][j].first][depth[i][j].second] = 0;
        }
        answer = max(answer, bfs(safe, n));
    }

    cout << answer;

    return 0;
}