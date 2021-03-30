// 21.03.26. 금
// 1043: 거짓말 https://www.acmicpc.net/problem/1043
// 구현.
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_1043
{
	void Solution()
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int> > partyWho(m + 1, vector<int>());	// 파티별 참석한 사람.
		vector<vector<int> > peopleParti(n + 1, vector<int>());	// 사람별 참석한 파티.
		vector<int> knowTrue;	// 진실을 아는 사람.
		vector<bool> visitPeople(n + 1, false);	// 탐색한 사람.
		vector<bool> visitParty(m + 1, false);	// 탐색한 파티.

		// input.
		for (int i = 0; i <= m; ++i)
		{
			int many;
			cin >> many;
			for (int j = 0; j < many; ++j)
			{
				int number;
				cin >> number;
				if (i == 0) knowTrue.push_back(number);
				else
				{
					partyWho[i].push_back(number);
					peopleParti[number].push_back(i);
				}
			}
		}

		// 진실 아는 사람 없으면 모든 파티 ㅇㅋ.
		if (knowTrue.empty())
		{
			cout << m;
			return;
		}

		// 진실 아는 사람이 참석한 파티를 탐색.
		for (int i = 0; i < knowTrue.size(); ++i)
		{
			int knowPerson = knowTrue[i];
			visitPeople[knowPerson] = true;
			for (int j = 0; j < peopleParti[knowPerson].size(); ++j)
			{
				int truePartyNumber = peopleParti[knowPerson][j];
				if (visitParty[truePartyNumber]) continue;
				--m;

				// 같이 참여한 사람도 진실 아는 목록에 추가됨.
				for (int k = 0; k < partyWho[truePartyNumber].size(); ++k)
				{
					int partiOtherPerson = partyWho[truePartyNumber][k];
					if (visitPeople[partiOtherPerson]) continue;
					knowTrue.push_back(partiOtherPerson);
				}
				visitParty[truePartyNumber] = true;
			}
		}

		// output.
		cout << m;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1043::Solution();

	return 0;
}