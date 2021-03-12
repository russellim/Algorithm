// 21.03.12. 금
// DFS/BFS_여행경로 https://programmers.co.kr/learn/courses/30/lessons/43164
// DFS.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visit;
int ticketCount;
vector<vector<string> > answers;
vector<string> answerTemp;

bool FindNextAirport(vector<vector<string>>& tickets, string now, int index)
{
	if (index > ticketCount)
	{
		answers.push_back(answerTemp);
		return true;
	}
	bool isComplete = false;
	for (int i = 0; i < ticketCount; ++i)
	{
		if (visit[i]) continue;
		if (tickets[i][0] != now) continue;

		visit[i] = true;
		string temp = answerTemp[index];
		answerTemp[index] = tickets[i][1];

		isComplete = FindNextAirport(tickets, tickets[i][1], index + 1);

		visit[i] = false;
		if (!isComplete) answerTemp[index] = temp;
	}
	if (isComplete) return true;
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	int visitCount = 0;
	string now = "ICN";

	ticketCount = tickets.size();
	visit.assign(ticketCount, false);
	answerTemp.assign(ticketCount + 1, "ZZZ"); // +1은 출발점 포함.
	answerTemp[0] = now;

	FindNextAirport(tickets, now, 1);

	sort(answers.begin(), answers.end());

	return answers[0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	auto s = solution({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} });
	for (auto x : s) cout << x << " ";
	cout << "\n";

	s = solution({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} });
	for (auto x : s) cout << x << " ";
	cout << "\n";

	s = solution({ {"ICN", "A"}, {"A", "C"}, {"A", "D"}, {"D", "B"}, {"B", "A"} });
	for (auto x : s) cout << x << " ";
	cout << "\n";

	return 0;
}