// 21.06.11. 금
// 2533: 사회망 서비스(SNS) https://www.acmicpc.net/problem/2533
// DFS, DP.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace BOJ_2533
{
	vector<vector<int> > conn;
	vector<vector<int> > dir;
	vector<bool> visit;
	vector<bool> earlyAdaptor;
	vector<vector<int> > dp;

	int MakeEarlyAdaptor(int now, bool state)
	{
		int& res = dp[now][state];
		if (res != -1) return res;

		res = (int)state;
		for (int& next : dir[now])
		{
			// 현재가 얼리면 다음이 얼리 또는 아님.
			if(state) res += min(MakeEarlyAdaptor(next, true), MakeEarlyAdaptor(next, false));
			// 현재가 얼리아니면 다음이 얼리여야함.
			else res += MakeEarlyAdaptor(next, true);
		}

		return res;
	}

	void MakeOneDir(int to)
	{
		visit[to] = true;
		for (int& from : conn[to])
		{
			if (visit[from]) continue;
			dir[to].emplace_back(from);
			MakeOneDir(from);
		}
	}

	void Solution()
	{
		int n;
		cin >> n;
		conn.assign(n + 1, vector<int>());
		dir.assign(n + 1, vector<int>());
		for (int i = 0; i < n - 1; ++i)
		{
			int u, v;
			cin >> u >> v;
			conn[u].emplace_back(v);
			conn[v].emplace_back(u);
		}

		// 루트 정하고 단방향 그래프로 만들기.
		int root = 1;
		visit.assign(n + 1, false);
		MakeOneDir(root);

		// 얼리아답터 찾기.
		// 루트부터 밑으로 찾습니다.
		// 밑에서 나온 결과를 dp로 저장하면 시간 팍팍 줄음!.
		earlyAdaptor.assign(n + 1, false);
		dp.assign(n + 1, vector<int>(2, -1));
		cout << min(MakeEarlyAdaptor(root, true), MakeEarlyAdaptor(root, false));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2533::Solution();

	return 0;
}