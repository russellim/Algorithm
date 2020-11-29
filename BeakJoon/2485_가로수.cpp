// 20.11.28. 토
// 2485: 가로수 https://www.acmicpc.net/problem/2485
// Math, 유클리드 호제법
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최대공약수 구하기.
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, start = 1e9, mindist;
	cin >> n;
	vector<int> trees(n);
	vector<int> dists(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> trees[i];
		start = min(start, trees[i]);
	}

	// 모든 가로수의 첫번째 가로수와의 거리 구하기.
	for (int i = 0; i < n; ++i)
	{
		if (start != trees[i])
			dists[i] = trees[i] - start;
	}
	sort(dists.begin(), dists.end());

	// 거리들의 최대공약수 구하기.
	int g = gcd(dists[1], dists[2]);
	for (int i = 3; i < dists.size(); ++i)
	{
		g = gcd(g, dists[i]);
	}

	// 있어야하는 가로수 - 이미 있는 가로수.
	cout << (dists[dists.size() - 1] / g) + 1 - dists.size();

	return 0;
}