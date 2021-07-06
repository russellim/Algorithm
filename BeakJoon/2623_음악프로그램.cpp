// 21.07.06. 화
// 2623: 음악프로그램 https://www.acmicpc.net/problem/2623
// Topological Sort.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace BOJ_2623
{
	// 위상 정렬.
	vector<int> Topological_Sort(int n, vector<int>& preCount, const vector<vector<int> >& conn)
	{
		vector<int> answer;

		queue<int> q;
		for (int i = 1; i <= n; ++i)
		{
			if (preCount[i] == 0) q.push(i);
		}

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			answer.push_back(now);

			for (int next : conn[now])
			{
				preCount[next]--;
				if (preCount[next] > 0) continue;

				q.push(next);
			}
		}
		
		return answer;
	}

	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<int> preCount(n + 1, 0);
		vector<vector<int> > conn(n + 1, vector<int>());

		for (int i = 0; i < m; ++i)
		{
			int cnt, node, preNode;
			cin >> cnt;
			cin >> preNode;
			for (int i = 1; i < cnt; ++i)
			{
				cin >> node;
				conn[preNode].emplace_back(node);
				preCount[node]++;
				preNode = node;
			}
		}

		auto answer = Topological_Sort(n, preCount, conn);

		// 모두 방문하지 않았으면 "0" 출력.
		if (answer.size() != n) cout << "0";
		else
		{
			for (int& x : answer) cout << x << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2623::Solution();
	return 0;
}
