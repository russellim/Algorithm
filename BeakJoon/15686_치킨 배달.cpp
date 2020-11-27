// 20.11.24. 화
// 15686: 치킨 배달 https://www.acmicpc.net/problem/15686
// 브루트포스, 백트래킹
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P; // 좌표.
int n, m; // n x n / m개 치킨집.
int answer = 1e9; // 치킨거리 최솟값.
vector<P> homes;
vector<P> chickens;
vector<vector<int> > dists;
vector<int> indexes;

void GetChickenDistance(int count, int start)
{
	if (count == m)
	{
		int sumDist = 0;
		vector<int> disttemp;

		for (int i = 0; i < dists.size(); ++i)
		{
			disttemp.clear();
			for (int j = 0; j < indexes.size(); ++j)
			{
				disttemp.push_back(dists[i][indexes[j]]);
			}
			sumDist += *min_element(disttemp.begin(), disttemp.end());
		}
		answer = min(answer, sumDist);

		return;
	}
	for (int i = start; i < chickens.size(); ++i)
	{
		indexes.push_back(i);
		GetChickenDistance(count + 1, i + 1);
		indexes.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int temp;
			cin >> temp;
			if (temp == 1) homes.push_back({ i,j });
			else if (temp == 2) chickens.push_back({ i,j });
		}
	}

	dists.assign(homes.size(), vector<int>(chickens.size()));

	for (int i = 0; i < homes.size(); ++i)
	{
		for (int j = 0; j < chickens.size(); ++j)
		{
			dists[i][j] = abs(homes[i].first - chickens[j].first) + abs(homes[i].second - chickens[j].second);
		}
	}
	GetChickenDistance(0, 0);
	cout << answer;

	return 0;
}