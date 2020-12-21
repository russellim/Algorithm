// 20.12.21. 월
// 1753: 최단 경로 https://www.acmicpc.net/problem/1753
// 다익스트라 알고리즘.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v, e, start;
    cin >> v >> e >> start;
    vector<vector<P> >data(v + 1, vector<P>());
    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        data[u].push_back({ v, w });
    }

    vector<int> dist(v + 1, 2e9);
    dist[start] = 0;

    // 그냥 큐로하면 시간초과.
    // 가중치 기준으로 하는 우선순위 큐를 사용합시다.
    priority_queue<P> q;
    q.push({ 0, start });

    while (!q.empty())
    {
        // 음수 사용하는 이유: priority_queue에서는 가장 큰 값이 top이 됨.
        // {2,3,5}가 들어가면 최소비용인 2->3->5를 뽑아 사용하고싶지만 (3, 5는 큐에 아마 안들어가겠지).
        // 가장 큰 값인 5->3->2를 사용하게 되는 것. (전부 큐에 들어가서 검사하겠네).
        // 이를 반전 시켜서 2(가장 작은 비용)을 사용할 수있게 넣을때 -(크기 반전), 꺼낼때 -(원래 값) 하는 것이다이마리야르.
        int nowDist = -q.top().first;
        int nowPos = q.top().second;
        q.pop();
        for (int i = 0; i < data[nowPos].size(); ++i)
        {
            int nextDist = nowDist + data[nowPos][i].second;
            int nextPos = data[nowPos][i].first;
            if (dist[nextPos] > nextDist)
            {
                dist[nextPos] = nextDist;
                q.push({ -nextDist, nextPos });
            }
        }
    }

    for (int i = 1; i <= v; ++i)
    {
        if (dist[i] == 2e9) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}