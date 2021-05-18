// 21.05.18. 화
// 1647: 도시 분할 계획 https://www.acmicpc.net/problem/1647
// MST(프림).
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

namespace BOJ_1647
{
	struct Conn
	{
		int from;
		int cost;
	};
	struct cmp
	{
		bool operator()(Conn& a, Conn& b)
		{
			return a.cost > b.cost;
		}
	};

	int n, m;

	// 프림 알고리즘.
	int MST(int start, vector<vector<Conn> >& conn)
	{
		int sum = 0;
		vector<int> road;
		vector<bool> visit(n + 1, false);
		priority_queue<Conn, vector<Conn>, cmp> pq;
		for (auto& x : conn[start]) pq.push(x);
		visit[start] = true;

		while (!pq.empty())
		{
			auto next = pq.top();
			pq.pop();

			if (visit[next.from]) continue;
			visit[next.from] = true;
			sum += next.cost;
			road.push_back(next.cost);
			for (auto& x : conn[next.from]) pq.push(x);
		}

		sort(road.rbegin(), road.rend());
		return sum - road[0];
	}

	void Solution()
	{
		cin >> n >> m;
		vector<vector<Conn> > conn(n + 1, vector<Conn>());
		for (int i = 0; i < m; ++i)
		{
			int to, from, cost;
			cin >> to >> from >> cost;
			conn[to].push_back({ from, cost });
			conn[from].push_back({ to, cost });
		}

		// output.
		cout << MST(1, conn);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1647::Solution();

	return 0;
}