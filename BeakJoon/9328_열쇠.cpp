// 21.05.15. 토
// 9328: 열쇠 https://www.acmicpc.net/problem/9328
// BFS, 비트마스킹.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace BOJ_9328
{
	struct Pos
	{
		int x, y;
		friend Pos operator+(Pos& a, Pos& b)
		{
			return { a.x + b.x, a.y + b.y };
		}
	};
	Pos dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	int CharToInt(char c)
	{
		return c - 'a';
	}

	bool CheckAlphaGo(char c, int& key)
	{
		if (isupper(c))
		{
			if (!(key & 1 << CharToInt(tolower(c))))
			{
				return false;
			}
		}
		else if (islower(c))
		{
			key |= 1 << CharToInt(c);
		}
		return true;
	}

	bool IsRange(int h, int w, Pos& pos)
	{
		return (pos.x >= 0 && pos.y >= 0 && pos.x < h&& pos.y < w);
	}

	void test(int h, int w, vector<vector<char> >& mapp)
	{
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cout << mapp[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}

	int BFS(int h, int w, vector<vector<char> >& mapp, vector<Pos>& enter, int key)
	{
		int res = 0;
		if (enter.size() == 0) return res;
		vector<Pos> savePos;
		queue<Pos> q;
		for (Pos& start : enter)
		{
			if (!CheckAlphaGo(mapp[start.x][start.y], key))
			{
				savePos.push_back(start);
				continue;
			}
			if (mapp[start.x][start.y] == '$') ++res;
			mapp[start.x][start.y] = '#';
			q.push(start);

			while (!q.empty())
			{
				Pos now = q.front();
				q.pop();

				for (int i = 0; i < 4; ++i)
				{
					Pos next = now + dir[i];
					if (!IsRange(h, w, next)) continue;
					if (mapp[next.x][next.y] == '#' || mapp[next.x][next.y] == '*') continue;

					char c = mapp[next.x][next.y];
					if (isalpha(c))
					{
						if (!CheckAlphaGo(c, key))
						{
							savePos.push_back(next);
							continue;
						}
						else
						{
							if (islower(c))
							{
								for (int s = 0; s < savePos.size(); ++s)
								{
									Pos save = savePos[s];
									if (tolower(mapp[save.x][save.y]) == c)
									{
										mapp[save.x][save.y] = '#';
										q.push(save);
										savePos.erase(savePos.begin() + s);
										--s;
									}
								}
							}
						}
					}
					else if (c == '$') ++res;
					mapp[next.x][next.y] = '#';
					q.push(next);
				}

				//test(h, w, mapp);
			}

		}
		return res;
	}

	void Solution()
	{
		int t;
		cin >> t;
		while (t--)
		{
			int h, w;
			cin >> h >> w;
			vector<vector<char> > mapp(h, vector<char>(w));
			vector<Pos> enter;
			int key = 1 << 26;
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					cin >> mapp[i][j];
					if ((i == 0 || j == 0 || i == h - 1 || j == w - 1) && mapp[i][j] != '*')
					{
						enter.push_back({ i, j });
					}
				}
			}
			string st;
			cin >> st;
			if (st != "0")
				for (char& c : st) key |= 1 << CharToInt(c);

			cout << BFS(h, w, mapp, enter, key) << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_9328::Solution();

	return 0;
}