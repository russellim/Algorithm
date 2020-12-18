// 20.12.18. 금
// 11050: 이항 계수 1 https://www.acmicpc.net/problem/11050
// Math: 이항정리, 파스칼의 삼각형.
#include <iostream>

using namespace std;

int bino(int n, int k)
{
	if (k == 0 || k == n) return 1;
	return bino(n - 1, k - 1) + bino(n - 1, k);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, k;
	cin >> n >> k;
	cout << bino(n, k);

	return 0;
}

/*
### 이항 계수 : 이항식을 이항 정리로 전개 했을 때 각 항의 계수, 주어진 크기의 (순서 없는) 조합의 가짓수.
### 파스칼의 삼각형 : 이항계수를 삼각형 모양의 기하학적 형태로 배열한 것.
	  1
	1   1
   1  2  1
  1 3   3 1
 1 4  6  4 1
1 5 10 10 5 1

(5, 0) => 1
(5, 1) => 5
(5, 2) => 10
...

### 이항계수 점화식
bino(n - 1, k - 1) + bino(n - 1, k) if, 0 < k < n
ex) (5, 2) = (4, 1) + (4, 2)

파스칼 삼각형을 이렇게 봅시다.

1
1  1
1  3  3  1
1  4  6  4  1
1  5 10 10  5  1

아시겠어요?

*/