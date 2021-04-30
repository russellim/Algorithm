// 21.04.29. 목
// 2448: 별 찍기 - 11 https://www.acmicpc.net/problem/2448
// 재귀.

// 별모양 잘못해서 틀린거였음 머쓱ㅎㅎ;.
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

namespace BOJ_2448
{
	void ExtendStar(vector<string>& tri, int& h, int& w, int& emptyCount)
	{
		auto temp = tri;
		h = h * 2;
		w = w * 2 + 1;
		tri.assign(h, " ");
		string emptyStr(emptyCount, ' ');

		for (int i = 0; i < temp.size(); ++i)
		{
			tri[i] = emptyStr + temp[i] + emptyStr;
		}
		for (int i = 0; i < temp.size(); ++i)
		{
			tri[h / 2 + i] = temp[i] + ' ' + temp[i];
		}
		emptyCount *= 2;
	}

	void Solution()
	{
		int n;
		cin >> n;
		int h = 3, w = 5, emptyCount = 3;
		vector<string> tri(h);
		tri[0] = { "  *  " };
		tri[1] = { " * * " };
		tri[2] = { "*****" };

		for (int k = 0; n > 3 * pow(2, k); ++k)
		{
			ExtendStar(tri, h, w, emptyCount);
		}

		for (int i = 0; i < n; ++i)
		{
			cout << tri[i] << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2448::Solution();

	return 0;
}
