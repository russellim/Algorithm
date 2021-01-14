// 21.01.14. 목
// 1541: 잃어버린 괄호 https://www.acmicpc.net/problem/1541
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str, temp = "";
    cin >> str;

    int answer = 0;
    bool IsMinus = false;

    for (int i = 0; i <= str.size(); ++i)
    {
        if (isdigit(str[i]))
        {
            temp += str[i];
            continue;
        }

        if (IsMinus) answer -= stoi(temp);
        else answer += stoi(temp);

        // 연산자는 연속하지않고 +, -만 -> + -가 번갈아 나온다.
        // 한번 - 나오면 그 뒤는 다 -().
        if (str[i] == '-')
        {
            IsMinus = true;
        }
        temp = "";
    }

    cout << answer;

    return 0;
}