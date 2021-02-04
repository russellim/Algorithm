// 21.02.04. 목
// 1764: 듣보잡 https://www.acmicpc.net/problem/1764
// 방법1. 이분탐색, 방법2. 해시맵.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 이분탐색: 5964kb, 32ms. solved.
bool BinarySearch(vector<string>& v, string& str)
{
    int start = 0, end = v.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == str) return true;
        if (v[mid] > str) end = mid - 1;
        else start = mid + 1;
    }
    return false;
}
void Solution_BinarySearch()
{
    int n, m;
    cin >> n >> m;
    vector<string> noHears(n), noSees;
    for (int i = 0; i < n; ++i)
    {
        cin >> noHears[i];
    }
    sort(noHears.begin(), noHears.end());

    string temp;
    for (int i = 0; i < m; ++i)
    {
        cin >> temp;
        if (BinarySearch(noHears, temp)) noSees.push_back(temp);
    }

    sort(noSees.begin(), noSees.end());
    cout << noSees.size() << "\n";
    for (string& x : noSees) cout << x << "\n";
}

// 해시맵: 12988kb, 52ms. solved.
void Solution_Map()
{
    int n, m;
    cin >> n >> m;
    map<string, int> noHears;
    vector<string> noSees;

    string temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        noHears[temp] = 1;
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> temp;
        if (noHears[temp] == 1)
            noSees.push_back(temp);
    }
    sort(noSees.begin(), noSees.end());
    cout << noSees.size() << "\n";
    for (string x : noSees) cout << x << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //Solution_Map();
    Solution_BinarySearch();

    return 0;
}