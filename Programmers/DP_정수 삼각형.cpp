// 21.03.19. 금
// DP_정수 삼각형 https://programmers.co.kr/learn/courses/30/lessons/43105
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    auto dp = triangle;
    for(int i=0; i<triangle.size() - 1; ++i)
    {
        for(int j=0; j<triangle[i].size(); ++j)
        {
            dp[i+1][j] = max(dp[i+1][j], triangle[i+1][j] + dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], triangle[i+1][j+1] + dp[i][j]);
            answer = max({dp[i+1][j], dp[i+1][j+1], answer});
        }
    }
    return answer;
}