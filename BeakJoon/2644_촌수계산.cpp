// 21.04.04. 일
// 2644: 촌수계산 https://www.acmicpc.net/problem/2644
// 트리.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_2644
{
	vector<int> parents;
	vector<int> bridge;

	int FindBridgeCount(int num, int otherNum)
	{
		int count = 1;
		while (1)
		{
			if (parents[num] == 0) return 0;
			if (bridge[parents[num]] != 0 || parents[num] == otherNum) return bridge[parents[num]] + count;
			bridge[parents[num]] += count;
			num = parents[num];
			++count;
		}
	}

	void Solution()
	{
		int n, a, b, m;
		cin >> n >> a >> b >> m;
		parents.assign(n + 1, 0);
		bridge.assign(n + 1, 0);
		while (m--)
		{
			int parent, child;
			cin >> parent >> child;
			parents[child] = parent;
		}

		int answer;
		answer = FindBridgeCount(a, b);
		if (answer != 0)
		{
			cout << answer;
			return;
		}
		answer = FindBridgeCount(b, a);
		if (answer == 0) cout << "-1";
		else cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2644::Solution();

	return 0;
}