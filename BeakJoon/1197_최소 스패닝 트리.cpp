// 21.02.11. 목
// 1197: 최소 스패닝 트리 https://www.acmicpc.net/problem/1197
// mst, 크루스칼
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace MST
{
	struct kruscal
	{
		int from;
		int to;
		int value;
	};
	int v, e, answer = 0;
	vector<kruscal> edges;
	int parent[10001];
	bool check;

	bool cmp(kruscal& a, kruscal& b)
	{
		return a.value < b.value;
	}

	int findParent(int child)
	{
		if (child == parent[child]) return child;
		return parent[child] = findParent(parent[child]);
	}

	void merge(int from, int to)
	{
		check = false;
		from = findParent(from);
		to = findParent(to);

		if (from == to) return;

		parent[from] = to;
		check = true;
	}

	void Solution()
	{
		sort(edges.begin(), edges.end(), cmp);
		for (int i = 0; i < e; ++i)
		{
			merge(edges[i].from, edges[i].to);

			if (check) answer += edges[i].value;
		}
	}

	void Input()
	{
		cin >> v >> e;
		for (int i = 1; i <= v; ++i)
		{
			parent[i] = i;
		}
		for (int i = 0; i < e; ++i)
		{
			kruscal ks;
			cin >> ks.from >> ks.to >> ks.value;
			edges.push_back(ks);
		}
	}
	void Output()
	{
		cout << answer;
	}
}

int main()
{
	MST::Input();
	MST::Solution();
	MST::Output();
}