// 20.09.22 화
// 1002: 터렛 https://www.acmicpc.net/problem/1002
// math

// 두 원의 위치 관계, 내접, 외접 / """교점"""의 개수.

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

		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));	// 두점의 거리.
		// 내접, 외접 구할때 준비.
		int minus = abs(r1 - r2);
		int plus = r1 + r2;

		// 두 점이 겹침(동심원).
		if (distance == 0.0)
		{
			// 반지름도 같네 = 같은 위치, 같은 원, 전부 다 교점
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
			// 두 원이 두 점에서 만난다.
			if (minus < distance && plus > distance)
			{
				res = 2;
			}
			// 내접하거나, 외접하거나 = 한 점에서 만난다.
			else if (minus == distance || plus == distance)
			{
				res = 1;
			}
			// 안만나는 갑다.
			else
			{
				res = 0;
			}
		}
		cout << res << "\n";
	}

	return 0;
}