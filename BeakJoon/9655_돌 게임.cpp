﻿// 20.09.17 수
// 9655: 돌 게임 https://www.acmicpc.net/problem/9655
// DP
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;


	if (n % 2 == 0)
		cout << "CY";
	else
		cout << "SK";
}