// 21.07.02. 금
// 1725: 히스토그램 https://www.acmicpc.net/problem/1725
// stack.
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

namespace BOJ_1725
{
	void Solution()
	{
		int n, answer = 0;
		cin >> n;
		vector<int> arr(n + 2, 0);
		for (int i = 1; i <= n; ++i) cin >> arr[i];

		stack<int> st;

		st.push(0);
		for (int i = 1; i <= n + 1; ++i)
		{
			int len = arr[i];
			while (!st.empty() && arr[st.top()] > arr[i])
			{
				int h = arr[st.top()];
				st.pop();
				int w = i - st.top() - 1;
				answer = max(answer, h * w);
			}

			st.push(i);
		}

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1725::Solution();
	return 0;
}
