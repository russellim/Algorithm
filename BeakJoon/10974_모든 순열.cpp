// 21.06.12. 토
// 10974: 모든 순열 https://www.acmicpc.net/problem/10974
// 백트래킹.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_10974
{
	int n;
	vector<int> arr;
	vector<bool> visit;

	void MakeArray(int count)
	{
		if (count == n)
		{
			for (int& x : arr) cout << x << " ";
			cout << "\n";
			return;
		}

		for (int i = 1; i <= n; ++i)
		{
			if (visit[i]) continue;

			arr.emplace_back(i);
			visit[i] = true;
			MakeArray(count + 1);
			arr.pop_back();
			visit[i] = false;
		}
	}

	void Solution()
	{
		cin >> n;
		visit.assign(n + 1, false);

		MakeArray(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_10974::Solution();

	return 0;
}