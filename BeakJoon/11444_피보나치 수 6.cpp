// 21.04.20. 화
// 11444: 피보나치 수 6 https://www.acmicpc.net/problem/11444
// 분할정복 거듭제곱.

// 거듭제곱으로 피보나치 구하기.
// {{f^n+1, f^n}, {f^n, f^n-1}} = {{1, 1}, {1, 0}}^n.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace BOJ_11444
{
	typedef long long LL;
	typedef vector<vector<LL> > Matrix;
	constexpr int div = 1000000007;

	string MakeBinary(LL n)
	{
		string bin;
		while (n != 0)
		{
			bin += to_string(n % 2);
			n /= 2;
		}
		return bin;
	}

	void MultiMatrix(Matrix& a, Matrix& b)
	{
		int size = a.size();
		Matrix res(size, vector<LL>(size, 0));
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				for (int k = 0; k < size; ++k)
				{
					res[i][j] += a[i][k] * b[k][j];
				}
				res[i][j] %= div;
			}
		}
		a = res;
	}

	void Solution()
	{
		LL n;
		cin >> n;

		if (n == 0)
		{
			cout << "0";
			return;
		}

		string bin = MakeBinary(n - 1);
		Matrix m = { {1, 1}, {1, 0} };
		auto fm = m;

		for (int i = bin.size() - 2; i >= 0; --i)
		{
			if (bin[i] == '0')
			{
				MultiMatrix(m, m);
			}
			else
			{
				MultiMatrix(m, m);
				MultiMatrix(m, fm);
			}
		}

		cout << m[0][0];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_11444::Solution();

	return 0;
}