// 21.04.25. 일
// 같은 숫자는 싫어 https://programmers.co.kr/learn/courses/30/lessons/12906
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	answer.push_back(arr[0]);
	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i - 1] == arr[i]) continue;
		answer.push_back(arr[i]);
	}

	return answer;
}