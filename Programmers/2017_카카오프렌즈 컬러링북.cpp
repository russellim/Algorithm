// 20.10.23. 금
// kakao 2017_카카오프렌즈 컬러링북 https://programmers.co.kr/learn/courses/30/lessons/1829
// BFS. IDE 사용 금지!

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 동서남북 더할 좌표.
    queue<pair<int, int> > q; // 방문한 곳 저장할 큐.
    int ii = 0, jj = 0; // (재)시작점.

    while (1)
    {
        int num = -1, count = 0; // 영역번호, 개수.
        // 시작점 찾기.
        bool bFindStart = false;
        for (int i = ii; i < m; ++i)
        {
            for (int j = jj; j < n; ++j)
            {
                if (picture[i][j] != 0)
                {
                    bFindStart = true;
                    ii = i; jj = j;
                    q.push({ i, j });
                    num = picture[i][j];
                    picture[i][j] = 0;
                    count++;
                    number_of_area++;
                    break;
                }
            }
            if (bFindStart) break;
            jj = 0;
        }
        if (!bFindStart) break; // 찾을거 더 없으면 끝!

        while (!q.empty())
        {
            pair<int, int> pivot = q.front();
            q.pop();
            for (int t = 0; t < 4; ++t)
            {
                int i = pivot.first + direction[t][0];
                int j = pivot.second + direction[t][1];
                if (i >= 0 && j >= 0 && i < m && j < n && picture[i][j] == num)
                {
                    q.push({ i,j });
                    picture[i][j] = 0;
                    count++;
                }
            }
        }
        if (max_size_of_one_area < count) max_size_of_one_area = count;
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}