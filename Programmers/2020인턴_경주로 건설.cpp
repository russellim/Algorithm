// 21.05.04. 화
// kakao 2020인턴_경주로 건설 https://programmers.co.kr/learn/courses/30/lessons/67259
// BFS.

// BFS visited 탐색을 3번까지 허용해주니 풀렸다. 이래도 되는것인가!??!
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int STRAIGHT = 100;
constexpr int TURN = 500;
constexpr int EMPTY = 0;
constexpr int WALL = 1;
constexpr int VISITED = 2;
struct Pos
{
    int x, y;
    friend Pos operator+(Pos& a, Pos& b)
    {
        return { a.x + b.x, a.y + b.y };
    }
};
struct Status
{
    Pos pos;
    int dir;
    int cost;
};
struct cmp
{
    bool operator()(Status& a, Status& b)
    {
        return a.cost > b.cost;
    }
};
Pos direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int answer = 2e9;

bool IsRange(Pos& pos, int boardSize)
{
    return (pos.x >= 0 && pos.y >= 0 && pos.x < boardSize&& pos.y < boardSize);
}

void BFS(vector<vector<int>>& board)
{
    int boardSize = board.size();
    priority_queue<Status, vector<Status>, cmp> pq;
    pq.push({ {0, 0}, -1, 0 });
    board[0][0] = VISITED;

    while (!pq.empty())
    {
        Pos nowPos = pq.top().pos;
        int nowDir = pq.top().dir;
        int nowCost = pq.top().cost;
        pq.pop();

        for (int i = 0; i < 4; ++i)
        {
            Pos nextPos = nowPos + direction[i];
            if (!IsRange(nextPos, boardSize)) continue;
            if (board[nextPos.x][nextPos.y] == WALL || board[nextPos.x][nextPos.y] == 4) continue;

            int nextCost;
            if (nowDir == -1 || nowDir == i) nextCost = nowCost + STRAIGHT;
            else nextCost = nowCost + STRAIGHT + TURN;

            if (nextPos.x == boardSize - 1 && nextPos.y == boardSize - 1)
            {
                answer = min(answer, nextCost);
            }

            if (board[nextPos.x][nextPos.y] >= VISITED) board[nextPos.x][nextPos.y]++;
            else board[nextPos.x][nextPos.y] = VISITED;

            pq.push({ nextPos, i, nextCost });

        }
    }
}

int solution(vector<vector<int>> board) {

    BFS(board);
    return answer;
}