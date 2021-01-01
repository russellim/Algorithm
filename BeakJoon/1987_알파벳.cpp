// 21.01.01. 금
// 1987: 알파벳 https://www.acmicpc.net/problem/1987
// DFS.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define AlphaToNum 65
typedef vector<vector<char> > C;

int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
bool UseAlpha[26]{ false };
string word;
int maxValue = 0;

bool IsRange(int x, int y, int r, int c)
{
    if (x >= 0 && y >= 0 && x < r && y < c) return true;
    return false;
}

void dfs(C& board, int x, int y)
{
    word += board[x][y];
    UseAlpha[board[x][y] - AlphaToNum] = true;
    board[x][y] = '0';
    maxValue = max(maxValue, (int)word.size());

    for (int i = 0; i < 4; ++i)
    {
        int nextx = x + direction[i][0];
        int nexty = y + direction[i][1];
        if (IsRange(nextx, nexty, board.size(), board[0].size())
            && board[nextx][nexty] != '0'
            && !UseAlpha[board[nextx][nexty] - AlphaToNum])
        {
            char c = board[nextx][nexty];
            dfs(board, nextx, nexty);

            board[nextx][nexty] = c;
            UseAlpha[c - AlphaToNum] = false;
            word.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int r, c;
    cin >> r >> c;
    C board(r, vector<char>(c));

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> board[i][j];
        }
    }

    dfs(board, 0, 0);
    cout << maxValue;

    return 0;
}