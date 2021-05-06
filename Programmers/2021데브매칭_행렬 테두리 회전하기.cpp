// 21.05.06. 목
// 2021데브매칭_행렬 테두리 회전하기 https://programmers.co.kr/learn/courses/30/lessons/77485
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Coord
{
    int x, y;
};

int Rotate(vector<vector<int>>& pann, Coord leftup, Coord rightdown)
{
    Coord now = leftup;
    Coord next = now;
    int res = pann[now.x][now.y];
    while (next.x != rightdown.x)
    {
        next.x++;
        res = min(res, pann[next.x][next.y]);
        swap(pann[now.x][now.y], pann[next.x][next.y]);
        now = next;
    }
    while (next.y != rightdown.y)
    {
        next.y++;
        res = min(res, pann[next.x][next.y]);
        swap(pann[now.x][now.y], pann[next.x][next.y]);
        now = next;
    }
    while (next.x != leftup.x)
    {
        next.x--;
        res = min(res, pann[next.x][next.y]);
        swap(pann[now.x][now.y], pann[next.x][next.y]);
        now = next;
    }
    while (next.y != leftup.y + 1)
    {
        next.y--;
        res = min(res, pann[next.x][next.y]);
        swap(pann[now.x][now.y], pann[next.x][next.y]);
        now = next;
    }

    return res;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int> > pann(rows, vector<int>(columns));
    int count = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            pann[i][j] = ++count;
        }
    }

    for (int cmd = 0; cmd < queries.size(); ++cmd)
    {
        answer.push_back(Rotate(pann, { queries[cmd][0] - 1, queries[cmd][1] - 1 }, { queries[cmd][2] - 1, queries[cmd][3] - 1 }));
    }
    return answer;
}