// 20.09.24 목
// 10815: 숫자 카드 https://www.acmicpc.net/problem/10815
// Sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, m;
	cin >> n;
	vector<int> sarr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> sarr[i];
	}
	sort(sarr.begin(), sarr.end());

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int temp;
		cin >> temp;

		int start = 0, end = n - 1;
		bool findnum = false;

		while (start <= end)
		{
			int middle = (start + end) / 2;
			//cout << "m: " << sarr[middle] << endl;
			if (sarr[middle] == temp)
			{
				findnum = true;
				cout << "1 ";
				break;
			}

			if (temp > sarr[middle])
			{
				start = middle + 1;
			}
			else
			{
				end = middle - 1;
			}
		}

		if (!findnum)
		{
			cout << "0 ";
		}
	}

	return 0;
}