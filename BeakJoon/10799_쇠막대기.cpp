// 20.12.05. 토
// 10799: 쇠막대기 https://www.acmicpc.net/problem/10799
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	int stick = 0, answer = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			if (str[i + 1] == ')')
			{
				// () 레이저에 겹친 막대 잘림 = 막대 수만큼 더하기.
				answer += stick;
				i++;
				continue;
			}
			// 막대 추가.
			stick++;
		}
		else
		{
			// 막대 하나 끝. 끝자락 하나 더하기.
			stick--;
			answer++;
		}
	}

	cout << answer;

	return 0;
}