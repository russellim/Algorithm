// 20.12.10. 목
// kakao 2020_기둥과 보 설치 https://programmers.co.kr/learn/courses/30/lessons/60061
// 구현.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 기둥 생성 조건.
bool IsCreatePillar(vector<vector<int> >& P, vector<vector<int> >& B, int x, int y)
{
    if (y == 0 || (x > 0 && B[x - 1][y] == 1) || B[x][y] == 1 || P[x][y - 1] == 1)
        return true;
    return false;
}

// 보 생성 조건.
bool IsCreateBeam(vector<vector<int> >& P, vector<vector<int> >& B, int x, int y)
{
    if (P[x][y - 1] == 1 || (x < P.size() - 1 && P[x + 1][y - 1] == 1) || (x > 0 && B[x - 1][y] == 1 && x < B.size() - 1 && B[x + 1][y] == 1))
        return true;
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int> > Pillars(n + 1, vector<int>(n + 1, 0));
    vector<vector<int> > Beams(n + 1, vector<int>(n + 1, 0));
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
                if (!IsCreatePillar(Pillars, Beams, x, y)) continue;
                Pillars[x][y] = 1;
            }
            else    // 보.
            {
                if (!IsCreateBeam(Pillars, Beams, x, y)) continue;
                Beams[x][y] = 1;
            }
        }
        // 삭제 (일단 삭제 해놓고 주변 기둥, 보가 생성조건에 위배되는가? -> true면 삭제 무시).
        else
        {
            if (build_frame[i][2] == 0) // 기둥.
            {
                Pillars[x][y] = 0;
                if ((y < n - 1 && Pillars[x][y + 1] == 1 && !IsCreatePillar(Pillars, Beams, x, y + 1)) ||
                    (y < n - 1 && Beams[x][y + 1] == 1 && !IsCreateBeam(Pillars, Beams, x, y + 1)) ||
                    (y < n - 1 && x  > 0 && Beams[x - 1][y + 1] == 1 && !IsCreateBeam(Pillars, Beams, x - 1, y + 1)))
                    Pillars[x][y] = 1;
            }
            else
            {
                Beams[x][y] = 0;
                if ((x < n - 1 && Pillars[x + 1][y] == 1 && !IsCreatePillar(Pillars, Beams, x + 1, y)) ||
                    (Pillars[x][y] == 1 && !IsCreatePillar(Pillars, Beams, x, y)) ||
                    (x > 0 && Beams[x - 1][y] == 1 && !IsCreateBeam(Pillars, Beams, x - 1, y)) ||
                    (x < n - 1 && Beams[x + 1][y] == 1 && !IsCreateBeam(Pillars, Beams, x + 1, y)))
                    Beams[x][y] = 1;
            }
        }
    }

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            if (Pillars[i][j] == 1)
            {
                answer.push_back({ i,j, 0 });
            }
            if (Beams[i][j] == 1)
            {
                answer.push_back({ i,j, 1 });
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<vector<int>> v;
    v = solution(5, { {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} });
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    v = solution(5, { {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} });
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}