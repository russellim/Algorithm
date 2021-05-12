// 21.05.12. 수
// 11723: 집합 https://www.acmicpc.net/problem/11723
// 비트마스킹.

// 예전에 vector로 풀었었다. 시간은 비슷하지만 이게 더 간단하고 알아보기 쉬운 방법인듯.
#include <iostream>
using namespace std;

namespace BOJ_11723
{

	int Check(int n, int num)
	{
		return (n >> num) % 2;
	}
	void Solution()
	{
		// 1: 있음, 0: 없음.
		int n = 1 << 21; // 1~20.
		int m, num;
		cin >> m;
		string cmd;
		while (m--)
		{
			cin >> cmd;
			if (cmd == "all") // 모두 1.
			{
				n = (1 << 22) - 1;
			}
			else if (cmd == "empty") // 모두 0 (초기화).
			{
				n = 1 << 21;
			}
			else
			{
				cin >> num;
				if (cmd == "add") // num 추가.
				{
					n = n | 1 << num;
				}
				else if (cmd == "remove") // num 삭제.
				{
					n = n & ~(1 << num);
				}
				else if (cmd == "check") // num 확인.
				{
					cout << Check(n, num) << "\n";
				}
				else if (cmd == "toggle") // num 토글.
				{
					if (Check(n, num) == 0) n += 1 << num;
					else n -= 1 << num;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_11723::Solution();

	return 0;
}