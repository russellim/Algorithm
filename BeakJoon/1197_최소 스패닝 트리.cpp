// 21.02.11. 목
// 1197: 최소 스패닝 트리 https://www.acmicpc.net/problem/1197
// mst, 크루스칼, 프림
// 사이클이 되지않는 총 비용이 가장 적은 그래프를 만들어라! 답이 여러개가 될 수도 있음.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 프림 알고리즘. (210212 금, 추가).
// 기준 정점을 먼저 잡아서 최소 힙에 간선의 가중치를 추가해, 가장 작은 가중치부터 연결하며 이동하는 방식.
namespace MST_Prim
{
	typedef pair<int, int> pii;
	int answer = 0;
	vector<pii>* path;
	vector<bool> isVisit;
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	void FindPathPushQueue(int vertexNum)
	{
		for (int i = 0; i < path[vertexNum].size(); ++i)
		{
			int nextVertex = path[vertexNum][i].first;
			int nextCost = path[vertexNum][i].second;

			pq.push({ nextCost, nextVertex });
		}
	}

	void Solution(int startVertex)
	{
		isVisit[startVertex] = true;

		// startVertex 부터 주변 간선 체크.
		FindPathPushQueue(startVertex);

		// 나머지 고고.
		while (!pq.empty())
		{
			int nowVertex = pq.top().second;
			int nowCost = pq.top().first;
			pq.pop();

			if (isVisit[nowVertex]) continue;
			isVisit[nowVertex] = true;
			answer += nowCost;

			FindPathPushQueue(nowVertex);
		}
	}

	void Input()
	{
		int v, e;
		cin >> v >> e;

		path = new vector<pii>[v + 1];
		isVisit.assign(v + 1, false);

		for (int i = 0; i < e; ++i)
		{
			int from, to, value;
			cin >> from >> to >> value;

			path[from].push_back({ to, value });
			path[to].push_back({ from, value });
		}
	}

	void Output()
	{
		cout << answer;
		delete[] path;
	}
}

// 크루스칼 알고리즘.
// 모든 간선에 대해 가장 작은 가중치부터 연결하는 방식.
namespace MST_Kruskal
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
	MST_Prim::Input();
	MST_Prim::Solution(1);
	MST_Prim::Output();

	MST_Kruskal::Input();
	MST_Kruskal::Solution();
	MST_Kruskal::Output();
}