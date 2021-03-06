// 21.03.06. 토
// 힙_더 맵게 https://programmers.co.kr/learn/courses/30/lessons/42626
// 최소힙.
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < scoville.size(); ++i)
	{
		q.push(scoville[i]);
	}

	while (1)
	{
		if (q.empty())
		{
			answer = -1;
			break;
		}
		if (q.top() > K) break;
		int a = q.top();
		q.pop();
		if (q.empty())
		{
			answer = -1;
			break;
		}
		int b = q.top();
		q.pop();
		q.push(a + (b * 2));
		answer++;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);

	return 0;
}