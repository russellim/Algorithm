// 20.10.10. 토
// 1389: 케빈 베이컨의 6단계 법칙 https://www.acmicpc.net/problem/1389
// BFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int> >mate(n, vector<int>(n, 0));
	vector<int> sum(n, 0);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		mate[x - 1][y - 1] = mate[y - 1][x - 1] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		queue <pair<int, int>> q;	// (탐색할 사람, i와의 관계 깊이)
		vector<bool> check(n, false);
		q.push({ i, 0 });
		check[i] = true;
		while (!q.empty())
		{
			int now = q.front().first;
			int num = q.front().second;
			q.pop();
			for (int j = 0; j < n; ++j)
			{
				if (mate[now][j] == 1 && !check[j])
				{
					check[j] = true;
					sum[i] += num + 1;
					q.push({ j, num + 1 });
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i < n; ++i)
	{
		if (sum[answer] > sum[i])
			answer = i;
	}

	// 번호 0부터 했으니까 +1.
	cout << answer + 1;

	return 0;
}