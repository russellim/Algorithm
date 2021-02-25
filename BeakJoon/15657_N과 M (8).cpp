// 21.02.25. 목
// 15657: N과 M (8) https://www.acmicpc.net/problem/15657
// 백트래킹
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ15657
{
	int n, m;
	vector<int> v, nums;

	void MakeNums(int count, int start)
	{
		if (count == m)
		{
			for (int x : nums) cout << x << " ";
			cout << "\n";
			return;
		}
		for (int i = start; i < n; ++i)
		{
			nums.push_back(v[i]);
			MakeNums(count + 1, i);
			nums.pop_back();
		}
	}

	void Solution()
	{
		cin >> n >> m;
		v.assign(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());
		MakeNums(0, 0);
	}
}

int main()
{
	BOJ15657::Solution();
}