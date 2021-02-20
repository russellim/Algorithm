// 21.02.20. 토
// 18870: 좌표 압축 https://www.acmicpc.net/problem/18870
// 정렬.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_18870
{
	bool cmp(pair<int, int>& a, pair<int, int>& b)
	{
		return a.second < b.second;
	}

	void SortCoordinate(int size, vector<pair<int, int> >& coords)
	{
		vector<int> answer(size);
		sort(coords.begin(), coords.end(), cmp);
		int count = 0;
		answer[coords[0].first] = count;
		for (int i = 1; i < size; ++i)
		{
			if (coords[i - 1].second != coords[i].second) count++;
			answer[coords[i].first] = count;
		}

		// output.
		for (int x : answer) cout << x << " ";
	}

	void Solution()
	{
		int n;
		cin >> n;
		vector<pair<int, int> > coords(n);
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			coords[i] = { i, x };
		}
		SortCoordinate(n, coords);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_18870::Solution();

	return 0;
}