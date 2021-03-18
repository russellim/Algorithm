// 21.03.18. 목
// DFS/BFS_타겟 넘버 https://www.acmicpc.net/problem/43165
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ns;
int answer, nSize, t;

void dfs(int index, int sum)
{
	if (index == nSize)
	{
		if (sum == t)answer++;
		return;
	}

	int a = sum + ns[index];
	int b = sum - ns[index];
	dfs(index + 1, a);
	dfs(index + 1, b);
}

int solution(vector<int> numbers, int target) {
	answer = 0;
	t = target;
	nSize = numbers.size();
	ns = numbers;
	dfs(0, 0);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution({ 1,1,1,1,1 }, 3); // 5.

	return 0;
}