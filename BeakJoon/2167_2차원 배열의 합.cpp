// 21.01.24. 일
// 2167: 2차원 배열의 합 https://www.acmicpc.net/problem/2167
// 구현, 누적 합.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    int k, i, j, x, y;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));


    // 방법1. 매번 더해서 구하는 방식. 400ms
    //for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) cin >> v[i][j];
    //cin >> k;
    //while (k--)
    //{
    //    int sum = 0;
    //    cin >> i >> j >> x >> y;
    //    for (int a = i - 1; a < x; ++a) for (int b = j - 1; b < y; ++b) sum += v[a][b];
    //    cout << sum << "\n";
    //}


    // 방법2. 누적 합으로 구한 값. 12ms.
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            cin >> v[i][j];
            if (i == 0 && j == 0) continue;
            else if (i == 0) v[i][j] += v[i][j - 1];
            else if (j == 0) v[i][j] += v[i - 1][j];
            else v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            ;
        }
    }

    cin >> k;
    while (k--)
    {
        cin >> i >> j >> x >> y;
        if (i == 1 && j == 1) cout << v[x - 1][y - 1];
        else if (x == 1) cout << v[x - 1][y - 1] - v[i - 1][j - 2];
        else if (y == 1) cout << v[x - 1][y - 1] - v[i - 2][j - 1];
        else if (i == 1) cout << v[x - 1][y - 1] - v[x - 1][j - 2];
        else if (j == 1) cout << v[x - 1][y - 1] - v[i - 2][y - 1];
        else cout << v[x - 1][y - 1] - v[i - 2][y - 1] - v[x - 1][j - 2] + v[i - 2][j - 2];

        cout << "\n";
    }

    return 0;
}