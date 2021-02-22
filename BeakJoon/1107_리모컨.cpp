// 21.02.22. 월
// 1107: 리모컨 https://www.acmicpc.net/problem/1107
// 브루트포스.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

namespace BOJ_1107
{
	int n, answer;
	vector<bool> error;

	int Minus()
	{
		int newN = n;

		while (1)
		{
			if (newN == -1) break;
			string str = to_string(newN);
			for (int i = 0; i < str.size(); ++i)
			{
				if (!error[str[i] - '0']) break;
				if (i == str.size() - 1)
				{
					return str.size() + n - newN;
				}
			}
			newN--;
			if (answer < str.size() + n - newN)
				return 123456789;
		}
		return 123456789;
	}

	int Plus()
	{
		int newN = n;

		while (1)
		{
			string str = to_string(newN);
			for (int i = 0; i < str.size(); ++i)
			{
				if (!error[str[i] - '0']) break;
				if (i == str.size() - 1)
				{
					return (int)str.size() + newN - n;
				}
			}
			newN++;
			if (answer < str.size() + newN - n)
				return 123456789;
		}
		return 123456789;
	}

	void Solution()
	{
		// input.
		int m;
		cin >> n >> m;
		if (n == 100)
		{
			cout << "0";
			return;
		}
		error.assign(10, true);
		for (int i = 0; i < m; ++i)
		{
			int index;
			cin >> index;
			error[index] = false;
		}

		answer = abs(100 - n);	// 1. 100번에서 +-로 이동.
		answer = min(Minus(), answer);  // 2. 아래채널로.
		// output.
		cout << min(Plus(), answer);	// 3. 위채널로.
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1107::Solution();

	return 0;
}