// 20.10.22. 목
// kakao 2018_프렌즈4블록 https://programmers.co.kr/learn/courses/30/lessons/17679
// BFS(할때 배운 방법) + 완전탐색. IDE 사용 금지!

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    // [0][x] 가 바닥인 벡터로 만들어줍니다.
    // 왜냐! 블록 삭제했을때 알아서 내려오게 하기 위해.
    vector<vector<char> > ground(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            ground[i].push_back(board[j][i]);
        }
    }

    set<pair<int, int> > blocks; // 삭제할 블록들 저장하는 곳. 중복 제거를 위해 set 사용.
    while (1)
    {
        // 완죤 탐색.
        for (int j = m - 1; j > 0; --j)
        {
            for (int i = 0; i < n - 1; ++i)
            {
                char pivot = ground[i][j];
                if (pivot == '0') continue;
                if (pivot == ground[i + 1][j] && pivot == ground[i][j - 1] && pivot == ground[i + 1][j - 1])
                {
                    blocks.insert({ i, j }); blocks.insert({ i + 1, j });
                    blocks.insert({ i, j - 1 }); blocks.insert({ i + 1, j - 1 });
                }
            }
        }
        if (blocks.empty()) break; // 삭제할거 없으면 끝!.
        answer += blocks.size();

        // ground에서 블록 삭제 후, blocks에서 삭제.
        // blocks 뒤에부터 삭제하는 이유는 밑에 블록이 삭제되면 위에서 내려오니까 나머지는 정확한 삭제가 안됨.
        while (!blocks.empty())
        {
            pair<int, int> p = *(--blocks.end());
            vector<char> v = ground[p.first];
            v.erase(v.begin() + p.second);
            ground[p.first] = v;
            blocks.erase(--blocks.end());
            ground[p.first].push_back('0'); // 블록 없는 공간은 '0'으로 만들어줌.
        }
    }

    return answer;
}