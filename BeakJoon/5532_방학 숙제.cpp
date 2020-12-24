// 20.12.24. 목
// 5532: 방학 숙제 https://www.acmicpc.net/problem/5532
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int L, B, A, C, D, b, a;
    cin >> L >> B >> A >> C >> D;

    b = B / C;
    if (B % C != 0) b++;
    a = A / D;
    if (A % D != 0) a++;

    cout << L - max(a, b);

    return 0;
}