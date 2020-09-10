// 20.09.10 목
// 10989: 수 정렬하기 3 https://www.acmicpc.net/problem/10989
// 메모리에 주의해야하는 정렬.(8MB)

// sort()나 다른 정렬 로직을 사용하면(퀵소트도!) 메모리 초과.
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, temp;
	int count[10001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		count[temp]++;
	}

	for (int i = 0; i <= 10000; ++i)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; ++j)
			{
				cout << i << "\n";
			}
		}
	}
}