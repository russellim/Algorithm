// 21.03.24. 수
// 17070: 파이프 옮기기 1 https://www.acmicpc.net/problem/17070
// BFS.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace BOJ_17070
{
	struct Coord
	{
		int x, y;

		friend Coord operator+(const Coord& a, const Coord& b)
		{
			return { a.x + b.x, a.y + b.y };
		}
	};
	int n;
	constexpr int WALL = 1;

	bool IsRange(const Coord& coord)
	{
		return (coord.x < n&& coord.y < n);
	}

	void MakeMoveRoute(vector<vector<pair<Coord, int> > >& move)
	{
		move[0] = { {{0, 1}, 0}, {{1, 1}, 2} };
		move[1] = { {{1, 0}, 1}, {{1, 1}, 2} };
		move[2] = { {{0, 1}, 0}, {{1, 0}, 1}, { {1, 1}, 2} };
	}

	int bfs(vector<vector<int> >& mapp)
	{
		int answer = 0;
		vector<vector<pair<Coord, int> > > move(3, vector<pair<Coord, int> >());
		MakeMoveRoute(move);

		queue<pair<Coord, int> > q;
		q.push({ { 0, 1 }, 0 });

		while (!q.empty())
		{
			Coord nowPos = q.front().first;
			int nowDir = q.front().second;
			q.pop();
			for (int i = 0; i < move[nowDir].size(); ++i)
			{
				Coord nextPos = nowPos + move[nowDir][i].first;
				if (!IsRange(nextPos) || mapp[nextPos.x][nextPos.y] == WALL) continue;
				int nextDir = move[nowDir][i].second;
				// 대각선 파이프는 범위검사 한번 더. 
				if (nextDir == 2 && (mapp[nowPos.x + 1][nowPos.y] == WALL || mapp[nowPos.x][nowPos.y + 1] == WALL)) continue;
				if (nextPos.x == n - 1 && nextPos.y == n - 1)
				{
					answer++;
					continue;
				}
				q.push({ nextPos, nextDir });
			}
		}
		return answer;
	}

	void Solution()
	{
		cin >> n;
		vector<vector<int> > mapp(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> mapp[i][j];
			}
		}

		cout << bfs(mapp);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_17070::Solution();

	return 0;
}