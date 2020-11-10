// 20.11.10. 화
// 1966: 프린터 큐 https://www.acmicpc.net/problem/1966
// Queue.
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		queue<pair<int, int> > q;	// 문서번호, 우선순위.
		vector<int> priority(10, 0); // 우선순위 별 남은 개수.
		int n, m;
		int big = 1; // 현재 가장 큰 우선순위.
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			priority[temp]++;
			if (big < temp) big = temp;
			q.push({ i, temp });
		}
		int answer = 1;

		while (1)
		{
			if (q.front().second == big)
			{
				if (q.front().first == m)
				{
					cout << answer << "\n";
					break;
				}
				else
				{
					// 우선순위 남은 개수 0이면 다음 제일 큰 우선순위 찾기.
					if (--priority[q.front().second] <= 0)
					{
						for (int i = q.front().second - 1; i >= 1; --i)
						{
							if (priority[i] > 0)
							{
								big = i;
								break;
							}
						}
					}
					answer++;
				}
				q.pop();
			}
			else
			{
				// 맨 앞이 제일 큰 우선순위(big) 아니면 뒤로 보내기.
				q.push({ q.front().first, q.front().second });
				q.pop();
			}
		}
	}

	return 0;
}