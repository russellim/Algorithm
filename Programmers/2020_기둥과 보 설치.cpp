// 20.12.10. 목
// kakao 2020_기둥과 보 설치 https://programmers.co.kr/learn/courses/30/lessons/60061

// fail.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int> > create(n + 1, vector<int>(n + 1, -1));
    vector<vector<int> > answer;
    for (int i = 0; i < build_frame.size(); ++i)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        // 설치.
        if (build_frame[i][3] == 1)
        {
            if (build_frame[i][2] == 0) // 기둥.
            {
                if (y > 0 && !((y > 0 && create[x][y - 1] == 0) || (x > 0 && create[x - 1][y] == 1) || create[x][y] == 1))
                    continue;
                create[x][y] = 0;
            }
            else    // 보.
            {
                create[x][y] = 1;
            }
        }
        // 삭제.
        else
        {
            if (build_frame[i][2] == 0) // 기둥.
            {
                create[x][y] = -1;
            }
            else
            {
                if (!((x > 0 && y > 0 && create[x - 1][y - 1] == 0) && (y > 0 && create[x + 1][y - 1] == 0)))
                    continue;
                create[x][y] = -1;
            }
        }
    }

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            if (create[i][j] != -1)
            {
                answer.push_back({ i,j, create[i][j] });
            }
        }
    }

    return answer;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solution(5, { {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} });

    return 0;
}