// 21.02.19. 금
// 11286: 절댓값 힙 https://www.acmicpc.net/problem/11286
// 최소, 최대 heap.
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

namespace BOJ_9375
{
	void Solution()
	{
		priority_queue<int, vector<int>, greater<int> > plusQ; // 0보다 큰 수는 최소힙으로.
		priority_queue<int, vector<int>, less<int> > minusQ;   // 0보다 작은 수는 최대힙으로.
		int n;
		cin >> n;
		while (n--)
		{
			int input;
			cin >> input;
			if (input == 0)
			{
				if (plusQ.empty() && minusQ.empty())
				{
					cout << "0\n";
					continue;
				}
				int a = plusQ.empty() ? 1e9 : plusQ.top();
				int b = minusQ.empty() ? 1e9 : minusQ.top();
				if (a >= abs(b))
				{
					cout << b << "\n";
					minusQ.pop();
				}
				else
				{
					cout << a << "\n";
					plusQ.pop();
				}
			}
			else
			{
				if (input > 0) plusQ.push(input);
				else minusQ.push(input);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_9375::Solution();

	return 0;
}