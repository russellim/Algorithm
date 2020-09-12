#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> tobinary(int size, int n)
{
	vector<int> answer(size);
	for (int i = size - 1; i >= 0; --i)
	{
		answer[i] = n % 2;
		n /= 2;
	}

	//for (int i = 0; i < size; ++i)
	//{
	//	cout << answer[i];
	//}
	//cout << endl;
	return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; ++i)
	{
		vector<int> temp1, temp2;
		temp1 = tobinary(n, arr1[i]);
		temp2 = tobinary(n, arr2[i]);
		for (int j = 0; j < n; ++j)
		{
			if (temp1[j] == 1 || temp2[j] == 1) temp1[j] = 1;
			//cout << temp1[j] << " ";
		}
		//cout << endl;

		string strtemp;
		for (int j = 0; j < n; ++j)
		{
			if (temp1[j] == 1) strtemp += "#";
			else strtemp += " ";
		}
		answer.push_back(strtemp);
	}

	return answer;
}