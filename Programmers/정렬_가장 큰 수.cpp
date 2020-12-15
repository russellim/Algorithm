// 20.12.15. 화
// 정렬_가장 큰 수 https://programmers.co.kr/learn/courses/30/lessons/42746
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringNum;
    for (int i = 0; i < numbers.size(); ++i)
    {
        stringNum.push_back(to_string(numbers[i]));
    }
    sort(stringNum.begin(), stringNum.end(), cmp);
    if (stringNum[0][0] == '0') return "0";
    for (string x : stringNum) answer += x;

    return answer;
}