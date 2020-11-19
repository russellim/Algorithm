// 20.11.18. 수
// 6603: 로또 https://www.acmicpc.net/problem/6603
// 백트래킹
#include <iostream>
#include <vector>

using namespace std;

int k;
int choice[13];
vector<int> lotto;

void makeLotto(int count, int start)
{
	if (count == 6)
	{
		for (int x : lotto)
			cout << x << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < k; ++i)
	{
		lotto.push_back(choice[i]);
		makeLotto(count + 1, i + 1);
		lotto.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	while (1)
	{
		cin >> k;
		if (k == 0) break;

		lotto.clear();

		for (int i = 0; i < k; ++i)
			cin >> choice[i];

		for (int i = 0; i <= k - 6; ++i)
		{
			lotto.push_back(choice[i]);
			makeLotto(1, i + 1);
			lotto.pop_back();
		}
		cout << "\n";
	}

	return 0;
}