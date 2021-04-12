// 21.04.12. 월
// 10830: 행렬 제곱 https://www.acmicpc.net/problem/10830
// Math.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace BOJ_10830
{
	void Square(int n, vector<vector<int> >& answer, vector<vector<int> >& matrix)
	{
		vector<vector<int> > res(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					res[i][j] += (answer[i][k] * matrix[k][j]) % 1000;
				}
				res[i][j] %= 1000;
			}
		}
		answer = res;
	}

	string MakeBinary(long long b)
	{
		string res;
		while (b != 0)
		{
			res += to_string(b % 2);
			b /= 2;
		}
		return res;
	}

	void Solution()
	{
		int n;
		long long b;
		cin >> n >> b;
		vector<vector<int> > matrix(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> matrix[i][j];
			}
		}

		auto answer = matrix;
		auto binary = MakeBinary(b);
		for (int i = binary.size() - 2; i >= 0; --i)
		{
			if (binary[i] == '1')
			{
				Square(n, answer, answer);
				Square(n, answer, matrix);
			}
			else
			{
				Square(n, answer, answer);
			}
		}

		// output;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << answer[i][j] % 1000 << " ";
			}
			cout << "\n";
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_10830::Solution();

	return 0;
}