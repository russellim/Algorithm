// 21.04.03. 토
// 2096: 내려가기 https://www.acmicpc.net/problem/2096
// DP. 메모리 아끼기 포인트.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_2096
{
	constexpr int MAX = 1e9;

	void Solution()
	{
		int n, score;
		cin >> n;
		// [0]  0   0   0   MAX MAX MAX	-> 비교 기본값.
		// [1] old old old  old old old	-> 이전 계산값.
		// [2] new new new  new new new -> 새 계산값.
		vector<vector<int> > maxScore(3, vector<int>(3, 0));
		vector<vector<int> > minScore(3, vector<int>(3, MAX));

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> score;
				if (i == 0)
				{
					maxScore[2][j] = minScore[2][j] = score;
				}
				else
				{
					for (int k = j - 1; k <= j + 1; ++k)
					{
						if (k < 0 || k >= 3) continue;
						maxScore[2][j] = max(maxScore[2][j], maxScore[1][k] + score);
						minScore[2][j] = min(minScore[2][j], minScore[1][k] + score);
					}
				}
			}
			if (i != n - 1)
			{
				// 다음 비교를 위해 교체.
				maxScore[1] = maxScore[2];
				minScore[1] = minScore[2];
				maxScore[2] = maxScore[0];
				minScore[2] = minScore[0];
			}
		}

		cout << *max_element(maxScore[2].begin(), maxScore[2].end()) << " "
			<< *min_element(minScore[2].begin(), minScore[2].end());
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2096::Solution();

	return 0;
}