// 20.10.14. 수
// 스택/큐_기능개발 https://programmers.co.kr/learn/courses/30/lessons/42586
// IDE 사용 금지.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int ans;            // 구한 일 수.
    int preday = -1;    // 이전 일 수 중 max값.
    int pivot = -1;     // answer 인덱스 pivot.
    for (int i = 0; i < progresses.size(); ++i)
    {
        ans = ceil((100 - progresses[i]) / (double)speeds[i]);

        // 일 수 구하고 이전에 일수max값과 비교
        if (preday < ans)
        {
            // max값이 작으면 바로 끝남.
            pivot++;
            answer.push_back(1);
            preday = ans;
        }
        else
        {
            // max값이 크면 그거 끝나는거 기다렸다 같이 끝남.
            answer[pivot]++;
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    v = solution({ 93,30,55 }, { 1,30,5 });
    for (auto& x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v = solution({ 95,90,99,99,80,99 }, { 1,1,1,1,1,1 });
    for (auto& x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}