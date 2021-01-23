// 21.01.23. 토
// 1992: 쿼드트리 https://www.acmicpc.net/problem/1992
// 재귀.
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Coord;

void QuadTree(vector<vector<char> >& image, Coord start, Coord end);

void Analysis(vector<vector<char> >& image, int istart, int iend, int jstart, int jend)
{
    char base = image[istart][jstart];
    for (int i = istart; i < iend; ++i)
    {
        for (int j = jstart; j < jend; ++j)
        {
            if (image[i][j] != base)
            {
                QuadTree(image, { istart, jstart }, { iend, jend });
                return;
            }
        }
    }
    cout << base;
}

void QuadTree(vector<vector<char> >& image, Coord start, Coord end)
{
    cout << "(";

    if (end.first - start.first == 2)
    {
        for (int i = start.first; i < end.first; ++i)
            for (int j = start.second; j < end.second; ++j)
                cout << image[i][j];
        cout << ")";
        return;
    }

    // 4분할 검사.
    Analysis(image,
        start.first,
        (start.first + end.first) / 2,
        start.second,
        (start.second + end.second) / 2);

    Analysis(image,
        start.first,
        (start.first + end.first) / 2,
        (start.second + end.second) / 2,
        end.second);

    Analysis(image,
        (start.first + end.first) / 2,
        end.first,
        start.second,
        (start.second + end.second) / 2);

    Analysis(image,
        (start.first + end.first) / 2,
        end.first,
        (start.second + end.second) / 2,
        end.second);

    cout << ")";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<char> > image(n, vector<char>(n));
    bool IsAll = true; // 전부 같은 색인지 검사.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> image[i][j];
            if (image[0][0] != image[i][j]) IsAll = false;
        }
    }

    if (IsAll)
    {
        cout << image[0][0];
        return 0;
    }

    QuadTree(image, { 0,0 }, { n, n });

    return 0;
}