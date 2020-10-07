// 20.10.07. 수
// 2019 카카오겨울인턴: 크레인 인형뽑기 게임  https://programmers.co.kr/learn/courses/30/lessons/64061
// Stack, IDE 사용 금지!
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    vector<stack<int>> st(size, stack<int>());
    stack<int> ansst;
    for (int i = size - 1; i >= 0; --i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j] != 0)
                st[j].push(board[i][j]);
        }
    }
    int prev = -1;
    for (int i = 0; i < moves.size(); ++i)
    {
        if (st[moves[i] - 1].empty())
        {
            continue;
        }
        ansst.push(st[moves[i] - 1].top());
        st[moves[i] - 1].pop();
        if (prev == ansst.top())
        {
            answer += 2;
            ansst.pop(); ansst.pop();
        }
        if (!ansst.empty()) prev = ansst.top();
        else prev = -1;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cout << solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1,5,3,5,1,2,1,4 });

    return 0;
}