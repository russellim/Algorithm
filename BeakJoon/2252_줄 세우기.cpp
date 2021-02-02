// 21.02.02. 화
// 2252: 줄 세우기 https://www.acmicpc.net/problem/2252

// 위상정렬로 다시 풀것.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > priority;

struct Student
{
    int Num;
    vector<struct Student*> parent;
public:
    Student(int num) { Num = num; }

    void AddParent(Student* p)
    {
        parent.push_back(p);
    }

    void AddPriority()
    {
        for (int i = 0; i < parent.size(); ++i)
        {
            Student* temp = this;
            if (temp->parent[i] != nullptr)
            {
                temp = temp->parent[i];
                priority[temp->Num - 1].second++;
                temp->AddPriority();
            }
        }
    }
};

bool comp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    vector<Student> student;
    for (int i = 1; i <= n; ++i)
    {
        priority.push_back({ i, 0 });
        student.push_back(Student(i));
    }

    while (m--)
    {
        cin >> a >> b;
        student[b - 1].AddParent(&student[a - 1]);
        student[b - 1].AddPriority();
    }

    sort(priority.begin(), priority.end(), comp);
    for (auto x : priority) cout << x.first << " ";

    return 0;
}