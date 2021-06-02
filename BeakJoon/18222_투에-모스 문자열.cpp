// 21.06.01. 화
// 18222: 투에-모스 문자열 https://www.acmicpc.net/problem/18222
// 시프트연산, 이분탐색?.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_18222
{
	typedef long long LL;
	constexpr int MAX = 62;

	int Thue_Morse_Sequence(LL index)
	{
		if (index == 0) return 0;
		for (int i = 0; i <= MAX; ++i)
		{
			LL data = (LL)(1) << i;	// 32비트 넘어가는 시프트 연산하는 법.
			if (index < data)
			{
				LL prev = (LL)(1) << (i - 1);
				return 1 - Thue_Morse_Sequence(index - prev);
			}
		}
	}

	void Solution()
	{
		LL n;
		cin >> n;

		cout << Thue_Morse_Sequence(n - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_18222::Solution();

	return 0;
}