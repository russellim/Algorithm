// 20.11.14. 토
// 15810: 풍선 공장 https://www.acmicpc.net/problem/15810
// BS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	long long low = 1LL;
	long long high = 1000000000001LL;
	//long long high = 31LL;
	
	while (low + 1 < high)
	{
		long long mid = (low + high) / 2;
		long long count = 0;
		for (int i = 0; i < n; ++i)
		{
			count += mid / v[i];
		}
		//cout << " low: " << low  << " high: " << high << " mid: " << mid << " count: " << count << endl;
		if (count >= m) high = mid;
		else low = mid;
	}
	cout << high;

	return 0;
}