// 20.09.17 수
// 1697: 숨바꼭질 https://www.acmicpc.net/problem/1697
// BFS
#include <iostream>
#include <queue>
using namespace std;

// 0 <= 위치 <= 100000.

#define MAX 100001

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	bool visit[MAX] = { false };

	// (수빈위치, 이동카운트).
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	visit[n] = true;

	int step, count = 0;

	while (!q.empty())
	{
		step = q.front().first;
		count = q.front().second;
		q.pop();

		//cout << step << " " << count << endl;
		if (step == k) break;

		if (step + 1 < MAX && !visit[step + 1])
		{
			q.push(make_pair(step + 1, count + 1));
			visit[step + 1] = true;
		}
		if (step - 1 >= 0 && !visit[step - 1])
		{
			q.push(make_pair(step - 1, count + 1));
			visit[step - 1] = true;
		}
		if (step * 2 < MAX && !visit[step * 2])
		{
			q.push(make_pair(step * 2, count + 1));
			visit[step * 2] = true;
		}
	}

	cout << count;
}