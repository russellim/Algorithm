// 21.06.03. 목
// 1516: 게임 개발 https://www.acmicpc.net/problem/1516
// 위상정렬.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

namespace BOJ_1516
{
	vector<int> prev;
	vector<int> time;
	vector<vector<int> > conn;

	void Topological_Sort(int n)
	{
		vector<int> res(n+1);
		queue<int> q;
		for (int i = 1; i <= n; ++i)
		{
			if (prev[i] == 0)
			{
				q.push(i);
				res[i] = time[i];
			}
		}

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for (auto& next : conn[now])
			{
				--prev[next];
				res[next] = max(res[next], time[next] + res[now]);
				if (prev[next] != 0) continue;
				q.push(next);
			}
		}

		for (int i = 1; i <= n; ++i)
			cout << res[i] << " ";
	}

	void Solution()
	{
		int n;
		cin >> n;
		prev.assign(n + 1, 0);
		time.assign(n + 1, 0);
		conn.assign(n + 1, vector<int>());
		for (int i = 1; i <= n; ++i)
		{
			cin >> time[i];
			int data;
			while (1)
			{
				cin >> data;
				if (data == -1) break;
				conn[data].push_back(i);
				++prev[i];
			}
		}

		Topological_Sort(n);
	}
}

int main()
{
	BOJ_1516::Solution();
	return 0;
}