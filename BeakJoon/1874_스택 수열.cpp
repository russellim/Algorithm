// 20.10.07. 수
// 1874: 스택 수열 https://www.acmicpc.net/problem/1874
// Stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> numbers(n); // 숫자들 저장.
	vector<char> pp;		// +, - 결과 저장. 
							// (왜냐! No를 출력하는 경우때문에 저장해놓고 나중에 출력해야됨!)
	stack<int> st;			// 1~N 스택.
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
	}

	int pivot = 0;
	// 1~N 푸시 다할때 까지.
	for (int i = 1; i <= n; ++i)
	{
		while (!st.empty() && numbers[pivot] == st.top())
		{
			st.pop();
			pivot++;
			pp.push_back('-');
			//cout << "-\n";
		}
		st.push(i);
		pp.push_back('+');
		//cout << "+\n";
	}
	// 푸시 끝나고 나머지 pop.
	while (!st.empty() && numbers[pivot] == st.top())
	{
		st.pop();
		pivot++;
		pp.push_back('-');
		//cout << "-\n";
	}

	if (!st.empty())
	{
		// pop이 다 안되는 수열이다.
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < pp.size(); ++i)
		{
			cout << pp[i] << "\n";
		}
	}

	return 0;
}