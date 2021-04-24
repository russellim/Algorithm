// 21.04.01. 목
// 16928: 뱀과 사다리 게임 https://www.acmicpc.net/problem/16928
// bfs.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace BOJ_16928
{
	constexpr int GOAL = 100;
	constexpr int DICE = 6;
	constexpr int MAX = 1e9;

	int bfs(vector<int>& pann)
	{
		queue<pair<int, int> > q;
		vector<int> counts(101, MAX);	// 이걸 안하고 그냥 visit만 체크하면 메모리랑 시간이 많이 듭니다.
		q.push({ 1, 0 });

		while (!q.empty())
		{
			int nowPos = q.front().first;
			int nowCount = q.front().second;
			q.pop();

			for (int dice = 1; dice <= 6; ++dice)
			{
				int nextPos = pann[nowPos + dice];
				if (nextPos == 100) return nowCount + 1;

				if (counts[nextPos] <= nowCount + 1) continue;
				counts[nextPos] = nowCount + 1;

				q.push({ nextPos, nowCount + 1 });
			}
		}
	}

	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<int> pann(101, 0);
		for (int i = 1; i <= 100; ++i) pann[i] = i;
		for (int i = 0; i < n + m; ++i)
		{
			int to, from;
			cin >> to >> from;
			pann[to] = from;
		}

		cout << bfs(pann);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_16928::Solution();

	return 0;
}