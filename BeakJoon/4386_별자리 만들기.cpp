// 21.04.18. 일
// 4386: 별자리 만들기 https://www.acmicpc.net/problem/4386
// 크루스칼 알고리즘, math(거리 구하는 식이 틀렸었음)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

namespace BOJ_4386
{
	struct Coord { double x, y; };
	struct Conn { double dist; int from, to; };
	vector<vector<pair<double, int> > > conn;
	vector<int> parent;

	double GetDistance(Coord& a, Coord& b)
	{
		double dx = (a.x - b.x) * (a.x - b.x);
		double dy = (a.y - b.y) * (a.y - b.y);
		return sqrt(dx + dy);
	}

	int GetParent(int child)
	{
		if (child == parent[child]) return child;
		return parent[child] = GetParent(parent[child]);
	}

	bool Merge(int from, int to)
	{
		from = GetParent(from);
		to = GetParent(to);

		if (from == to) return false;	// 사이클 체크.

		// 사이클 아니여서 합침.
		if (from > to) parent[from] = to;
		else parent[to] = from;
		return true;
	}

	double Cruskal(int n, vector<Conn>& conn)
	{
		double sum = 0.0;
		for (int i = 0; i < conn.size(); ++i)
		{
			if (Merge(conn[i].from, conn[i].to))
				sum += conn[i].dist;
		}

		return sum;
	}

	void Solution()
	{
		int n;
		cin >> n;
		vector<Coord> stars(n);
		parent.assign(n, 0);
		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
			cin >> stars[i].x >> stars[i].y;
		}

		vector<Conn> conn;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				conn.push_back({ GetDistance(stars[i], stars[j]), i, j });
			}
		}

		sort(conn.begin(), conn.end(), [](Conn& a, Conn& b) { return a.dist < b.dist; });
		double answer = Cruskal(n, conn);

		// output.
		cout << fixed;
		cout.precision(2);
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_4386::Solution();

	return 0;
}