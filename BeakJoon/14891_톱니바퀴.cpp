// 21.06.08. 화
// 14891: 톱니바퀴 https://www.acmicpc.net/problem/14891
// 구현.
#include <iostream>
#include <vector>
using namespace std;

namespace BOJ_14891
{
	constexpr int GEAR_COUNT = 4;
	constexpr int TOOTH_COUNT = 8;

	// 맞닿는 톱니 인덱스.
	constexpr int TOUCH_LEFT_INDEX = 6;
	constexpr int TOUCH_RIGHT_INDEX = 2;

	constexpr int CLOCKWISE = 1;

	vector<string> gears(GEAR_COUNT);
	vector<bool> visit;

	bool IsRange(int num)
	{
		return num >= 0 && num < GEAR_COUNT;
	}

	int CharToInt(char c)
	{
		return c - '0';
	}

	// 기어 돌리기.
	void TurnGear(string& str, int dir)
	{
		if(dir == CLOCKWISE) 
			str = str[TOOTH_COUNT - 1] + str.substr(0, TOOTH_COUNT - 1);
		else 
			str = str.substr(1, TOOTH_COUNT - 1) + str[0];
	}

	// 기어 체크.
	void CheckGear(int num, int dir)
	{
		visit[num] = true;
		char left = gears[num][TOUCH_LEFT_INDEX];
		char right = gears[num][TOUCH_RIGHT_INDEX];

		// 왼쪽 체크.
		if (IsRange(num - 1) && !visit[num - 1])
		{
			if (left != gears[num - 1][TOUCH_RIGHT_INDEX])
			{
				CheckGear(num - 1, dir * -1);
			}
		}

		// 오른쪽 체크.
		if (IsRange(num + 1) && !visit[num + 1])
		{
			if (right != gears[num + 1][TOUCH_LEFT_INDEX])
			{
				CheckGear(num + 1, dir * -1);
			}
		}

		TurnGear(gears[num], dir);
	}

	void Solution()
	{
		int answer = 0;
		int k, num, dir;

		for (string& s : gears) cin >> s;
		cin >> k;

		while (k--)
		{
			cin >> num >> dir;
			visit.assign(GEAR_COUNT, false); // 방문 초기화.

			CheckGear(num - 1, dir);
		}

		answer = CharToInt(gears[0][0]) * 1
			+ CharToInt(gears[1][0]) * 2
			+ CharToInt(gears[2][0]) * 4
			+ CharToInt(gears[3][0]) * 8;

		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_14891::Solution();

	return 0;
}