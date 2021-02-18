// 21.02.18. 목
// 9019: DSLR https://www.acmicpc.net/problem/9019
// BFS.
#include <iostream>
#include <queue>
#include <string>

using namespace std;

namespace BOJ_9019
{
	int a, b;

	int cmdD(int n)
	{
		return (n * 2) % 10000;
	}
	int cmdS(int n)
	{
		if (n == 0) return 9999;
		return n - 1;
	}
	int cmdL(int n)
	{
		return ((n % 1000) * 10) + (n / 1000);
	}
	int cmdR(int n)
	{
		return ((n % 10) * 1000) + (n / 10);
	}

	// 굳이 switch를 쓰면 시간이 두배나 더 걸린다.
	//pair<string, int> Calcul(int cal, string cmd, int num)
	//{
	//	switch (cal)
	//	{
	//	case 1: return { cmd + "D", cmdD(num) };
	//	case 2: return { cmd + "S", cmdS(num) };
	//	case 3: return { cmd + "L", cmdL(num) };
	//	case 4: return { cmd + "R", cmdR(num) };
	//	default: break;
	//	}
	//	return { cmd, num };
	//}

	string Search()
	{
		bool visit[10001]{ false }; // 중요!
		queue<pair<string, int> >q;
		q.push({ "", a });
		visit[a] = true;

		while (!q.empty())
		{
			string cmd = q.front().first;
			int num = q.front().second;
			q.pop();
			// switch 있는 함수 사용한 코드.
			//for (int i = 1; i <= 4; ++i)
			//{
			//	auto res = Calcul(i, cmd, num);
			//	if (res.second == b) return res.first;
			//	if (!visit[res.second])
			//	{
			//		q.push(res);
			//		visit[res.second] = true;
			//	}
			//}
			int res;
			res = cmdD(num);
			if (res == b) return cmd + "D";
			if (!visit[res])
			{
				q.push({ cmd + "D", res });
				visit[res] = true;
			}
			res = cmdS(num);
			if (res == b) return cmd + "S";
			if (!visit[res])
			{
				q.push({ cmd + "S", res });
				visit[res] = true;
			}
			res = cmdL(num);
			if (res == b) return cmd + "L";
			if (!visit[res])
			{
				q.push({ cmd + "L", res });
				visit[res] = true;
			}
			res = cmdR(num);
			if (res == b) return cmd + "R";
			if (!visit[res])
			{
				q.push({ cmd + "S", res });
				visit[res] = true;
			}
		}
	}

	void Solution()
	{
		int t;
		cin >> t;
		while (t--)
		{
			cin >> a >> b;
			cout << Search() << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_9019::Solution();

	return 0;
}