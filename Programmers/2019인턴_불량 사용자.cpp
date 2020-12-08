// 20.12.08. 화
// kakao 2019인턴_불량 사용자 https://programmers.co.kr/learn/courses/30/lessons/64064
// 백트래킹.

// 문제 처음 봤을때는(약 한달 전) 백트래킹을 몰라서 set도 쓰고 이리저리 하다 포기했었는데
// 백트래킹 배우고나서 잘 풀렸다.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string> > correct;	// banned_id 목록과 일치하는 id 목록.
vector<vector<string> > answerList;	// 구한 경우.
vector<string> tempid;

int banned_size;

void MakeBanList(int count)
{
	if (count == banned_size)
	{
		// 중복이 있으면 목록에 올라가지 않습니다.
		auto sorttemp = tempid;
		sort(sorttemp.begin(), sorttemp.end());
		sorttemp.erase(unique(sorttemp.begin(), sorttemp.end()), sorttemp.end());
		if (sorttemp.size() == count)
		{
			answerList.push_back(sorttemp);
		}
		return;
	}

	for (int i = 0; i < correct[count].size(); ++i)
	{
		tempid.push_back(correct[count][i]);
		MakeBanList(count + 1);
		tempid.pop_back();
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	correct.assign(banned_id.size(), vector<string>(0));
	banned_size = banned_id.size();

	// 일치하는 id 목록 만들기.
	for (int i = 0; i < banned_size; ++i)
	{
		for (int j = 0; j < user_id.size(); ++j)
		{
			if (banned_id[i].size() == user_id[j].size())
			{
				bool IsCorrect = true;
				for (int k = 0; k < banned_id[i].size(); ++k)
				{
					if (banned_id[i][k] != '*' && user_id[j][k] != banned_id[i][k])
					{
						IsCorrect = false;
						break;
					}
				}
				if (IsCorrect) correct[i].push_back(user_id[j]);
			}
		}
	}

	MakeBanList(0);

	sort(answerList.begin(), answerList.end());
	answerList.erase(unique(answerList.begin(), answerList.end()), answerList.end());

	return answerList.size();
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<string> s1 = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> s2 = { "*rodo", "*rodo", "******" };
	cout << solution(s1, s2) << endl;
	cout << endl;

	return 0;
}