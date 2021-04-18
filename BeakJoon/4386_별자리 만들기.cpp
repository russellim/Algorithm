// 21.04.18. 일
// 4386: 별자리 만들기 https://www.acmicpc.net/problem/4386
// 크루스칼 알고리즘

// failed. 왜!??!
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
	bool check;

	double GetDistance(Coord& a, Coord& b)
	{
		return sqrt(abs(b.x - a.x)) + sqrt(abs(b.y - a.y));
	}

	int findParent(int child)
	{
		if (child == parent[child]) return child;
		return parent[child] = findParent(parent[child]);
	}

	void merge(int from, int to)
	{
		check = false;
		from = findParent(from);
		to = findParent(to);

		if (from == to) return;
		parent[from] = to;
		check = true;
	}

	double Cruskal(int n, vector<Conn>& conn)
	{
		double res = 0.0;
		for (int i = 0; i < conn.size(); ++i)
		{
			merge(conn[i].from, conn[i].to);
			if (check) res += conn[i].dist;
		}

		return res;
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
				auto temp = GetDistance(stars[i], stars[j]);
				conn.push_back({ temp, i, j });
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