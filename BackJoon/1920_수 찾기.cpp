// 20.08.23 Sun
// 1920: 수 찾기 https://www.acmicpc.net/problem/1920
// 이진탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int _lower_bound(int N, int key)
{
	int low = 0;
	int top = N-1;
	int middle;

	while (low <= top)
	{
		middle = (low + top) / 2;

		if (v[middle] == key) return 1;
		else if (v[middle] > key)
		{
			top = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, temp;
	cin >> a;

	for (int i = 0; i < a; ++i)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cin >> b;
	for (int i = 0; i < b; ++i)
	{
		cin >> temp;

		// 방법1: 이진탐색 직접만듦.
		cout << _lower_bound(v.size(), temp) << "\n";

		// 방법2: stl사용.
		//auto it = lower_bound(v.begin(), v.end(), temp);
		//if (*it != temp) cout << "0\n";
		//else cout << "1\n";
	}
}