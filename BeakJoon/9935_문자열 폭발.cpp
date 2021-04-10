// 21.04.10. 토
// 9935: 문자열 폭발 https://www.acmicpc.net/problem/9935
// 스택.

// 45% 시간초과 Failed.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace BOJ_9935
{
	void Solution()
	{
		string str, key, answer;
		cin >> str >> key;
		stack<char> st, store;
		int size = str.size(), pointer = key.size() - 1;

		for (int i = 0; i < size; ++i)
		{
			st.push(str[i]);
		}

		while (!st.empty())
		{
			if (key[pointer] == st.top()) pointer--;
			else
			{
				pointer = key.size() - 1;
				if (key[pointer] == st.top()) pointer--;
			}
			store.push(st.top());
			st.pop();
			if (pointer == -1)
			{
				pointer = key.size() - 1;
				for (int i = 0; i < key.size(); ++i) store.pop();
				while (1)
				{
					if (store.empty() || key.find(store.top()) == string::npos) break;
					st.push(store.top());
					store.pop();
				}
			}
		}

		if (store.empty()) cout << "FRULA";
		else
		{
			while (!store.empty())
			{
				cout << store.top();
				store.pop();
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_9935::Solution();

	return 0;
}