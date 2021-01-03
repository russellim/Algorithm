// 21.01.03. 일
// 1676: 팩토리얼 0의 개수 https://www.acmicpc.net/problem/1676
// 큰 수 연산.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, answer = 0;
    cin >> n;

    // 최대 500! 을 구해야함.
    // unsinged long long에도 안담깁니다. (50!만 돼도 무 쳤 다).
    // 문자열과 캐리값을 사용해 계산합시다.
    string res = "1";

    for (int i = 2; i <= n; ++i)
    {
        int temp = 0; // 캐리값.
        for (int j = res.size() - 1; j >= 0; --j) // 앞자리 수 부터 계산.
        {
            temp = (res[j] - '0') * i + temp;   // 곱한값 + 캐리값.
            res[j] = (temp % 10) + 48;          // 구한 값의 1의 자리만 남겨두고.
            temp /= 10;                         // 나머지는 다음 자릿수 캐리값으로.
        }

        // 다 계산하고 캐리값이 남을 경우, 답 앞에 붙여줍시다.
        if (temp != 0)
        {
            res = to_string(temp) + res;
        }
    }

    for (int i = res.size() - 1; i >= 0; --i)
    {
        if (res[i] != '0') break;
        answer++;
    }
    cout << answer;

    return 0;
}