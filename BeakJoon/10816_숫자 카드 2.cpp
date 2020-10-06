// 20.10.06. 화
// 10816: 숫자 카드 2 https://www.acmicpc.net/problem/10816
// Sort, Search
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	// 주석 코드보다 시간을 1/3 줄였습니당.
	int n, m, temp;
	cin >> n;
	vector<int> nrr(n);
	vector<int>::iterator lower, upper;
	for (int i = 0; i < n; ++i)
	{
		cin >> nrr[i];
	}
	// lower_ upper_bound 쓸때 정렬 필수.
	sort(nrr.begin(), nrr.end());

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		// 찾는 값의 첫번째 원소.
		lower = lower_bound(nrr.begin(), nrr.end(), temp);
		// 배열에 없으면 바로 0 출력.
		if (lower == nrr.end())
		{
			cout << "0 ";
			continue;
		}
		// 배열에 있으면
		// 찾는 값을 초과하는 가장 첫번째 원소.
		upper = upper_bound(nrr.begin(), nrr.end(), temp);

		// -nrr.begin()으로 인덱스끼리 빼주면 개수 짜잔.
		cout << (upper - nrr.begin()) - (lower - nrr.begin()) << " ";
	}


	// 처음 사용한 방법.
	// 시간초과는 아닌데 굉장히 오래걸리고 메모리 왕창.
	// 탐색(map.find())을 너어어어무 많이해.
	//int n, m, temp;
	//cin >> n;
	//map<int, int> cards;
	//for (int i = 0; i < n; ++i)
	//{
	//	cin >> temp;

	//	auto it = cards.find(temp);
	//	if (it == cards.end())
	//	{
	//		cards.insert({ temp, 1 });
	//	}
	//	else
	//	{
	//		it->second++;
	//	}
	//}

	//cin >> m;
	//for (int i = 0; i < m; ++i)
	//{
	//	cin >> temp;

	//	auto it = cards.find(temp);
	//	if (it == cards.end())
	//	{
	//		cout << "0 ";
	//		continue;
	//	}
	//	cout << it->second << " ";
	//}

	return 0;
}