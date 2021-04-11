// 21.04.10. 토
// 9935: 문자열 폭발 https://www.acmicpc.net/problem/9935
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_9935
{
	void Solution()
	{
		string str, key, answer, temp;
		cin >> str >> key;

		for (int i = 0; i < str.size(); ++i)
		{
			answer += str[i];
			if (answer.size() < key.size()) continue;
			if (str[i] != key[key.size() - 1]) continue;

			int pointer = key.size() - 1;
			for (int j = answer.size() - 1; j >= 0; --j)
			{
				if (answer[j] != key[pointer]) break;
				--pointer;
				if (pointer < 0)
				{
					answer.erase(answer.begin() + j, answer.end());
					break;
				}
			}
		}

		if (answer == "") cout << "FRULA";
		else cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_9935::Solution();

	return 0;
}