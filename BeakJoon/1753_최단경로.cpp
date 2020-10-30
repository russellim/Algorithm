// 20.10.30. 금
// 1753_최단경로 https://www.acmicpc.net/problem/1753
// 다익스트라 알고리즘.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solution(vector<pair<int, int> >* data, int v, int e, int start)
{
    int* dist = new int[e + 1];
    fill(dist, dist + e + 1, 1e9);
    priority_queue<pair<int, int> > q;  // cost, 위치.
    q.push({ 0, start });
    dist[start] = 0;

    while (!q.empty())
    {
        // 음수 사용하는 이유: priority_queue에서는 가장 큰 값이 top이 됨.
        // {2,3,5}가 들어가면 최소비용인 2->3->5를 뽑아 사용하고싶지만 (3, 5는 큐에 아마 안들어가겠지).
        // 가장 큰 값인 5->3->2를 사용하게 되는 것. (전부 큐에 들어가서 검사하겠네).
        // 이를 반전 시켜서 2(가장 작은 비용)을 사용할 수있게 넣을때 -(크기 반전), 꺼낼때 -(원래 값) 하는 것이다이마리야르.
        int cost = -q.top().first; // 그러니까 사용하지는 않지만 꺼내는 순서를 결정하는데 필요하다.
        int cur = q.top().second;
        //cout << cost << " " << cur << endl; // - 지우고 확인해보세염!
        q.pop();
        for (int i = 0; i < data[cur].size(); ++i)
        {
            int next = data[cur][i].first;
            int nextcost = data[cur][i].second;
            if (dist[next] > dist[cur] + nextcost)
            {
                dist[next] = dist[cur] + nextcost;
                q.push({ -dist[next], next });
            }
        }
    }

    for (int i = 1; i <= v; ++i)
    {
        if (dist[i] == 1e9) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    delete[] dist;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v, e, start, from, to, w;
    cin >> v >> e >> start;
    vector<pair<int, int> > data[20001];
    for (int i = 0; i < e; ++i)
    {
        cin >> from >> to >> w;
        data[from].push_back(make_pair(to, w));
    }

    solution(data, v, e, start);
}