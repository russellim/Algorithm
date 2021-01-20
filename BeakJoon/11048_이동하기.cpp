// 21.01.19. 화
// 11048: 이동하기 https://www.acmicpc.net/problem/11048
// DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > mapp(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mapp[i][j];
            if (i == 0 && j == 0) continue;
            else if (i == 0) mapp[i][j] += mapp[i][j - 1];
            else if (j == 0) mapp[i][j] += mapp[i - 1][j];
            else mapp[i][j] += max({ mapp[i - 1][j], mapp[i][j - 1], mapp[i - 1][j - 1] });
        }
    }
    cout << mapp[n - 1][m - 1];

    return 0;
}