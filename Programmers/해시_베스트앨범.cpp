// 21.03.07. 일
// 해시_베스트앨범 https://programmers.co.kr/learn/courses/30/lessons/42579
// 해시.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmpTotal(pair<string, unsigned int>& a, pair<string, unsigned int>& b)
{
	return a.second > b.second;
}

bool cmpPlayTime(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

vector<pair<string, unsigned int> > SumTotalPlayTime(int size, vector<string>& genres, vector<int>& plays)
{
	unordered_map<string, unsigned int> totalMap;
	for (int i = 0; i < size; ++i)
	{
		totalMap[genres[i]] += plays[i];
	}
	vector<pair<string, unsigned int> > totalVec;
	for (auto it = totalMap.begin(); it != totalMap.end(); ++it)
	{
		totalVec.push_back(*it);
	}
	sort(totalVec.begin(), totalVec.end(), cmpTotal);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int size = genres.size();

	// 총 재생 시간 순으로 정렬된 장르별 시간 배열 구하기.
	auto totalVec = SumTotalPlayTime(size, genres, plays);
	int genresCount = totalVec.size();

	// genres 배열 탐색으로 많이 들은 장르순으로 시간과 인덱스 저장.
	// bestGenres[j][..] : j+1번째로 많이 들은 장르.
	vector<vector<pair<int, int> > > bestGenres(genresCount, vector<pair<int, int> >());
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < genresCount; ++j)
		{
			if (genres[i] == totalVec[j].first)
			{
				bestGenres[j].push_back({ plays[i], i });	// { 시간, 인덱스 }
				break;
			}
		}
	}
	// 각 장르 안에서도 많이 들은 순으로 정렬.
	for (int i = 0; i < genresCount; ++i)
	{
		sort(bestGenres[i].begin(), bestGenres[i].end(), cmpPlayTime);
	}

	// 각 장르에서 들은 순 최대 2개까지 뽑아 저장.
	for (int i = 0; i < genresCount; ++i)
	{
		for (int j = 0; j < bestGenres[i].size(); ++j)
		{
			if (j == 2) break;
			answer.push_back(bestGenres[i][j].second);
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> answer;
	answer = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
	for (auto x : answer) cout << x << " ";

	return 0;
}