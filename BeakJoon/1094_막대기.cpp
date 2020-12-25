// 20.12.25. 금
// 1094: 막대기 https://www.acmicpc.net/problem/1094
// math

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int size = 64, x;
	vector<int> sticks = { 64 };
	
	cin >> x;

	while (1)
	{
		if (size == x) break;
		
		int temp = sticks.back() / 2;
		sticks.pop_back();
		sticks.push_back(temp);
		sticks.push_back(temp);

		if (size - sticks.back() >= x)
		{
			size -= sticks.back();
			sticks.pop_back();
		}
	}

	cout << sticks.size();

	return 0;
}