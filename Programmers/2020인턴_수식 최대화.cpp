// 20.11.08. 일
// 2020인턴_수식 최대화 https://programmers.co.kr/learn/courses/30/lessons/67257
// 구현.
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long cal(long long a, long long b, char c)
{
    switch (c)
    {
    case '+': return a + b;
    case '*': return a * b;
    case '-': return a - b;
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> priority = { "*+-", "*-+", "+*-", "+-*", "-+*", "-*+" };
    vector<long long> numbers;
    vector<char> exps;
    
    // 식 초기화 저장소.
    vector<long long> storenumbers;
    vector<char> storeexps;

    string numTemp = "";
    for (int i = 0; i < expression.size(); ++i)
    {
        if (isdigit(expression[i]))
        {
            numTemp += expression[i];
        }
        else
        {
            numbers.push_back(atoll(numTemp.c_str()));
            exps.push_back(expression[i]);
            numTemp = "";
        }
    }
    numbers.push_back(atoll(numTemp.c_str()));

    storenumbers = numbers;
    storeexps = exps;

    for (int i = 0; i < priority.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < exps.size(); ++k)
            {
                if (exps[k] == priority[i][j])
                {
                    numbers[k] = cal(numbers[k], numbers[k + 1], exps[k]);
                    numbers.erase(numbers.begin() + k + 1);
                    exps.erase(exps.begin() + k);
                    --k;
                }
            }
        }

        if (answer < abs(numbers[0])) answer = abs(numbers[0]);

        // 초기화.
        numbers = storenumbers;
        exps = storeexps;
    }


    return answer;
}