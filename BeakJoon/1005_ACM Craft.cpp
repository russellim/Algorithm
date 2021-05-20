// 21.05.20. 목
// 1005: ACM Craft https://www.acmicpc.net/problem/1005
// 위상정렬.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

namespace BOJ_1005
{
	int n, k;

	int GetTime(vector<int>& time, vector<vector<int> >& tree, vector<int>& conn, int goal)
	{
		vector<int> value(n + 1, 0);
		queue<int> q;
		for (int i = 1; i <= n; ++i)
		{
			if (conn[i] == 0)
			{
				q.push(i);
				value[i] = time[i];
			}

		}

		while (!q.empty())
		{
			int nowPos = q.front();
			q.pop();

			for (int nextPos : tree[nowPos])
			{
				conn[nextPos]--;
				value[nextPos] = max(value[nextPos], value[nowPos] + time[nextPos]);

				if (conn[nextPos] == 0) q.push(nextPos);
			}
		}
		return value[goal];
	}

	void Solution()
	{
		int t;
		cin >> t;
		while (t--)
		{
			cin >> n >> k;
			vector<int> time(n + 1);
			for (int i = 1; i <= n; ++i) cin >> time[i];
			vector<vector<int> >tree(n + 1, vector<int>());
			vector<int> conn(n + 1, 0);
			for (int i = 0; i < k; ++i)
			{
				int a, b;
				cin >> a >> b;
				tree[a].push_back(b);
				conn[b]++;
			}
			int goal;
			cin >> goal;

			cout << GetTime(time, tree, conn, goal) << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1005::Solution();

	return 0;
}