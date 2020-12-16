// 20.12.16. 수
// 2805: 나무 자르기 https://www.acmicpc.net/problem/2805
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long BinarySearch(vector<int>& trees, int x)
{
	long long answer = 0;
	for (int i = 0; i < trees.size(); ++i)
	{
		if (trees[i] - x > 0)
			answer += trees[i] - x;
	}
	return answer;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	vector<int> trees(n);

	for (int i = 0; i < n; ++i)
		cin >> trees[i];

	long long start = 0, end = 1000000000;
	while (start < end)
	{
		long long mid = (start + end + 1) / 2;
		if (BinarySearch(trees, mid) < m)
			end = mid - 1;
		else
			start = mid;
	}

	cout << start;

	return 0;
}