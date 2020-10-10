// 20.10.10. 토
// 완전탐색  https://programmers.co.kr/learn/courses/30/lessons/42840
// 완전탐색, IDE 사용 금지.
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int AnswersCount = answers.size();
    vector<int> Count(3, 0);
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2 = { 2,1,2,3,2,4,2,5 };
    vector<int> v3 = { 3,3,1,1,2,2,4,4,5,5 };

    for (int i = 0; i < AnswersCount; ++i)
    {
        if (v1[i % v1.size()] == answers[i]) Count[0]++;
        if (v2[i % v2.size()] == answers[i]) Count[1]++;
        if (v3[i % v3.size()] == answers[i]) Count[2]++;
    }

    int maxValue = max({ Count[0], Count[1], Count[2] });
    for (int i = 0; i < 3; ++i)
    {
        if (Count[i] >= maxValue)
        {
            maxValue = Count[i];
            answer.push_back(i + 1);
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    vector<int> v;
    v = solution({ 1,2,3,4,5 });
    for (auto& x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v = solution({ 1,3,2,4,2 });
    for (auto& x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}