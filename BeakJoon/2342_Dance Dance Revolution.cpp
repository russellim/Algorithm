// 21.06.23. 수
// 2342: Dance Dance Revolution https://www.acmicpc.net/problem/2342
// DP, DFS.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

namespace BOJ_2342
{
	constexpr int MAX = 100000;
	constexpr int DIR = 5;
	vector<int> cmd(MAX + 1);
	int cmdSize = 0;
	vector<vector<vector<int> > > dp(MAX + 1, vector<vector<int> >(DIR, vector<int>(DIR, -1)));

	int CheckScore(int from, int to)
	{
		if (from == to) return 1; // 같은곳.
		if (from == 0) return 2;  // 0에서 이동..
		if (abs(from - to) == 2) return 4; // 반대편 이동.
		return 3; // 인접한곳 이동.
	}

	int dfs(int foot1, int foot2, int index)
	{
		if (index == cmdSize) return 0;

		int& now = dp[index][foot1][foot2];
		if (now != -1) return now;

		return now = min(dfs(cmd[index], foot2, index + 1) + CheckScore(foot1, cmd[index]),
			dfs(foot1, cmd[index], index + 1) + CheckScore(foot2, cmd[index]));
	}

	void Solution()
	{
		int point;
		while (1)
		{
			cin >> point;
			if (point == 0) break;
			//cmd.reserve(cmd.size() + 1); // 이거 시간 오래걸리니까 주의.
			cmd[cmdSize++] = point;
		}

		cout << dfs(0, 0, 0);
	}
}

int main()
{
	BOJ_2342::Solution();

	return 0;
}