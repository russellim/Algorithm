// 20.12.02. 수
// 15649: N과 M (1) https://www.acmicpc.net/problem/15649
// 백트래킹.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v, makev;

void MakeNums(int count)
{
	if (count == m)
	{
		for (int x : makev) cout << x << " ";
		cout << "\n";
		return;
	}

	vector<int> copyv;

	for (int i = 0; i < v.size(); ++i)
	{
		makev.push_back(v[i]);
		copyv = v;
		v.erase(v.begin() + i);
		MakeNums(count + 1);
		v = copyv;
		makev.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) v.push_back(i);

	MakeNums(0);

	return 0;
}