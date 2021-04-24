// 21.04.17. 토
// 9466: 텀 프로젝트 https://www.acmicpc.net/problem/9466
// 방향그래프.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_9466
{
	vector<int> pick;
	vector<bool> checkMan;

	int CheckCycle(int n, int man)
	{
		vector<bool>visit(n + 1, false);	// 사이클인지는 방문으로 체크.
		vector<int> cycle;
		visit[man] = true;
		checkMan[man] = true;
		cycle.push_back(man);

		while (1)
		{
			man = pick[man];
			if (visit[man])
			{
				checkMan[man] = true;
				// 사이클 도착점을 이용해 사이클 이루는 것만 계산해줌.
				// ex) 1->3->5->7->3 여기에 1은 제외된다.
				for (int i = 0; i < cycle.size(); ++i)
				{
					if (cycle[i] == man)
					{
						return cycle.size() - i;
					}
				}
			}
			if (checkMan[man]) return 0;
			visit[man] = checkMan[man] = true;
			cycle.push_back(man);
		}
	}

	void Solution()
	{
		int t;
		cin >> t;
		while (t--)
		{
			int n, answer;
			cin >> n;
			answer = n;
			pick.assign(n + 1, 0);
			checkMan.assign(n + 1, false);
			for (int i = 1; i <= n; ++i)
			{
				cin >> pick[i];
				if (i == pick[i])	// 자기 자신 가리키는건 미리 제외.
				{
					checkMan[i] = true;
					answer--;
				}
			}

			for (int i = 1; i <= n; ++i)
			{
				if (checkMan[i]) continue;
				answer -= CheckCycle(n, i);	// 사이클에 속하는 것들 제외시켜줌.
			}

			cout << answer << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_9466::Solution();

	return 0;
}