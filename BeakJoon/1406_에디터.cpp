// 20.09.25 금
// 1406: 에디터 https://www.acmicpc.net/problem/1406
// List

// Stack으로 풀어도 빠르고 용량도 저렴쓰.
#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	string str;
	int m;
	cin >> str;
	cin >> m;

	list<char> li(str.begin(), str.end());
	auto cursor = li.end();

	while (m--)
	{
		char cmd;
		cin >> cmd;
		if (cmd == 'L')
		{
			if (cursor != li.begin()) cursor--;
		}
		else if (cmd == 'D')
		{
			if (cursor != li.end()) cursor++;
		}
		else if (cmd == 'B')
		{
			if (cursor != li.begin())
			{
				cursor--;
				li.erase(cursor++);
			}
		}
		else if (cmd == 'P')
		{
			char temp;
			cin >> temp;
			li.insert(cursor, temp);
		}
	}

	for (auto& x : li)
	{
		cout << x;
	}


	// 시간초과에여.
	//while (m > 0)
	//{
	//	m--;
	//	cin >> cmd;
	//	if (cmd == "L")
	//	{
	//		if (cursor > 0) cursor--;
	//	}
	//	else if (cmd == "D")
	//	{
	//		if (cursor < str.size()) cursor++;
	//	}
	//	else if (cmd == "B")
	//	{
	//		if (cursor != 0)
	//		{
	//			str.erase(str.begin() + cursor - 1);
	//			cursor--;
	//		}
	//	}
	//	else if (cmd == "P")
	//	{
	//		char temp;
	//		cin >> temp;
	//		str.insert(str.begin() + cursor, temp);
	//		cursor++;
	//	}
	//	//cout << str << "(" << cursor << ")" << endl;
	//}
	//cout << str;

	return 0;
}