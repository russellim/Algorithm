// 20.10.24. 토
// kakao 2018_n진수 게임  https://programmers.co.kr/learn/courses/30/lessons/17687
// string. IDE 사용 금지!
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// n진수 구해서 string으로 반환하는 함수.
string decTo(int num, int n)
{
    if (num == 0) return "0";
    string ans = "";
    int temp;
    while (num != 0)
    {
        temp = num % n;
        if (temp >= 10)
        {
            char c = 65 + temp - 10;
            ans = c + ans;
        }
        else ans = to_string(temp) + ans;
        num /= n;
    }
    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = -1;
    string snum;
    while (1)
    {
        num++;
        snum += decTo(num, n);
        if (snum.size() > t* m) break;
    }

    // 내 차례부터 시작해서 사람 수 만큼 건너뜀.
    for (int i = p - 1; answer.size() < t; i += m)
    {
        answer += snum[i];
    }

    return answer;
}