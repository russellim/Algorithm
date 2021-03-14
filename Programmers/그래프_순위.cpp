// 21.03.14. 일
// 그래프_순위 https://programmers.co.kr/learn/courses/30/lessons/49191
// 플로이드 와샬 알고리즘
// A->B 비용과 A->x->B 비용을 비교해 최소비용 구하는 알고리즘.
// 이렇게 구한 경로가 모두 존재하는 노드는 순위를 특정할 수 있다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 1e9; //이동불가.

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int> > route(n + 1, vector<int>(n + 1, MAX));	// 경로 비용 저장. (0, 1, MAX).
	auto conn = route;	// 특정 지점까지 이동 가능한 최소 비용.
	for (int i = 1; i <= n; ++i)
	{
		route[i][i] = conn[i][i] = 0;	// 0은 자기자신.
	}

	for (int i = 0; i < results.size(); ++i)
	{
		route[results[i][0]][results[i][1]] =
			conn[results[i][0]][results[i][1]] =
			conn[results[i][1]][results[i][0]] = 1;
	}

	for (int mid = 1; mid <= n; ++mid)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				route[i][j] = min(route[mid][j] + route[i][mid], route[i][j]);
				conn[i][j] = conn[j][i] = min(route[i][j], conn[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (conn[i][j] == MAX) break;
			if (j == n) answer++;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} }) << "\n"; // 2.
	cout << solution(5, { {1, 2}, {3,1}, {4,1}, {5,1}, {3,4}, {5,4}, {5,3} }) << "\n"; // 5.

	return 0;
}