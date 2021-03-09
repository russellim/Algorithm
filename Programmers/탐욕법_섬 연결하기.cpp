// 21.03.09. 화
// 탐욕법_섬 연결하기 https://programmers.co.kr/learn/courses/30/lessons/42861
// 프림 알고리즘 사용.

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Connect
{
	int dest, cost;
};

int answer = 0, connCount = 0;
vector<vector<Connect> > conn;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // {cost, from}.
vector<bool> visit;

void FindBridge(int start)
{
	visit[start] = true;
	connCount++;

	for (int i = 0; i < conn[start].size(); ++i)
	{
		if (visit[conn[start][i].dest]) continue;
		pq.push({ conn[start][i].cost, conn[start][i].dest });
	}
}

int solution(int n, vector<vector<int>> costs) {
	conn.assign(n, vector<Connect>());
	visit.assign(n, false);
	for (int i = 0; i < costs.size(); ++i)
	{
		conn[costs[i][0]].push_back({ costs[i][1], costs[i][2] });
		conn[costs[i][1]].push_back({ costs[i][0], costs[i][2] });
	}

	FindBridge(0);

	while (connCount != n)
	{
		auto next = pq.top();
		pq.pop();
		if (visit[next.second]) continue;
		answer += next.first;
		FindBridge(next.second);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} });

	return 0;
}