// 20.10.03. 토
// 10953: A+B - 6 https://www.acmicpc.net/problem/10953
// string
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int t;
	cin >> t;

	string str;
	while (t--)
	{
		cin >> str;
		int cut_temp = str.find(',');
		cout << atoi(str.substr(0, cut_temp).c_str())
			+ atoi(str.substr(cut_temp + 1).c_str()) << "\n";
	}

	return 0;
}