// 21.06.18. 금
// 14003: 가장 긴 증가하는 부분 수열 5 https://www.acmicpc.net/problem/14003
// LIS, 이분탐색, 스택!!!.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace BOJ_14003
{
	vector<int> store;
	stack<pair<int, int> > st; // { 입력된 숫자, store에 매치된 인덱스 } 가 차례대로 들어갈 스택.

	void Solution()
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int num, index;
			cin >> num;

			if (store.empty() || store.back() < num)
			{
				index = store.size();
				store.emplace_back(num);
			}
			else
			{
				// 이분탐색으로 store에서 같은 수, 없으면 그거 초과하는 제일 작은 수 찾아줌.
				index = lower_bound(store.begin(), store.end(), num) - store.begin();
				store[index] = num;
			}
			st.push({ num, index });
		}

		int maxIndex = store.size() - 1;
		cout << maxIndex + 1 << "\n";
		while (!st.empty())
		{
			auto temp = st.top();
			st.pop();
			if (temp.second == maxIndex)
			{
				store[maxIndex--] = temp.first;
			}
		}

		for (int& x : store) cout << x << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_14003::Solution();

	return 0;
}