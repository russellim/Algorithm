// 21.06.15. 화
// 20040: 사이클 게임 https://www.acmicpc.net/problem/20040
// MST(크루스칼).
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_20040
{
	vector<int> parent;

	// 크루스칼 사용.
	// 가장 위의 부모 찾기.
	int FindParent(int child)
	{
		if (child == parent[child]) return child;
		return parent[child] = FindParent(parent[child]);
	}

	// 제일 위 부모가 같으면 사이클 만들어진것.
	bool IsCycle(int from, int to)
	{
		from = FindParent(from);
		to = FindParent(to);

		if (from == to) return true;

		parent[from] = to;
		return false;
	}

	void Solution()
	{
		int n, m, answer = 0;
		cin >> n >> m;
		parent.assign(n, 0);
		for (int i = 0; i < n; ++i) parent[i] = i;

		int dot1, dot2;
		bool isFindCycle = false;
		for (int i = 1; i <= m; ++i)
		{
			cin >> dot1 >> dot2;
			if (isFindCycle) continue;

			//if (i <= 2) continue; // 1, 2번 선분을 그냥 합치는것도 필요함.
			if (IsCycle(dot1, dot2))
			{
				answer = i;
				isFindCycle = true;
			}
		}

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_20040::Solution();

	return 0;
}