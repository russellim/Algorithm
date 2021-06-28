// 21.06.28. 월
// 1202: 보석 도둑 https://www.acmicpc.net/problem/1202
// multiset, lower_bound.

// 가방무게 컨테이너를 vector로 하면 시간초과.
// 거 이분탐색이면 빠를줄알았는데 아니다. 삭제 때문일까?
// 
// 해결:
// vector -> multiset으로 바꾼 이유: https://stackoverflow.com/questions/18135394/stdmutiset-vs-stdvector-to-read-and-write-sorted-strings-to-a-file
// 요약하자면 단순삽입속도나 메모리에서는 vector가 더 좋은데, 데이터를 동적으로(삽입삭제에 따른 위치 변동같은..) 사용할 일이 많으면 multiset.
// (그냥 set는 중복된 데이터 허용x).
// lower_bound 멤버함수도 있어서 굿.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

namespace BOJ_1202
{
	struct Jewel { long long weight, value; };

	void Solution()
	{
		// input. 
		int n, k;
		cin >> n >> k;
		vector<Jewel> jewel(n);
		multiset<int> bag; // 알아서 오름차순 정렬이 된다.
		for (int i = 0; i < n; ++i)
		{
			cin >> jewel[i].weight >> jewel[i].value;
		}
		for (int i = 0; i < k; ++i)
		{
			int b;
			cin >> b;
			bag.insert(b);
		}

		// 가치 큰 순서로 sort (같으면 무게 적은 순).
		sort(jewel.begin(), jewel.end(), [](Jewel& a, Jewel& b) -> bool 
			{ 
				if (a.value == b.value) return a.weight < b.weight;
				return a.value > b.value;
			});


		// solution.
		long long answer = 0;

		// 보석을 가방에 매치.
		for (int i = 0; i < n; ++i)
		{
			if (bag.empty()) break; // 가방 다 차면 끝.
			auto it = bag.lower_bound(jewel[i].weight); // 일치하거나, 더 큰 최초의 가방 찾기.
			if (it == bag.end()) continue; // 맞는 무게 없음.
			answer += jewel[i].value;
			bag.erase(it);
		}


		// output.
		cout << answer;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_1202::Solution();
	return 0;
}

// vector의 흔적.
//int get_lower_bound(vector<int>& arr, int key)
//{
//	int arrSize = arr.size();
//	int start = 0, end = arrSize;
//	int mid;
//	while (start < end)
//	{
//		mid = (start + end) / 2;
//		if (arr[mid] < key) start = mid + 1;
//		else end = mid;
//	}
//	return start;
//}
