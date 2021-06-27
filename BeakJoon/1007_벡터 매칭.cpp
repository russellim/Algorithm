// 21.06.26. 토
// 1007: 벡터 매칭 https://www.acmicpc.net/problem/1007
// math(벡터), next_permutation.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

namespace BOJ_1007
{
	struct Coord { int x, y; };

	double GetDistance(double tx, double ty)
	{
		return sqrt(tx * tx + ty * ty);
	}

	void Solution()
	{
		// 소수점 12자리 고정.
		cout << fixed;
		cout.precision(12);
		
		int t;
		cin >> t;

		while (t--)
		{
			int n;
			double answer = LLONG_MAX;
			cin >> n;
			vector<Coord> arr(n);
			vector<int> mul(n);

			// 점A, 점B가 있을때 A->B 벡터.
			// = B - A (+하나 -하나).
			// 반은 +, 반은 - 해주고 조합별로 계산해줌.
			for (int i = 0; i < n; ++i)
			{
				cin >> arr[i].x >> arr[i].y;
			}
			for (int i = 0; i < n; ++i)
			{
				if (i < n / 2) mul[i] = -1;
				else mul[i] = 1;
			}

			do
			{
				double tx = 0.0, ty = 0.0;
				for (int i = 0; i < n; ++i)
				{
					tx += (arr[i].x * mul[i]);
					ty += (arr[i].y * mul[i]);
				}
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
