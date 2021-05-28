// 21.05.28. 금
// 1937: 욕심쟁이 판다 https://www.acmicpc.net/problem/1937
// DP + DFS.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

namespace BOJ_1937
{
	struct Pos
	{
		int r, c;

		friend Pos operator+(Pos& a, Pos& b)
		{
			return { a.r + b.r, a.c + b.c };
		}
	};
	Pos direction[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	vector<vector<int> > forest;
	vector<vector<int> > dp; // 냠냠칸 수 저장.
	int answer = 1;

	bool IsRange(int n, Pos pos)
	{
		return (pos.r >= 0 && pos.c >= 0 && pos.r < n&& pos.c < n);
	}

	void dfs(int n, Pos now)
	{
		dp[now.r][now.c] = 1;

		for (int i = 0; i < 4; ++i)
		{
			Pos next = now + direction[i];
			if (!IsRange(n, next)) continue;
			if (forest[now.r][now.c] <= forest[next.r][next.c]) continue;
			// 한번 검사 했던 경로는 더 가지 않는다.
			if (dp[next.r][next.c] != -1)	// 냠냠칸 수 정보가 있으면.
			{
				// 더 나가지 말고 그 칸 수 +1.
				dp[now.r][now.c] = max(dp[now.r][now.c], dp[next.r][next.c] + 1);
				answer = max(answer, dp[now.r][now.c]);
				continue;
			}
			dfs(n, next);
			dp[now.r][now.c] = max(dp[now.r][now.c], dp[next.r][next.c] + 1);
			answer = max(answer, dp[now.r][now.c]);
		}
	}

	void Solution()
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << n;
			return;
		}

		forest.assign(n, vector<int>(n));
		dp.assign(n, vector<int>(n, -1));

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> forest[i][j];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dp[i][j] != -1) continue;	// 냠냠칸 수가 이미 있으면 계산 안해도됨.
				dfs(n, { i, j });
			}
		}

		// output.
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1937::Solution();

	return 0;
}