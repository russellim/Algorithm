// 21.03.10. 수
// 탐욕법_단속카메라 https://programmers.co.kr/learn/courses/30/lessons/42884

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 도로를 빨리 나가는 순으로 나가는 시점에 설치.
vector<bool> visit;

bool cmp(vector<int>& a, vector<int>& b)
{
	return a[1] < b[1];
}

void CheckOverlap(vector<vector<int>>& routes, int end)
{
	for (int i = 0; i < routes.size(); ++i)
	{
		if (visit[i]) continue;
		if (end >= routes[i][0] && end <= routes[i][1])
		{
			visit[i] = true;
		}
	}
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	visit.assign(routes.size(), false);
	sort(routes.begin(), routes.end(), cmp);

	for (int i = 0; i < routes.size(); ++i)
	{
		if (visit[i]) continue;
		visit[i] = true;
		CheckOverlap(routes, routes[i][1]);
		answer++;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }) << "\n";
	cout << solution({ {1,3}, {5,8} }) << "\n";
	cout << solution({ {0, 4}, {0, 3}, {0, 2}, {0, 1} }) << "\n";
	cout << solution({ {0,2},{2,3},{3,4},{4,6} }) << "\n";

	return 0;
}

/*
 정확성은 다 맞는데 효율성에서 그냥 틀린 코드.
 이동한 거리가 짧은 순으로 앞뒤에 먼저 설치.
 */
 //vector<bool> visit;
 //
 //bool cmp(vector<int>& a, vector<int>& b)
 //{
 //	return ((a[1] - a[0]) < (b[1] - b[0]));
 //}
 //
 //void CheckOverlap(vector<vector<int>>& routes, int start, int end)
 //{
 //	for (int i = 0; i < visit.size(); ++i)
 //	{
 //		if (visit[i]) continue;
 //		if ((start >= routes[i][0] && start <= routes[i][1]) ||
 //			(end >= routes[i][0] && end <= routes[i][1]))
 //		{
 //			visit[i] = true;
 //		}
 //	}
 //}
 //
 //int solution(vector<vector<int>> routes) {
 //	int answer = 0;
 //	sort(routes.begin(), routes.end(), cmp);
 //	visit.assign(routes.size(), false);
 //
 //	for (int i = 0; i < routes.size(); ++i)
 //	{
 //		if (visit[i]) continue;
 //		visit[i] = true;
 //		CheckOverlap(routes, routes[i][0], routes[i][1]);
 //		answer++;
 //	}
 //
 //	return answer;
 //}