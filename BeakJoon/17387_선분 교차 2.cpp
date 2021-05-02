// 21.05.01. 토
// 17387: 선분 교차 2 https://www.acmicpc.net/problem/17387
// math(vector).
#include <iostream>
#include <algorithm>
using namespace std;

namespace BOJ_17387
{
	typedef long long LL;
	struct Dot
	{
		LL x, y;
		bool operator==(Dot& a)
		{
			return ((x == a.x) && (y == a.y));
		}
	};
	struct Line { Dot d1, d2; };

	int CounterClockwise(Dot& a, Dot& b, Dot& c)
	{
		// 1. 점 2개 -> 벡터 공식: v(d1->d2) = (d2.x - d1.x, d2.y - d1.y)

		// 2. 외적 공식(z=0) -> v1.x * v2.y - v1.y * v2.x
		//					 => v(a-b).x * v(a-c).y - v(a-b).y * v(a-c).x

		// 3. 두 점의 외적: +(반시계방향), 0(평행), -(시계방향).

		LL crossProduct = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

		if (crossProduct > 0) return 1;
		else if (crossProduct < 0) return -1;
		else return 0;
	}

	bool cmpDot(Dot& left, Dot& right)
	{
		if (left.x == right.x) return left.y < right.y;
		else return left.x < right.x;
	}

	bool IsCross(Line& L1, Line& L2)
	{
		if (L1.d1 == L2.d1 || L1.d1 == L2.d2 || L1.d2 == L2.d1 || L1.d2 == L2.d2) return true;

		int ccw1 = CounterClockwise(L1.d1, L1.d2, L2.d1) * CounterClockwise(L1.d1, L1.d2, L2.d2);
		int ccw2 = CounterClockwise(L2.d1, L2.d2, L1.d1) * CounterClockwise(L2.d1, L2.d2, L1.d2);

		if (ccw1 == 0 && ccw2 == 0) // 일직선 상에 있는 L1, L2.
		{
			// d1 < d2 로 순서 맞추기.
			if (cmpDot(L1.d2, L1.d1)) swap(L1.d1, L1.d2);
			if (cmpDot(L2.d2, L2.d1)) swap(L2.d1, L2.d2);

			return (cmpDot(L2.d1, L1.d2) && cmpDot(L1.d1, L2.d2));
		}
		else return (ccw1 <= 0 && ccw2 <= 0);
	}

	void Solution()
	{
		Line L1, L2;
		cin >> L1.d1.x >> L1.d1.y >>
			L1.d2.x >> L1.d2.y >>
			L2.d1.x >> L2.d1.y >>
			L2.d2.x >> L2.d2.y;

		// output.
		cout << (IsCross(L1, L2) ? "1" : "0");
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_17387::Solution();

	return 0;
}