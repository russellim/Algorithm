// 20.11.17. ghk
// 5430: AC https://www.acmicpc.net/problem/5430
// deque, istringstream.
#include <iostream>
#include <deque>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		deque<int> dq;
		string cmd, arr;
		int n;
		bool bPointFront = true;

		cin >> cmd;

		cin >> n;
		cin >> arr;
		if (n != 0)
		{
			string* strtemp = new string[n];
			//arr = arr.substr(1, arr.size()-2);
			istringstream ss(arr);
			int i = 0;
			while (getline(ss, strtemp[i], ',')) ++i;
			for (int i = 0; i < n; ++i)
			{
				dq.push_back(atoi(strtemp[i].c_str()));
			}
			delete[] strtemp;
		}

		bool bError = false;
		for (char& x : cmd)
		{
			if (x == 'R') bPointFront = !bPointFront;
			else if (x == 'D')
			{
				if (dq.empty())
				{
					cout << "error" << "\n";
					bError = true;
					break;
				}

				if (bPointFront) dq.pop_front();
				else dq.pop_back();
			}
		}

		if (!bError)
		{
			cout << "[";
			if (bPointFront)
			{
				for (int i = 0; i < dq.size(); ++i)
				{
					cout << dq[i];
					if (i != dq.size() - 1) cout << ",";
				}
			}
			else
			{
				for (int i = dq.size() - 1; i >= 0; --i)
				{
					cout << dq[i];
					if (i != 0) cout << ",";
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}