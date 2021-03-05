// 21.03.05. 금
// DFS/BFS: 네트워크 https://programmers.co.kr/learn/courses/30/lessons/43162
// DFS.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> visit;

void dfs(vector<vector<int> >& com, int node)
{
    visit[node] = true;
    for (int i = 0; i < com[node - 1].size(); ++i)
    {
        int next = i + 1;
        if (next == node) continue;
        if (com[node - 1][i] == 0) continue;
        if (visit[next]) continue;
        dfs(com, next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visit.assign(n + 1, false);

    for (int i = 1; i <= n; ++i)
    {
        if (visit[i]) continue;
        dfs(computers, i);
        answer++;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} });

    return 0;
}