// 21.03.08. 월
// 정렬_H-Index https://programmers.co.kr/learn/courses/30/lessons/42747
// 정렬. 근데 문제이해가 더 어려웠음.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.first > b.first;
}

int solution(vector<int> citations) {
	int answer = 0, count = 0;
	int size = citations.size();

	vector<pair<int, int> > v;
	for (int i = 0; i < size; ++i)
	{
		v.push_back({ citations[i], i + 1 });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < size; ++i)
	{
		if (i >= v[i].first) return i;
	}
	if (answer == 0) answer = size;
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution({ 3, 0, 6, 1, 5 }) << "\n";//3
	cout << solution({ 1, 2, 3, 4, 5 }) << "\n";//3
	cout << solution({ 0, 0, 0, 0, 5 }) << "\n";//1
	cout << solution({ 10,8,5,4,3 }) << "\n";	//4
	cout << solution({ 25,8,5,3,3 }) << "\n";	//3
	cout << solution({ 1, 2, 3, 3, 3, 3, 4, 4, 5, 6, 7, 7, 8, 8, 9, 9, 10, 10, 10 }) << "\n";	//7
	cout << solution({ 2, 2 }) << "\n";	//2

	return 0;
}