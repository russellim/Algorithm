// 21.01.30. 토
// 1717: 집합의 표현 https://www.acmicpc.net/problem/1717
// 분리집합.
#include <iostream>
#include <vector>

using namespace std;

struct Set
{
    int data;
    Set* parent;

public:
    void CreateSet(int data)
    {
        this->data = data;
        this->parent = this;
    }

    Set* GetParent()
    {
        Set* temp = this;

        while (temp->parent->data != temp->data)
            temp = temp->parent;
        return temp;
    }

    bool IsSameParent(Set* OtherSet)
    {
        Set* temp1 = GetParent();
        Set* temp2 = OtherSet->GetParent();
        return (temp1 == temp2);
    }

    void UnionSet(Set* OtherSet)
    {
        Set* temp1 = GetParent();
        Set* temp2 = OtherSet->GetParent();
        if (temp1->data < temp2->data) temp2->parent = temp1->parent;
        else temp1->parent = temp2->parent;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, cmd, a, b;
    cin >> n >> m;
    vector<Set> v(n + 1);
    for (int i = 0; i <= n; ++i) v[i].CreateSet(i);

    while (m--)
    {
        cin >> cmd >> a >> b;

        if (cmd == 0)
        {
            if (!v[a].IsSameParent(&v[b]))
                v[a].UnionSet(&v[b]);
        }
        else
        {
            if (a == b)
            {
                cout << "YES\n";
                continue;
            }

            if (v[a].IsSameParent(&v[b])) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}

//// 기냥 Find로 찾아버리기.
//pair<pair<vector<int>, vector<int>>, pair<int, int> > SearchNumber(vector<vector<int> >& v, int a, int b)
//{
//    int vsize = v.size();
//    vector<int> set1, set2;
//    int index1 = -1, index2 = -1;
//    for (int i = 0; i < vsize; ++i)
//    {
//        if (index1 == -1)
//        {
//            auto it = find(v[i].begin(), v[i].end(), a);
//            if (it != v[i].end())
//            {
//                set1 = v[i];
//                index1 = i;
//            }
//        }
//        if (index2 == -1)
//        {
//            auto it = find(v[i].begin(), v[i].end(), b);
//            if (it != v[i].end())
//            {
//                set2 = v[i];
//                index2 = i;
//            }
//        }
//        if (set1.size() == 0 && set2.size() == 0) break;
//    }
//    if (set1.size() == 0) set1.push_back(a);
//    if (set2.size() == 0) set2.push_back(b);
//    return { {set1, set2}, {index1, index2} };
//}
    // 메인.
    //vector<vector<int> > v;
    //while (m--)
    //{
    //    cin >> cmd >> a >> b;
    //    if (cmd == 0)
    //    {
    //        auto res = SearchNumber(v, a, b);
    //        vector<int> set1 = res.first.first, set2 = res.first.second;
    //        int index1 = res.second.first, index2 = res.second.second;
    //
    //        if (set1 != set2)
    //        {
    //            if (index1 != -1)
    //            {
    //                if(v.size() != 1) swap(*(v.begin() + index1), *(v.end() - 1));
    //                v.pop_back();
    //            }
    //            if (index2 != -1)
    //            {
    //                if (v.size() != 1) swap(*(v.begin() + index2), *(v.end() - 1));
    //                v.pop_back();
    //            }
    //            vector<int> buff(set1.size() + set2.size());
    //            set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), buff.begin());
    //            v.push_back(buff);
    //        }
    //    }
    //    else
    //    {
    //        if (a == b)
    //        {
    //            cout << "YES\n";
    //            continue;
    //        }
    //        auto res = SearchNumber(v, a, b);
    //        vector<int> set1 = res.first.first, set2 = res.first.second;
    //
    //        if (set1 == set2) cout << "YES\n";
    //        else cout << "NO\n";
    //    }
    //}