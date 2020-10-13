// 20.10.13. 화
// 스택/큐_주식가격 https://programmers.co.kr/learn/courses/30/lessons/42584
// IDE 사용 금지.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    for (int i = 0; i < prices.size() - 1; ++i)
    {
        for (int j = i + 1; j < prices.size(); ++j)
        {
            if (prices[i] > prices[j])
            {
                answer[i] = j - i;
                break;
            }
            if (j == prices.size() - 1) answer[i] = j - i;
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    v = solution({ 1, 2, 3, 2, 3 });
    for (auto& x : v)
    {
        cout << x << " ";
    }

    return 0;
}