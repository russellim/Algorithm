// 21.06.26. 토
// 1007: 벡터 매칭 https://www.acmicpc.net/problem/1007
// math(벡터), next_permutation.

// failed. 벡터공부 좀더 할것.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

namespace BOJ_1007
{
	struct Coord { int x, y; };
	double answer = LLONG_MAX;

	double GetDistance(double tx, double ty)
	{
		return sqrt(tx * tx + ty * ty);
	}

	void Solution()
	{
		cout << fixed;
		cout.precision(12);
		
		int t;
		cin >> t;

		while (t--)
		{
			int n;
			cin >> n;
			vector<Coord> arr(n);
			vector<int> mul(n);

			for (int i = 0; i < n; ++i)
			{
				cin >> arr[i].x >> arr[i].y;
			}
			for (int i = 0; i < n; ++i)
			{
				if (i < n / 2) mul[i] = -1;
				else mul[i] = 1;
			}

			double tx = 0.0, ty = 0.0;
			do
			{
				for (int i = 0; i < n; ++i)
				{
					cout << mul[i] << " ";
					tx += (arr[i].x * mul[i]);
					ty += (arr[i].y * mul[i]);
				}
				cout << tx << " " << ty << endl;
				answer = min(answer, GetDistance(tx, ty));

			} while (next_permutation(mul.begin(), mul.end()));

			cout << answer << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1007::Solution();

	return 0;
}