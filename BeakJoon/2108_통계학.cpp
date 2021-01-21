// 21.01.21. 목
// 2108: 통계학 https://www.acmicpc.net/problem/2108
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int>m;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
        m[v[i]]++;
    }

    cout << round(sum / (double)n) << endl;

    sort(v.begin(), v.end());
    cout << v[n / 2] << endl;

    if (n == 1)
    {
        cout << v[0] << "\n0";
        return 0;
    }
    vector<pair<int, int> > p(m.begin(), m.end());
    sort(p.begin(), p.end(), cmp);
    if (p[0].second == p[1].second) cout << p[1].first << endl;
    else cout << p[0].first << endl;

    cout << v[n - 1] - v[0];

    return 0;
}