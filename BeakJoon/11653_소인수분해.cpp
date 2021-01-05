// 21.01.05. 화
// 11653: 소인수분해 https://www.acmicpc.net/problem/11653
// 소수.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 2; n > 1; ++i)
    {
        if (n % i == 0)
        {
            cout << i << "\n";
            n /= i;
            i = 1;
        }
    }

    return 0;
}

// 이것 소수 구해야 한다는 편견과 아집으로 인해 오래걸린 문제.
// 소수가 2, 3 ... 으로 시작하는것을 안다면 간단하게 나올수있다.