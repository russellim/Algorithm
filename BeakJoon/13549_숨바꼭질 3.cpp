// 21.03.23. 화
// 13549: 숨바꼭질 3 https://www.acmicpc.net/problem/13549
// BFS.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

namespace BOJ_13549
{
	int n, k, answer = INT_MAX; // n 수빈, k 동생.
	int maxPos = 100000;
	vector<bool> visit;
	queue<pair<int, int>> q;

	int CheckNextPos(int nextPos, int nextTime)
	{
		if (!(nextPos >= 0 && nextPos <= maxPos)) return INT_MAX;

		if (nextPos == k) return nextTime;
		if (!visit[nextPos]) q.push({ nextPos, nextTime });
		return INT_MAX;
	}

	void Solution()
	{
		cin >> n >> k;
		if (n == k)
		{
			cout << "0";
			return;
		}

		visit.assign(100000 + 1, false);
		q.push({ n, 0 });

		while (!q.empty())
		{
			int now = q.front().first;
			int time = q.front().second;
			q.pop();

			if (answer <= time) continue;

			answer = min(answer, CheckNextPos(now * 2, time));
			answer = min(answer, CheckNextPos(now + 1, time + 1));
			answer = min(answer, CheckNextPos(now - 1, time + 1));

			visit[now] = true;
		}

		// output.
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_13549::Solution();

	return 0;
}