// 20.12.07. 월
// 11403: 경로 찾기 https://www.acmicpc.net/problem/11403
// BFS.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int> > in(n, vector<int>(n, 0));
	auto answer = in;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> in[i][j];
		}
	}

	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		q.push(i);
		int pivot = i;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int j = 0; j < n; ++j)
			{
				if (in[cur][j] == 1 && answer[pivot][j] == 0)
				{
					q.push(j);
					answer[pivot][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}