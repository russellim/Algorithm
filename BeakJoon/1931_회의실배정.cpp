// 20.09.28 월
// 1931: 회의실배정 https://www.acmicpc.net/problem/1931
// Sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

// 끝나는 시간 우선으로 오름차순.
// 끝나는 시간이 같으면 시작 시간 오름차순.
bool compare(p a, p b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n;
	cin >> n;

	int endtime = 0, count = 0;
	vector<p> vec(n);

	int temp1, temp2;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp1 >> temp2;
		vec[i] = make_pair(temp1, temp2);
	}

	sort(vec.begin(), vec.end(), compare);

	//for (int i = 0; i < n; ++i)
	//{
	//	cout << vec[i].first << " " << vec[i].second << endl;
	//}

	for (int i = 0; i < n; ++i)
	{
		if (vec[i].first >= endtime)
		{
			count++;
			endtime = vec[i].second;
		}
	}

	cout << count;

	return 0;
}