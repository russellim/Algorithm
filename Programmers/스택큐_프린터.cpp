// 20.10.11. 일
// 스택/큐_프린터 https://programmers.co.kr/learn/courses/30/lessons/42587
// Queue, IDE 사용 금지.
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetMax(const vector<int>& v)
{
    for (int i = 9; i >= 0; --i)
    {
        if (v[i] > 0) return i;
    }
}

int solution(vector<int> priorities, int location) {
    int size = priorities.size();
    vector<int> number(10, 0);
    int maxValue, answer = 1;

    for (int i = 0; i < size; ++i)
    {
        number[priorities[i]]++;
    }
    maxValue = GetMax(number);
    while (1)
    {
        // 뒤로 보내기.
        if (priorities[0] < maxValue)
        {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            if (location == 0) location = priorities.size() - 1;
            else location--;
        }
        else
        {
            if (location == 0) return answer;
            priorities.erase(priorities.begin());
            answer++;
            location--;
            number[maxValue]--;
            if (number[maxValue] == 0) maxValue = GetMax(number);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);


    cout << solution({ 2,1,3,2 }, 2) << endl;
    cout << solution({ 1,1,9,1,1,1 }, 0) << endl;


    return 0;
}