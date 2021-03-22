// 21.03.22. 월
// 12851: 숨바꼭질 2 https://www.acmicpc.net/problem/12851
// BFS.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

namespace BOJ_12851
{
	int n, k; // n 수빈, k 동생.
	int fastCount = 0, fastTime = INT_MAX, maxPos = 100000;
	vector<bool> visit;
	queue<pair<int, int>> q;

	void CheckNextPos(int nextPos, int nextTime)
	{
		if (!(nextPos >= 0 && nextPos <= maxPos)) return;

		if (nextPos == k)
		{
			fastTime = nextTime;
			fastCount++;
		}
		if (!visit[nextPos]) q.push({ nextPos, nextTime });
	}

	void Solution()
	{
		cin >> n >> k;
		if (n == k)
		{
			cout << "0\n1";
			return;
		}

		visit.assign(100000 + 1, false);
		q.push({ n, 0 });

		while (!q.empty())
		{
			int now = q.front().first;
			int time = q.front().second;
			q.pop();

			if (time + 1 > fastTime) break;

			CheckNextPos(now + 1, time + 1);
			CheckNextPos(now - 1, time + 1);
			CheckNextPos(now * 2, time + 1);

			visit[now] = true;
		}

		// output.
		cout << fastTime << "\n" << fastCount;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_12851::Solution();

	return 0;
}