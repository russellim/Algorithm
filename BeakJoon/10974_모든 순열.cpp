// 21.06.12. 토
// 10974: 모든 순열 https://www.acmicpc.net/problem/10974
// 백트래킹.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 210625 추가
// STL <algorithm> next_permutation (다음 순서 순열) 사용.
namespace BOJ_10974
{
	void Solution()
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			arr[i] = i + 1;
		}

		do
		{
			for (int& x : arr) cout << x << " ";
			cout << "\n";
		} while (next_permutation(arr.begin(), arr.end()));
	}
}

// 백트래킹 사용.
namespace BOJ_10974_lagacy
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