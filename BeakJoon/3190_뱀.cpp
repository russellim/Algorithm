// 21.01.16. 토
// 3190: 뱀 https://www.acmicpc.net/problem/3190

// 다 풀고 보니 앞으로 가기, 데크 앞뒤만 생성 삭제 하면 더 짧고 빠를 것 같다.

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Coord;
// pair<int, int> + 오버로딩.
Coord operator+(const Coord& x, const Coord& y)
{
    return { x.first + y.first, x.second + y.second };
}

struct Snake
{
    Coord front;
    Coord now;

public:
    Snake(Coord f, Coord n) : front(f), now(n) {};
};

// 방향 변환 정보 -> int 방향값.
int CmdToInt(char c, int d)
{
    int res;
    if (c == 'D')
    {
        res = d + 1;
        if (res > 3) res = 0;
    }
    else
    {
        res = d - 1;
        if (res < 0) res = 3;
    }

    return res;
}

bool IsRange(int n, int r, int c)
{
    if (r >= 0 && c >= 0 && r < n && c < n) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 0동 1남 2서 3북.
    int d = 0;
    // 방향별 직진좌표.
    Coord direction[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    int n, k, l, answer = 0;
    cin >> n >> k;
    // 0빈곳, 1사과, 2뱀.
    vector<vector<int> > mapp(n, vector<int>(n, 0));
    vector<Snake> snake;
    snake.push_back(Snake({ -1, -1 }, { 0, 0 }));
    mapp[0][0] = 2;
    // 사과 설치.
    for (int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        mapp[a - 1][b - 1] = 1;
    }
    // 명령 받기.
    cin >> l;
    vector<pair<int, char> > cmd;
    for (int i = 0; i < l; ++i)
    {
        int x;
        char c;
        cin >> x >> c;
        cmd.push_back({ x, c });
    }
    cmd.push_back({ '0', 10001 });

    // 시작.
    for (int i = 0; i <= l; ++i)
    {
        while (cmd[i].first != answer)
        {
            answer++;
            bool IsEatApple = false;
            for (int s = 0; s < snake.size(); ++s)
            {
                // 머리.
                if (snake[s].front.first == -1)
                {
                    auto body = snake[s];
                    auto now = snake[s].now;
                    mapp[now.first][now.second] = 0;
                    now = now + direction[d];
                    if (!IsRange(n, now.first, now.second) || mapp[now.first][now.second] == 2)
                    {
                        cout << answer;
                        return 0;
                    }
                    if (mapp[now.first][now.second] == 1) IsEatApple = true; // 사과 먹음.
                    mapp[now.first][now.second] = 2;
                    snake[s].now = now;

                    // 사과먹고 하나만 있을때 뒤에 늘려주기.
                    if (snake.size() == 1 && IsEatApple)
                    {
                        snake.push_back(body);
                        mapp[body.now.first][body.now.second] = 2;
                        snake.back().front = now;
                        break;
                    }
                }
                // 꼬리, 몸통.
                else
                {
                    auto body = snake[s];
                    auto now = snake[s].now;
                    auto fr = snake[s].front;
                    mapp[now.first][now.second] = 0;
                    mapp[fr.first][fr.second] = 2;
                    snake[s].now = fr;
                    snake[s].front = snake[s - 1].now;

                    if (s == snake.size() - 1 && IsEatApple) // 사과 먹어서 늘어남.
                    {
                        snake.push_back(body);
                        mapp[now.first][now.second] = 2;
                        break;
                    }
                }
            }
        }
        // 방향 전환.
        d = CmdToInt(cmd[i].second, d);
    }

    return 0;
}