// 21.02.17. 수
// 1786: 찾기 https://www.acmicpc.net/problem/1786
// KMP 알고리즘
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace BOJ_1786
{
	// SetPi(), Solution()의 level : 검사 완료된 단계.
	string T, P;
	int count;
	vector<int> indexes;

	// P에서 반복되는 구간 찾기.
	void SetPi(vector<int>& pi)
	{
		int size = pi.size();
		int level = 0;
		for (int i = 1; i < size; ++i)
		{
			while (level > 0 && P[i] != P[level])
			{
				level = pi[level - 1];
			}
			if (P[i] == P[level])
			{
				pi[i] = ++level;
			}
		}
	}

	void Solution()
	{
		int Tsize = T.size(), Psize = P.size();
		int level = 0;
		vector<int>pi(Psize, 0);
		SetPi(pi);
		// pi : P에 반복되는 구간이 있으면 T에서 달라도 P 중간부터 다시 검사할 수 있음.
		// 예> ABCDABD -> 0000120 : P[0] == P[4](A). T[..] != P[5]일때, pi[5-1] = 1 -> P[1](B)부터 검사(level은 1).
		//							P[1] == P[5](B). T[..] != P[6]일때, pi[6-1] = 2 -> P[2](C)부터 검사(level은 2).
		for (auto x : pi) cout << x;
		cout << endl;

		for (int i = 0; i < Tsize; ++i)
		{
			while (level > 0 && T[i] != P[level])
			{
				level = pi[level - 1];
			}
			if (T[i] == P[level])
			{
				if (level == Psize - 1) // P 탐색 끝까지 완료.
				{
					cout << level + 1;
					indexes.push_back(i - Psize + 2);
					count++;
					level = pi[level];
				}
				else
				{
					++level;
					cout << level;
				}
			}
			else cout << ".";
		}
		cout << endl;
	}

	void Input()
	{
		getline(cin, T);
		getline(cin, P);
	}

	void Output()
	{
		cout << count << "\n";
		for (int x : indexes) cout << x << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1786::Input();
	BOJ_1786::Solution();
	BOJ_1786::Output();

	return 0;
}