// 21.03.11. 목
// DFS/BFS_단어 변환 https://programmers.co.kr/learn/courses/30/lessons/43163
// BFS.
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int NumOfDifferent(string s1, string s2)
{
	int different = 0;
	for (int i = 0; i < s1.size(); ++i)
	{
		if (s1[i] != s2[i]) different++;
	}
	return different;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	if (find(words.begin(), words.end(), target) == words.end())
	{
		return 0;
	}

	vector<bool> visit(words.size(), false);
	queue<pair<string, int> > q;
	q.push({ begin, 0 });

	while (!q.empty())
	{
		string nowStr = q.front().first;
		int nowCount = q.front().second;
		q.pop();
		for (int i = 0; i < words.size(); ++i)
		{
			if (visit[i]) continue;
			if (NumOfDifferent(nowStr, words[i]) != 1) continue;
			if (words[i] == target) return nowCount + 1;
			visit[i] = true;
			q.push({ words[i], nowCount + 1 });
		}
	}

	return answer;
}