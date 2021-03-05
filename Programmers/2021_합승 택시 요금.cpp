// 21.03.05. 금
// kakao 2021_합승 택시 요금 https://programmers.co.kr/learn/courses/30/lessons/72413
// 다익스트라.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > roadCost;
vector<int> joinCost;
vector<int> ACost;
vector<int> BCost;

// 각 지점까지의 비용 계산.
void Dijkstra(int n, int start, vector<int>& whoCost)
{
	whoCost.assign(n + 1, 2e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >q;
	q.push({ 0, start });
	whoCost[start] = 0;

	while (!q.empty())
	{
		int pos = q.top().second;
		int cost = q.top().first;
		q.pop();
		for (int i = 1; i <= n; ++i)
		{
			if (roadCost[pos][i] == 0) continue;
			if (whoCost[i] <= cost + roadCost[pos][i]) continue;
			whoCost[i] = cost + roadCost[pos][i];
			q.push({ whoCost[i], i });
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 2e9;
	roadCost.assign(n + 1, vector<int>(n + 1));
	for (int i = 0; i < fares.size(); ++i)
	{
		roadCost[fares[i][0]][fares[i][1]] = fares[i][2];
		roadCost[fares[i][1]][fares[i][0]] = fares[i][2];
	}

	Dijkstra(n, s, joinCost);
	Dijkstra(n, a, ACost);
	Dijkstra(n, b, BCost);

	for (int i = 1; i <= n; ++i)
	{
		answer = min(answer, joinCost[i] + ACost[i] + BCost[i]);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} }) << endl;
	cout << solution(7, 3, 4, 1, { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} }) << endl;
	cout << solution(6, 4, 5, 6, { {2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9} }) << endl;

	return 0;
}