// 21.07.01. 목
// 1766: 문제집 https://www.acmicpc.net/problem/1766
// 위상정렬, priority_queue vs set.
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

// priority_queue 사용.
// 방문처리 vector가 추가 되었는데도 메모리 덜 사용.
namespace BOJ_1766_pqueue
{
	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<int> pre_count(n + 1, 0);
		vector<vector<int> > pre(n + 1, vector<int>());
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			pre[a].push_back(b);
			pre_count[b]++;
		}

		priority_queue<int, vector<int>, greater<int> > q;
		vector<int> visit(n + 1, 0);
		for (int i = 1; i <= n; ++i) q.push(i);

		while (!q.empty())
		{
			int now = q.top();
			q.pop();

			if (visit[now] == 1) continue;
			if (pre_count[now] > 0) continue;

			cout << now << " ";
			visit[now] = 1;

			for (int& next : pre[now])
			{
				pre_count[next]--;
				if (pre_count[next] == 0) q.push(next);
			}
		}
	}
}

// set (중복된 값 안들어가게 하려고) 사용.
// 메모리랑 시간이 좀 더 사용됨.
namespace BOJ_1766_set
{
	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<int> pre_count(n + 1, 0);
		vector<vector<int> > pre(n + 1, vector<int>());
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			pre[a].push_back(b);
			pre_count[b]++;
		}

		set<int> s;
		for (int i = 1; i <= n; ++i) s.insert(i);

		while (!s.empty())
		{
			int now = *s.begin();
			s.erase(s.begin());

			if (pre_count[now] > 0) continue;

			cout << now << " ";

			for (int& next : pre[now])
			{
				pre_count[next]--;
				if (pre_count[next] == 0) s.insert(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1766_pqueue::Solution();
	BOJ_1766_set::Solution();

	return 0;
}