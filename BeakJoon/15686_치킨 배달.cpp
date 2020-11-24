// 20.11.24. 화
// 15686: 치킨 배달 https://www.acmicpc.net/problem/15686
// 브루트포스
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);


	int n, m, answer = 0;
	cin >> n >> m;
	vector<vector<int> > city(n, vector<int>(n));
	vector<P> chickens, homes;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> city[i][j];
			if (city[i][j] == 2) chickens.push_back({ i,j });
			else if (city[i][j] == 1) homes.push_back({ i, j });
		}
	}
	vector<vector<int> > dist(chickens.size());
	for (int i = 0; i < chickens.size(); ++i)
	{
		dist[i].push_back(0);
		for (int j = 0; j < homes.size(); ++j)
		{
			int temp = abs(chickens[i].first - homes[j].first) + abs(chickens[i].second - homes[j].second);
			dist[i][0] += temp;
			dist[i].push_back(temp);
		}
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < chickens.size(); ++i)
	{
		for (int j = 0; j < homes.size() + 1; ++j)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	if (m == 1)
	{
		cout << dist[0][0];
	}
	else
	{
		for (int j = 1; j < homes.size() + 1; ++j)
		{
			vector<int> temp;
			for (int i = 0; i < m; ++i)
			{
				temp.push_back(dist[i][j]);
			}
			answer += *min_element(temp.begin(), temp.end());
		}
		cout << answer;
	}

	return 0;
}