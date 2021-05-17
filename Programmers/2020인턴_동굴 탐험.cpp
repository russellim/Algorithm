// 21.05.07. 금
// kakao 2020인턴_동굴 탐험 https://programmers.co.kr/learn/courses/30/lessons/67260
// BFS.

// 원소 개수가 많으면 vector보다 set의 find가 빠르다.
// 잠긴문 저장할 컨테이너를 set으로 했더니 시간초과가 없어짐!
// find, erase 사용.
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

vector<int> status;
vector<vector<int> > conn;
set<int> storeLock;

constexpr int NORMAL = 0;
constexpr int LOCK = -1;
constexpr int VISITED = -2;

int BFS()
{
    int res = 1;
    queue<int> q;
    q.push(0);
    if (status[0] == LOCK) return 0; // 입구가 잠겨있으면 실패.
    if (status[0] != NORMAL) status[status[0]] = NORMAL; // 입구가 열쇠.
    status[0] = VISITED;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int& next : conn[now])
        {
            if (status[next] == VISITED) continue;   // 방문 했다면.
            if (status[next] == LOCK)    // 잠겨있다면.
            {
                storeLock.insert(next);
                continue;
            }
            if (status[next] != NORMAL)  // 열쇠가 있다면.
            {
                int lock = status[next];
                status[lock] = NORMAL;
                if (storeLock.find(lock) != storeLock.end())
                {
                    storeLock.erase(lock);
                    q.push(lock);
                    status[lock] = VISITED;
                    ++res;
                }
            }

            q.push(next);
            status[next] = VISITED;
            ++res;
        }
    }

    return res;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    status.assign(n + 1, NORMAL);
    conn.assign(n + 1, vector<int>());
    for (auto& x : path)
    {
        conn[x[0]].push_back(x[1]);
        conn[x[1]].push_back(x[0]);
    }
    for (auto& x : order)
    {
        status[x[0]] = x[1];
        status[x[1]] = LOCK;
    }

    return BFS() == n;
}