// 20.09.25 금
// 1181: 단어 정렬 https://www.acmicpc.net/problem/1181
// String, Sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SizeSort(const string& s1, const string& s2)
{
	if (s1.size() == s2.size()) return s1 < s2;
	return s1.size() < s2.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;
	vector<string> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());
	// 중복 원소들 제거.
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	sort(vec.begin(), vec.end(), SizeSort);

	for (auto& x : vec)
	{
		cout << x << "\n";
	}

	return 0;
}