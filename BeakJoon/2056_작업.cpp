// 21.06.06. 일
// 2056: 작업 https://www.acmicpc.net/problem/2056
// 위상정렬.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

namespace BOJ_2056
{
	vector<int> time;
	vector<vector<int> > conn;
	vector<int> prev;

	void CheckRoute(int n)
	{
		int res = 0;
		vector<int> cost(n+1, 0);
		queue<int> q;
		for (int i = 1; i <= n; ++i)
		{
			if (prev[i] == 0)
			{
				q.push(i);
				cost[i] = time[i];
				res = max(res, cost[i]);
			}
		}

		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			for (int& next : conn[now])
			{
				cost[next] = max(cost[next], cost[now] + time[next]);
				res = max(res, cost[next]);
				prev[next]--;
				if (prev[next] != 0) continue;
				q.push(next);
			}
		}

		cout << res;
	}

	void Solution()
	{
		int n;
		cin >> n;
		time.assign(n + 1, 0);
		conn.assign(n + 1, vector<int>());
		prev.assign(n + 1, 0);

		for (int i = 1; i <= n; ++i)
		{
			cin >> time[i];
			cin >> prev[i];
			for (int j = 0; j < prev[i]; ++j)
			{
				int p;
				cin >> p;
				conn[p].push_back(i);
			}
		}

		CheckRoute(n);

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2056::Solution();

	return 0;
}