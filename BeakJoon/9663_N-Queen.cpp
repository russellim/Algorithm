// 20.11.16. 월
// 9663: N-Queen https://www.acmicpc.net/problem/9663
// 백트래킹, dfs.
#include <iostream>

using namespace std;

int answer, n;
int* exist_vertical; // 위에줄부터 넣을거니까 세로줄만 값 확인.
int* exist_crossright;
int* exist_crossleft;

// depth: 위부터 줄 순서.
void dfs(int depth)
{
	if (depth == n)
	{
		answer++;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (exist_vertical[i] == 1 || exist_crossright[depth + i] == 1 || exist_crossleft[n - 1 + depth - i] == 1)
			continue;

		exist_vertical[i] = exist_crossright[depth + i] = exist_crossleft[n - 1 + depth - i] = 1;
		dfs(depth + 1);
		exist_vertical[i] = exist_crossright[depth + i] = exist_crossleft[n - 1 + depth - i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n;
	exist_vertical = new int[n];
	exist_crossright = new int[2 * n - 1];
	exist_crossleft = new int[2 * n - 1];

	dfs(0);

	cout << answer;

	return 0;
}