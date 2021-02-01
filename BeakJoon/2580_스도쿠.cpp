// 21.02.01. 월
// 2580: 스도쿠 https://www.acmicpc.net/problem/2580
// 구현.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SUDOKULINE 9
vector<vector<int> > sudoku;
vector<pair<int, int> > unSolved;
vector<int> nums;

void OutputSudoku()
{
    for (int i = 0; i < SUDOKULINE; ++i)
    {
        for (int j = 0; j < SUDOKULINE; ++j)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}

bool analysisRow_2(int x, int y)
{
    for (int j = 0; j < SUDOKULINE; ++j)
    {
        if (j == y) continue;
        if (sudoku[x][j] == sudoku[x][y]) return false;
    }
    return true;
}
bool analysisColumn_2(int x, int y)
{
    for (int i = 0; i < SUDOKULINE; ++i)
    {
        if (i == x) continue;
        if (sudoku[i][y] == sudoku[x][y]) return false;
    }
    return true;
}
bool analysis3x3_2(int x, int y)
{
    int starti = x / 3 * 3, startj = y / 3 * 3;
    for (int i = starti; i < starti + 3; ++i)
    {
        for (int j = startj; j < startj + 3; ++j)
        {
            if (i == x && j == y) continue;
            if (sudoku[i][j] == sudoku[x][y]) return false;
        }
    }
    return true;
}
void solutionStep2()
{
    if (unSolved.empty()) return;
    int x = unSolved.back().first, y = unSolved.back().second;
    unSolved.pop_back();
    for (int i = 1; i <= SUDOKULINE; ++i)
    {
        sudoku[x][y] = i;
        if (analysisRow_2(x, y) && analysisColumn_2(x, y) && analysis3x3_2(x, y))
        {
            solutionStep2();
            if (unSolved.empty()) return;
        }
    }
    sudoku[x][y] = 0;
    unSolved.push_back({ x, y });
}

void analysisRow(int x, int y)
{
    for (int j = 0; j < SUDOKULINE; ++j)
    {
        if (j == y || sudoku[x][j] == 0) continue;
        nums[sudoku[x][j] - 1]++;
    }
}
void analysisColumn(int x, int y)
{
    for (int i = 0; i < SUDOKULINE; ++i)
    {
        if (i == x || sudoku[i][y] == 0) continue;
        nums[sudoku[i][y] - 1]++;
    }
}
void analysis3x3(int x, int y)
{
    int starti = x / 3 * 3, startj = y / 3 * 3;
    for (int i = starti; i < starti + 3; ++i)
    {
        for (int j = startj; j < startj + 3; ++j)
        {
            if ((i == x && j == y) || sudoku[i][j] == 0) continue;
            nums[sudoku[i][j] - 1]++;
        }
    }
}
int DestroyUnSolved(int i)
{
    swap(unSolved[i], unSolved[unSolved.size() - 1]);
    unSolved.pop_back();
    return i - 1;
}
int FindCountZero()
{
    int count = 0, zero = 0;
    for (int i = 0; i < SUDOKULINE; ++i)
    {
        if (nums[i] == 0)
        {
            count++;
            zero = i + 1;
        }
    }
    return (count == 1 ? zero : 0);
}
void solutionStep1()
{
    bool IsChanged = true;
    while (IsChanged)
    {
        IsChanged = false;
        for (int i = 0; i < unSolved.size(); ++i)
        {
            nums.assign(SUDOKULINE, 0);
            int x = unSolved[i].first, y = unSolved[i].second;
            analysisRow(x, y);
            analysisColumn(x, y);
            analysis3x3(x, y);
            sudoku[x][y] = FindCountZero();
            if (sudoku[x][y] == 0) continue;
            IsChanged = true;
            DestroyUnSolved(i);
        }
    }
}


void InputSudoku()
{
    sudoku.assign(SUDOKULINE, vector<int>(SUDOKULINE));
    for (int i = 0; i < SUDOKULINE; ++i)
    {
        for (int j = 0; j < SUDOKULINE; ++j)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) unSolved.push_back({ i, j });
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    InputSudoku();
    solutionStep1();

    reverse(unSolved.begin(), unSolved.end());
    if (!unSolved.empty()) solutionStep2();

    OutputSudoku();

    return 0;
}