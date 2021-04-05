// 21.04.05. 월
// 12852: 1로 만들기 2 https://www.acmicpc.net/problem/12852
// 백트래킹.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_12852
{
	vector<int> tempv, answer;
	int answerCount = 1e9;

	void MakeOne(int n, int count)
	{
		if (count >= answerCount) return;
		if (n == 1)
		{
			if (answerCount > count)
			{
				answerCount = count;
				answer = tempv;
			}
			return;
		}

		tempv.push_back(n);
		if (n % 3 == 0) MakeOne(n / 3, count + 1);
		if (n % 2 == 0) MakeOne(n / 2, count + 1);
		MakeOne(n - 1, count + 1);
		tempv.pop_back();
	}

	void Solution()
	{
		int n;
		cin >> n;
		MakeOne(n, 0);

		cout << answerCount << "\n";
		for (int x : answer) cout << x << " ";
		cout << "1";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_12852::Solution();

	return 0;
}