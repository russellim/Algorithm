// 21.03.31. 수
// 1967: 트리의 지름 https://www.acmicpc.net/problem/1967
// dfs.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_1967
{
	struct Node { int child, cost; };
	vector<vector<Node> > nodes;
	vector<vector<int> > costs;	// 노드에 저장된 자식노드 한줄기 씩 더해온 cost. (자식 개수만큼 가짐).

	int dfs(int pos, int nowCost)
	{
		int temp = 0;
		for (int i = 0; i < nodes[pos].size(); ++i)
		{
			int dfsCost = dfs(nodes[pos][i].child, nodes[pos][i].cost);
			temp = max(temp, dfsCost);
			costs[pos].push_back(dfsCost);
		}
		return temp + nowCost;
	}

	void Input(int& n)
	{
		cin >> n;
		nodes.assign(n + 1, vector<Node>());
		costs.assign(n + 1, vector<int>());
		int parent, child, cost;
		for (int i = 1; i < n; ++i)
		{
			cin >> parent >> child >> cost;
			nodes[parent].push_back({ child, cost });
		}
	}

	void Solution()
	{
		int n, answer = 0;
		Input(n);

		// 루트노드 1 부터 자식들 각각 dfs.
		for (int j = 0; j < nodes[1].size(); ++j)
		{
			costs[1].push_back(dfs(nodes[1][j].child, nodes[1][j].cost));
		}

		// 저장된 cost 중 큰 값 0~2개 더한 값.
		for (int i = 1; i <= n; ++i)
		{
			sort(costs[i].rbegin(), costs[i].rend());
			int temp = 0;
			for (int j = 0; j < costs[i].size(); ++j)
			{
				if (j > 1) break;
				temp += costs[i][j];
			}
			answer = max(answer, temp);
		}

		// output.
		cout << answer;
	}
}

// 얘! 이진트리라는 보장이 없단다!
// 이진트리인줄알고 left, right 값 계산해준 코드.
namespace BOJ_1967_lagacy
{
	struct Node { int parent, cost; };
	enum class NodeDirection { left, right };

	vector<Node> nodes;
	vector<vector<int> > nodeCosts;
	vector<NodeDirection> nodeDir;


	void dfs(int pos, int nowCost)
	{
		int direction = (int)nodeDir[pos];
		int parent = nodes[pos].parent;
		if (nodeCosts[parent][direction] >= nowCost) return;
		nodeCosts[parent][direction] = nowCost;
		if (nodeCosts[parent][!direction] >= nowCost) return;

		if (parent == 1) return;

		dfs(parent, nodes[parent].cost + nowCost);
	}

	void Solution()
	{
		int n, answer = 0;
		cin >> n;
		if (n == 1)
		{
			cout << "0";
			return;
		}

		nodes.assign(n + 1, { 0, 0 });
		nodeDir.assign(n + 1, NodeDirection::left);
		nodeCosts.assign(n + 1, { 0, 0 });
		int parent, child, cost, prevParent = 0;
		for (int i = 1; i < n; ++i)
		{
			cin >> parent >> child >> cost;
			nodes[child] = { parent, cost };
			if (prevParent == parent) nodeDir[child] = NodeDirection::right;
			prevParent = parent;
		}

		for (int i = n; i > nodes[n].parent; --i)
		{
			dfs(i, nodes[i].cost);
		}

		for (int i = 1; i <= nodes[n].parent; ++i)
		{
			answer = max(answer, nodeCosts[i][0] + nodeCosts[i][1]);
		}
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1967::Solution();

	return 0;
}