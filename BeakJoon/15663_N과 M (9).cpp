// 21.02.26. 금
// 15663: N과 M (9) https://www.acmicpc.net/problem/15663
// 백트래킹, vector unique.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ15663
{
	int n, m;
	vector<int> v, nums;
	vector<vector<int> > answer;

	void MakeNums(int count)
	{
		if (count == m)
		{
			answer.push_back(nums);
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
			cin >> v[i];
		sort(v.begin(), v.end());
		MakeNums(0);

		sort(answer.begin(), answer.end());
		answer.erase(unique(answer.begin(), answer.end()), answer.end());
		for (int i = 0; i < answer.size(); ++i)
		{
			for (int x : answer[i]) cout << x << " ";
			cout << "\n";
		}
	}
}

int main()
{
	BOJ15663::Solution();
}