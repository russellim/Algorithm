// 21.01.17. 일
// 14499: 주사위 굴리기 https://www.acmicpc.net/problem/14499
// 구현.
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Coord;
Coord operator+(Coord& a, Coord& b)
{
    return { a.first + b.first, a.second + b.second };
}

bool IsRange(int n, int m, Coord pos)
{
    if (pos.first >= 0 && pos.second >= 0 && pos.first < n && pos.second < m) return true;
    return false;
}

// 주사위 움직임.
void Diceroll(vector<int>& dice, int direction)
{
    int temp = dice[3];
    switch (direction)
    {
    case 1:
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
        break;
    case 2:
        dice[3] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
        break;
    case 3:
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[0];
        dice[0] = temp;
        break;
    case 4:
        dice[3] = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
        break;
    default:
        break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //1동 2서 3북 4남.
    Coord direction[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
    int n, m, k, cmd;
    Coord pos;
    cin >> n >> m >> pos.first >> pos.second >> k;
    vector<vector<int> > mapp(n, vector<int>(m));
    /* 주사위 전개도
       0
     4 1 5
       2
       3             */
    vector<int> dice(6, 0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mapp[i][j];


    // 명령 고.
    for (int i = 0; i < k; ++i)
    {
        cin >> cmd;
        Coord next = pos + direction[cmd - 1];
        if (!IsRange(n, m, next)) continue; // 맵 범위 나가면 명령 무시.
        pos = next;
        Diceroll(dice, cmd);
        cout << dice[1] << "\n";
        if (mapp[pos.first][pos.second] == 0) mapp[pos.first][pos.second] = dice[3];
        else dice[3] = mapp[pos.first][pos.second];
    }

    return 0;
}