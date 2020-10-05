// 20.10.05. 월
// 10867: 중복 빼고 정렬하기 https://www.acmicpc.net/problem/10867
// vector
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	// unique 쓰기 전에 정렬을 잊지 맙시다.
	sort(vec.begin(), vec.end());

	// 유니크 원소들은 앞으로 옮겨지고 it는 그 다음 중복 원소를 가리킨다.
	auto it = unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());

	for (auto x : vec)
	{
		cout << x << " ";
	}

	return 0;
}