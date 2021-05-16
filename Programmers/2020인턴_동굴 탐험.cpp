// 21.05.07. 금
// kakao 2020인턴_동굴 탐험 https://programmers.co.kr/learn/courses/30/lessons/67260
// BFS.

// 효율성 2,7,8,10 시간초과. 
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> status;
vector<vector<int> > conn;

constexpr int NORMAL = 0;
constexpr int LOCK = -1;
constexpr int VISITED = -2;

int BFS()
{
    int res = 1;
    vector<int> saveLock;
    queue<int> q, qLock;
    q.push(0);
    if (status[0] == LOCK) return 0;
    if (status[0] != NORMAL) status[status[0]] = NORMAL;
    status[0] = VISITED;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < conn[now].size(); ++i)
        {
            int next = conn[now][i];
            if (status[next] == VISITED) continue;
            if (status[next] == LOCK)
            {
                saveLock.push_back(next);
                continue;
            }
            if (status[next] != NORMAL)
            {
                int lock = status[next];
                status[lock] = NORMAL;
            }
            q.push(next);
            status[next] = VISITED;
            ++res;
        }

        for (int i = saveLock.size() - 1; i >= 0; --i)
        {
            int lock = saveLock[i];
            if (status[lock] == LOCK) continue;
            saveLock.erase(saveLock.begin() + i);
            --i;
            q.push(lock);
            status[lock] = VISITED;
            ++res;
        }
    }

    return res;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    status.assign(n + 1, NORMAL);
    conn.assign(n + 1, vector<int>());
    int pathSize = path.size();
    for (int i = 0; i < pathSize; ++i)
    {
        conn[path[i][0]].push_back(path[i][1]);
        conn[path[i][1]].push_back(path[i][0]);
    }
    int orderSize = order.size();
    for (int i = 0; i < orderSize; ++i)
    {
        status[order[i][0]] = order[i][1];
        status[order[i][1]] = LOCK;
    }

    return (BFS() == n);
}