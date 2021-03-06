// 21.03.06. 토
// 힙_디스크 컨트롤러 https://programmers.co.kr/learn/courses/30/lessons/42627
// 최소힙.

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	int answer = 0, size = jobs.size();
	int time = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	sort(jobs.begin(), jobs.end(), cmp);

	int index = 0;
	time += jobs[index][0];
	// 맨 처음과 동시에 들어온 작업들 함께 큐에 넣어줌.
	for (index; index < jobs.size(); ++index)
	{
		if (jobs[0][0] == jobs[index][0])
			q.push({ jobs[index][1], jobs[index][0] });
		else break;
	}

	while (1)
	{
		if (q.empty())
		{
			if (index == size) break;
			// 다음 작업의 시간이 현재 시간보다 나중일때, 시간을 그때로 건너 뜀.
			time = jobs[index][0];
			q.push({ jobs[index][1], jobs[index][0] });
			++index;
		}

		time += q.top().first;
		int startTime = q.top().second;
		q.pop();
		answer += (time - startTime);

		while (index < size)
		{
			if (jobs[index][0] <= time)
			{
				q.push({ jobs[index][1], jobs[index][0] });
				++index;
			}
			else break;
		}
	}


	return answer / size;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution({ {0, 3}, {1, 9}, {2, 6} }) << endl;

	// 이 두개의 답은 같지만,
	cout << solution({ {0,1}, {0,2}, {0,3} }) << endl;
	cout << solution({ {0,3}, {0,2}, {0,1} }) << endl;
	// 이 두개의 답은 다르다.
	cout << solution({ {0, 3}, { 1, 9 }, { 2, 6 }, { 20, 10 }, {20, 5} }) << endl;
	cout << solution({ {0, 3}, { 1, 9 }, { 2, 6 }, { 20, 5 }, {20, 10} }) << endl;

	// 문제 조건에 작업이 없을때는 먼저 들어온 작업부터 처리한다고 했지만, 그럼 맨 처음에 들어온 작업은 왜 동시에 들어오는 것으로 취급됐을까?
	// 문제의 조건을 분명하게 해야한다고 생각.

	return 0;
}