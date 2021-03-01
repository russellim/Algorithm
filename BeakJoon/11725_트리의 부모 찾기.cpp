// 21.03.01. 월
// 11725: 트리의 부모 찾기 https://www.acmicpc.net/problem/11725
// 트리, BFS, DFS.

// 메모리 초과.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

namespace BOJ_11725
{
	vector<int> Tree;
	queue<pair<int, int> > ReadyNodes;

	pair<int, int> FindChildAndParent(int a, int b)
	{
		if (Tree[a] == 0 && Tree[b] == 0)
		{
			ReadyNodes.push({ a, b });
			return { -1, -1 };
		}
		if (Tree[a] != 0) return { b, a };
		return { a, b };
	}

	void InsertTree(int child, int parent)
	{
		Tree[child] = parent;
	}

	void CheckReadyNodes()
	{
		int qSize = ReadyNodes.size();
		while (qSize--)
		{
			int a = ReadyNodes.front().first;
			int b = ReadyNodes.front().second;
			ReadyNodes.pop();
			auto node = FindChildAndParent(a, b);
			if (node.first == -1)
			{
				ReadyNodes.push({ a, b });
				continue;
			}
			InsertTree(node.first, node.second);
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
			auto node = FindChildAndParent(a, b);
			if (node.first != -1)
			{
				InsertTree(node.first, node.second);
				CheckReadyNodes();
			}
		}

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