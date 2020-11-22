// 20.11.22. 일
// 2490: 윷놀이 https://www.acmicpc.net/problem/2490

#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; ++i)
    {
        int one = 0;
        for (int j = 0; j < 4; ++j)
        {
            int temp;
            cin >> temp;
            if (temp == 1) one++;
        }
        char ch;
        switch (one)
        {
        case 0: ch = 'D'; break;
        case 1: ch = 'C'; break;
        case 2: ch = 'B'; break;
        case 3: ch = 'A'; break;
        case 4: ch = 'E'; break;
        }
        cout << ch << "\n";

    }
    return 0;
}