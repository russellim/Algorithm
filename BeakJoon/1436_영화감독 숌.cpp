// 20.12.27. 일
// 1436: 영화감독 숌 https://www.acmicpc.net/problem/1436
// 브루트포스, string.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int number = 665, n, answer = 0;

    cin >> n;

    while (1)
    {
        number++;
        if (to_string(number).find("666") != string::npos)
            answer++;
        if (answer == n) break;
    }
    cout << number;

    return 0;
}