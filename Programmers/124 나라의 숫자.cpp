// 20.10.12. 월
// 124 나라의 숫자  https://programmers.co.kr/learn/courses/30/lessons/12899
// 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int temp = 0, dob = 1;
    while (n > 3)
    {
        if (n % 3 == 0)
        {
            temp += dob * 4;
            n = (n / 3) - 1;
        }
        else
        {
            temp += dob * (n % 3);
            n /= 3;
        }
        dob *= 10;
    }

    temp += dob * n;

    answer = to_string(temp);
    for (int i = 0; i < answer.size(); ++i)
    {
        if (answer[i] == '3') answer[i] = '4';
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cout << solution(1) << endl;
    cout << solution(2) << endl;
    cout << solution(3) << endl;
    cout << solution(4) << endl;

    return 0;
}