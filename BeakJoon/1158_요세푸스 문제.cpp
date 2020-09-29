// 20.09.29 화
// 1158: 요세푸스 문제 https://www.acmicpc.net/problem/1158
// 
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = i + 1;
	}

	int jump = k - 1;
	cout << "<";
	while (1)
	{
		cout << v[jump];
		v.erase(v.begin() + jump);
		if (v.empty()) break;
		cout << ", ";
 		jump--;
		jump += k;
		if (jump >= v.size()) jump %= v.size();
	}
	cout << ">";

	return 0;
}