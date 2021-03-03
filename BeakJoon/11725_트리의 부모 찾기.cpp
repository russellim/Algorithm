// 21.03.01. 월
// 11725: 트리의 부모 찾기 https://www.acmicpc.net/problem/11725
// DFS.
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// dfs. 48ms solved.
namespace BOJ_11725
{
	vector<int> Tree;
	vector<vector<int> > connNode;
	vector<bool> visit;

	void dfs(int parent)
	{
		for (int i = 0; i < connNode[parent].size(); ++i)
		{
			int child = connNode[parent][i];
			if (visit[child]) continue;
			visit[child] = true;
			Tree[child] = parent;
			dfs(child);
		}
	}

	void Solution()
	{
		int n, a, b;
		cin >> n;
		Tree.assign(n + 1, 0);
		connNode.assign(n + 1, vector<int>());
		visit.assign(n + 1, false);
		visit[1] = true;

		for (int i = 0; i < n - 1; ++i)
		{
			cin >> a >> b;
			connNode[a].push_back(b);
			connNode[b].push_back(a);
		}
		dfs(1);

		for (int i = 2; i <= n; ++i)
		{
			cout << Tree[i] << "\n";
		}
	}
}

// deque 사용 83% 시간초과.
namespace BOJ_11725_legacy
{
	vector<int> Tree;
	deque<pair<int, int> > ReadyNodes;

	void CheckReadyNodes()
	{
		while (!ReadyNodes.empty())
		{
			deque<pair<int, int> > tempdq;
			tempdq.swap(ReadyNodes);
			while (!tempdq.empty())
			{
				int a = tempdq.back().first;
				int b = tempdq.back().second;
				tempdq.pop_back();
				if (Tree[a]) Tree[b] = a;
				else if (Tree[b]) Tree[a] = b;
				else ReadyNodes.push_back({ a, b });
			}
		}
	}

	void Solution()
	{
		int n, a, b;
		cin >> n;
		Tree.assign(n + 1, 0);
		Tree[1] = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> a >> b;
			if (Tree[a]) Tree[b] = a;
			else if (Tree[b]) Tree[a] = b;
			else ReadyNodes.push_back({ a, b });
		}

		CheckReadyNodes();

		for (int i = 2; i <= n; ++i)
		{
			cout << Tree[i] << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_11725::Solution();

	return 0;
}