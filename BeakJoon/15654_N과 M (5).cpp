// 21.02.24. 수
// 15654: N과 M (5) https://www.acmicpc.net/problem/15654
// 백트래킹.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_15654
{
	int n, m;
	vector<int> v, nums;

	void MakeNums(int count)
	{
		if (count == m)
		{
			for (int x : nums) cout << x << " ";
			cout << "\n";
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			if (v[i] == -1) continue;
			nums.push_back(v[i]);
			v[i] = -1;
			MakeNums(count + 1);
			v[i] = nums.back();
			nums.pop_back();
		}
	}

	void Solution()
	{
		cin >> n >> m;
		v.assign(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		MakeNums(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_15654::Solution();

	return 0;
}