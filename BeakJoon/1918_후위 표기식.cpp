// 21.03.29. 월
// 1918: 후위 표기식 https://www.acmicpc.net/problem/1918
// 스택.
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int PriorityNumber(char c)
{
	if (c == '(') return 0;
	else if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 2;
}

namespace BOJ_1918
{
	void Solution()
	{
		stack<char> st;
		string expr;
		cin >> expr;

		for (int i = 0; i < expr.size(); ++i)
		{
			if (isalpha(expr[i])) cout << expr[i];	// 알파벳은 바로 출력.
			else
			{
				if (st.empty()) st.push(expr[i]);
				else
				{
					// 괄호 끝 나오면 괄호 처음 만날때 까지 스택 다 출력.
					if (expr[i] == ')')
					{
						while (st.top() != '(')
						{
							cout << st.top();
							st.pop();
						}
						st.pop();
					}
					// 우선순위 높은거 만나면 push.
					else if (PriorityNumber(st.top()) < PriorityNumber(expr[i])) st.push(expr[i]);
					// 우선순위 낮은거 만나면.
					else
					{
						if (expr[i] == '(') st.push(expr[i]);
						else
						{
							cout << st.top();
							st.pop();

							if (!st.empty() && PriorityNumber(st.top()) == PriorityNumber(expr[i]))
							{
								cout << st.top();
								st.pop();
							}
							st.push(expr[i]);
						}
					}
				}
			}
		}

		// 남은거 출력.
		while (!st.empty())
		{
			if (st.top() == '(') st.pop();
			else
			{
				cout << st.top();
				st.pop();
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1918::Solution();

	return 0;
}