// 21.02.28. 일
// 16953: A -> B https://www.acmicpc.net/problem/16953
// BFS.
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

namespace BOJ_16953
{
	typedef long long LL;
	LL a, b;
	unordered_map<LL, bool> visit;
	queue<pair<LL, int>> q;

	LL Multi(LL n)
	{
		return n * 2;
	}

	LL AddRight(LL n)
	{
		return n * 10 + 1;
	}

	void CheckVisit(LL temp, int count)
	{
		if (temp < b && !visit[temp])
		{
			visit[temp] = true;
			q.push({ temp, count });
		}
	}

	int BFS()
	{
		LL temp = 0;
		q.push({ a, 1 });

		while (!q.empty())
		{
			LL num = q.front().first;
			int count = q.front().second;
			q.pop();
			count++;

			temp = Multi(num);
			if (temp == b) return count;
			CheckVisit(temp, count);

			temp = AddRight(num);
			if (temp == b) return count;
			CheckVisit(temp, count);
		}

		return -1;
	}

	void Solution()
	{
		cin >> a >> b;

		// output.
		cout << BFS();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_16953::Solution();

	return 0;
}