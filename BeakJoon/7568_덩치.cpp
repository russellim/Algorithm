// 20.10.02. 금
// 7568: 덩치 https://www.acmicpc.net/problem/7568
// 브루트포스 알고리즘
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;
	pair<int, int> p[50];
	int rank;

	for (int i = 0; i < n; ++i)
	{
		cin >> p[i].first >> p[i].second;
	}

	for (int i = 0; i < n; ++i)
	{
		rank = 1;
		for (int j = 0; j < n; ++j)
		{
			if (p[i].first < p[j].first && p[i].second < p[j].second)
			{
				rank++;
			}
		}
		cout << rank << " ";
	}

	return 0;
}