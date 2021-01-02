// 21.01.02. 토
// 14500: 테트로미노 https://www.acmicpc.net/problem/14500
// 구현.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, answer = 0, sum, preSum;
    cin >> n >> m;
    vector<vector<int> > pan(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> pan[i][j];

    // ㅣ ㅁ 모양
    int tetroI_1[4][2] = { {0, 0}, {0, 1}, {0, 2}, {0, 3} };
    int tetroI_2[4][2] = { {0, 0}, {1, 0}, {2, 0}, {3, 0} };
    int tetroO[4][2] = { {0, 0}, {1, 0}, {0, 1}, {1, 1} };

    // ㄴ ㄱ S 모양은 6칸(2x3, 3x2) 다 더하고 뺄 자리 좌표.
    int tetro_2x3[8][2][2] = { { {1, 0}, {1, 1} }, { {1, 1}, {1, 2} }, { {0, 0}, {1, 2} }, { {1, 0}, {1, 2} },
                               { {0, 1}, {0, 2} }, { {0, 0}, {0, 1} }, { {0, 2}, {1, 0} }, { {0, 0}, {0, 2} } };
    int tetro_3x2[8][2][2] = { { {1, 1}, {2, 1} }, { {1, 0}, {2, 0} }, { {0, 1}, {2, 0} }, { {0, 1}, {2, 1} },
                               { {0, 0}, {1, 0} }, { {0, 1}, {1, 1} }, { {0, 0}, {2, 1} }, { {0, 0}, {2, 0} } };

    // ㅡ.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m - 3; ++j)
        {
            sum = 0;
            for (int k = 0; k < 4; ++k)
            {
                sum += pan[i + tetroI_1[k][0]][j + tetroI_1[k][1]];
            }
            answer = max(answer, sum);
        }
    }

    // ㅣ.
    for (int i = 0; i < n - 3; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            sum = 0;
            for (int k = 0; k < 4; ++k)
            {
                sum += pan[i + tetroI_2[k][0]][j + tetroI_2[k][1]];
            }
            answer = max(answer, sum);
        }
    }

    // ㅁ.
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            sum = 0;
            for (int k = 0; k < 4; ++k)
            {
                sum += pan[i + tetroO[k][0]][j + tetroO[k][1]];
            }
            answer = max(answer, sum);
        }
    }

    // 2x3.
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            preSum = 0;
            for (int k = i; k < 3 + i; ++k)
            {
                for (int l = j; l < 2 + j; ++l)
                {
                    preSum += pan[k][l];
                }
            }
            for (int k = 0; k < 8; ++k)
            {
                sum = preSum
                    - pan[i + tetro_3x2[k][0][0]][j + tetro_3x2[k][0][1]]
                    - pan[i + tetro_3x2[k][1][0]][j + tetro_3x2[k][1][1]];
                answer = max(answer, sum);
            }
        }
    }

    // 3x2.
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 2; ++j)
        {
            preSum = 0;
            for (int k = i; k < 2 + i; ++k)
            {
                for (int l = j; l < 3 + j; ++l)
                {
                    preSum += pan[k][l];
                }
            }
            for (int k = 0; k < 8; ++k)
            {
                sum = preSum
                    - pan[i + tetro_2x3[k][0][0]][j + tetro_2x3[k][0][1]]
                    - pan[i + tetro_2x3[k][1][0]][j + tetro_2x3[k][1][1]];
                answer = max(answer, sum);
            }
        }
    }

    cout << answer;

    return 0;
}