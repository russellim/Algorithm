// 21.01.22. 금
// 7562: 나이트의 이동 https://www.acmicpc.net/problem/7562
// BFS.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Coord;
Coord operator+(Coord& a, Coord& b)
{
    return { a.first + b.first, a.second + b.second };
}

bool IsRange(int l, Coord& c)
{
    return (c.first >= 0 && c.second >= 0 && c.first < l && c.second < l);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Coord move[8] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
    int t, l, a, b, x, y;
    cin >> t;

    while (t--)
    {
        cin >> l >> a >> b >> x >> y;
        vector<vector<int> > pann(l, vector<int>(l, 2e9));
        queue< Coord> q;
        int count = 0;
        bool IsFind = false;
        pann[a][b] = 0;
        q.push({ a, b });

        if (a == x && b == y)
        {
            cout << "0\n";
            continue;
        }

        while (1)
        {
            Coord now = q.front();
            q.pop();
            count = pann[now.first][now.second] + 1;
            for (int i = 0; i < 8; ++i)
            {
                Coord next = now + move[i];
                if (IsRange(l, next) && pann[next.first][next.second] > count)
                {
                    pann[next.first][next.second] = count;
                    q.push(next);
                    if (next.first == x && next.second == y)
                    {
                        IsFind = true;
                        cout << count << "\n";
                        break;
                    }
                }
            }
            if (IsFind) break;
        }
    }

    return 0;
}