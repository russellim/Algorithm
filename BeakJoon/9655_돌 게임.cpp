// 20.09.17 수
// 9655: 숨바꼭질 https://www.acmicpc.net/problem/9655
// DP
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 3)
    {
        cout << "SK";
    }
    else
        {
        if(n%2 == 0)
            cout << "CY";
        else
            cout << "SK";
        }
}