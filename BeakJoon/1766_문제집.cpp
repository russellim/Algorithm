// 21.06.30. 수
// 1766: 문제집 https://www.acmicpc.net/problem/1766
// 위상정렬.

// 푸는중.. 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_1766
{
	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<int> pre_count(n + 1, 0);
		vector<vector<int> > pre(n + 1, vector<int>());
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			pre[b].push_back(a);
		}


	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1766::Solution();
	return 0;
}