// 21.02.03. 수
// 2252: 줄 세우기 https://www.acmicpc.net/problem/2252
// 위상정렬
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> linkFrontCount;
vector<vector<int> > graph;

void TopologicalSort(int n)
{
    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        // 선행 정점 없는 정점들(앞이 없는 애들) 큐에 우선 넣기.
        if (linkFrontCount[i] == 0) q.push(i);
    }

    for (int i = 0; i < n; ++i)
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";

        for (int x : graph[temp])
        {
            linkFrontCount[x]--;
            if (linkFrontCount[x] == 0) q.push(x);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    linkFrontCount.assign(n + 1, 0);
    graph.assign(n + 1, vector<int>());

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        linkFrontCount[b]++;
    }

    TopologicalSort(n);

    return 0;
}

// 시간초과 코드.
//vector<pair<int, int> > priority;
//
//struct Student
//{
//    int Num;
//    vector<struct Student*> parent;
//public:
//    Student(int num) { Num = num; }
//
//    void AddParent(Student* p)
//    {
//        parent.push_back(p);
//    }
//
//    void AddPriority()
//    {
//        for (int i = 0; i < parent.size(); ++i)
//        {
//            Student* temp = this;
//            if (temp->parent[i] != nullptr)
//            {
//                temp = temp->parent[i];
//                priority[temp->Num - 1].second++;
//                temp->AddPriority();
//            }
//        }
//    }
//};
//
//bool comp(pair<int, int>& a, pair<int, int>& b)
//{
//    return a.second > b.second;
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int n, m, a, b;
//    cin >> n >> m;
//    vector<Student> student;
//    for (int i = 1; i <= n; ++i)
//    {
//        priority.push_back({ i, 0 });
//        student.push_back(Student(i));
//    }
//
//    while (m--)
//    {
//        cin >> a >> b;
//        student[b-1].AddParent(&student[a-1]);
//        student[b-1].AddPriority();
//    }
//
//    sort(priority.begin(), priority.end(), comp);
//    for (auto x : priority) cout << x.first << " ";
//
//    return 0;
//}