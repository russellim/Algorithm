// 21.02.16. 화
// 1620: 나는야 포켓몬 마스터 이다솜 https://www.acmicpc.net/problem/1620
// 이분탐색, 해시.
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace PokemonMaster
{
	int n, m;
	unordered_map<int, string> docuMap;
	vector<pair<int, string> > docuVec;

	void Output(string answer);

	bool cmp(pair<int, string>& a, pair<int, string>& b)
	{
		return a.second < b.second;
	}

	int BinarySearch(string name)
	{
		int start = 0, end = docuVec.size() - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (docuVec[mid].second == name)
			{
				return docuVec[mid].first;
			}
			if (docuVec[mid].second < name)
				start = mid + 1;
			else
				end = mid - 1;
		}
	}

	void PokemonTest()
	{
		sort(docuVec.begin(), docuVec.end(), cmp);

		string quiz, answer;
		while (m--)
		{
			cin >> quiz;
			if (isalpha(quiz[0]))
			{
				answer = to_string(BinarySearch(quiz));
			}
			else
			{
				answer = docuMap[atoi(quiz.c_str())];
			}
			Output(answer);
		}
	}

	void Input()
	{
		string name;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> name;
			docuMap.insert({ i + 1, name });
			docuVec.push_back({ i + 1, name });
		}
	}
	void Output(string answer)
	{
		cout << answer << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	PokemonMaster::Input();
	PokemonMaster::PokemonTest();

	return 0;
}