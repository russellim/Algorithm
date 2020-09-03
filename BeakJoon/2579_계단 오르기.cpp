// 20.09.03 목
// 2579: 계단 오르기 https://www.acmicpc.net/problem/2579
// DP
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int a;
	cin >> a;
	int* stair = new int[a];
	for (int i = 0; i < a; ++i)
	{
		cin >> stair[i];
	}

	// jump[a][2] => [i][0]은 두칸 뛰어서 온거, [i][1]은 한 칸 뛰어서 온거.
	int jump[301][2];
	jump[0][0] = stair[0];
	jump[1][0] = stair[1];
	jump[1][1] = stair[1] + stair[0];

	for (int i = 2; i < a; ++i)
	{
		// 두 칸 뛰어오는건 이전전에 한 칸 뛰었든, 두 칸 뛰었든 상관없이 둘 중 큰값에 더함.
		jump[i][0] = max(jump[i - 2][0] + stair[i],
			jump[i - 2][1] + stair[i]);

		// 한 칸 뛰어오는건 이전에 두 칸 뛰었을 경우만 가능.
		jump[i][1] = jump[i - 1][0] + stair[i];
	}

	// 확인 하쇼다.
	//cout << endl;
	//for (int i = 0; i < a; ++i)
	//{
	//	cout << jump[i][0] << endl;
	//	cout << jump[i][1] << endl;
	//	cout << endl;
	//}

	cout << max(jump[a - 1][0], jump[a - 1][1]);

}