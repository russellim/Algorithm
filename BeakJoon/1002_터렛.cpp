// 20.09.22 화
// 1002: 터렛 https://www.acmicpc.net/problem/1002
// math
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		t--;

		int x1, y1, r1, x2, y2, r2, res;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		int minus = abs(r1 - r2);
		int plus = r1 + r2;

		if (distance == 0.0)
		{
			if (r1 == r2)
			{
				res = -1;
			}
			else
			{
				res = 0;
			}

		}
		else
		{
			if (minus < distance && plus > distance)
			{
				res = 2;
			}
			else if (minus == distance || plus == distance)
			{
				res = 1;
			}
			else
			{
				res = 0;
			}
		}
		cout << res << "\n";
	}

	return 0;
}