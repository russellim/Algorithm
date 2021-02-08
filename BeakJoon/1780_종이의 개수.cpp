// 21.02.08. 월
// 1780: 종이의 개수 https://www.acmicpc.net/problem/1780
// 분할정복.
#include <iostream>
#include <vector>
using namespace std;

namespace Solution
{
    int n;
    vector<int> count;
    vector<vector<int> > paper;
    void Divide(int startRow, int startCol, int endRow, int endCol);

    void CheckDividePaper(int startRow, int startCol, int endRow, int endCol)
    {
        int FirstNum = paper[startRow][startCol];
        for (int i = startRow; i < endRow; ++i)
        {
            for (int j = startCol; j < endCol; ++j)
            {
                if (FirstNum != paper[i][j])
                {
                    Divide(startRow, startCol, endRow, endCol);
                    return;
                }
            }
        }
        count[FirstNum + 1]++;
    }

    void Divide(int startRow, int startCol, int endRow, int endCol)
    {
        int size = (endRow - startRow) / 3;
        // 9분할.
        CheckDividePaper(startRow, startCol, startRow + size, startCol + size);
        CheckDividePaper(startRow, startCol + size, startRow + size, startCol + size * 2);
        CheckDividePaper(startRow, startCol + size * 2, startRow + size, endCol);

        CheckDividePaper(startRow + size, startCol, startRow + size * 2, startCol + size);
        CheckDividePaper(startRow + size, startCol + size, startRow + size * 2, startCol + size * 2);
        CheckDividePaper(startRow + size, startCol + size * 2, startRow + size * 2, endCol);

        CheckDividePaper(startRow + size * 2, startCol, endRow, startCol + size);
        CheckDividePaper(startRow + size * 2, startCol + size, endRow, startCol + size * 2);
        CheckDividePaper(startRow + size * 2, startCol + size * 2, endRow, endCol);
    }

    void Answer()
    {
        Divide(0, 0, n, n);
    }

    bool Input()
    {
        bool AllSame = true;
        cin >> n;
        paper.assign(n, vector<int>(n));
        count.assign(3, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> paper[i][j];
                if (paper[i][j] != paper[0][0]) AllSame = false;
            }
        }
        if (AllSame) count[paper[0][0] + 1]++;
        return AllSame;
    }
    void Output()
    {
        for (int x : count) cout << x << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (!Solution::Input())
    {
        Solution::Answer();
    }
    Solution::Output();

    return 0;
}