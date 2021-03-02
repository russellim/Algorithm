// 21.03.01. 월
// 11725: 트리의 부모 찾기 https://www.acmicpc.net/problem/11725
// 트리, BFS, DFS.

// 83% 시간초과.

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

namespace BOJ_11725
{
	vector<int> Tree;
	deque<pair<int, int> > ReadyNodes;

	void InsertTree(int a, int b)
	{
		if (Tree[a]) Tree[b] = a;
		else Tree[a] = b;
	}

	void CheckReadyNodes()
	{
		while (!ReadyNodes.empty())
		{
			deque<pair<int, int> > tempdq;
			tempdq.swap(ReadyNodes);
			while (!tempdq.empty())
			{
				int a = tempdq.front().first;
				int b = tempdq.front().second;
				tempdq.pop_front();
				if (Tree[a] == 0 && Tree[b] == 0)
				{
					// 다음에는 거꾸로 검사.
					ReadyNodes.push_front({ a, b });
					continue;
				}
				InsertTree(a, b);
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
			if (Tree[a] == 0 && Tree[b] == 0)
			{
				ReadyNodes.push_back({ a, b });
				continue;
			}
			InsertTree(a, b);
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