// 20.10.19. 월
// 2019 카카오겨울인턴_튜플  https://programmers.co.kr/learn/courses/30/lessons/64065
// string, sort. IDE 사용 금지!
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> > v; // 2차원 int 벡터로 저장할거임.
    vector<int> vtemp;      // 벡터 하나씩 일단 저장할거임.
    bool vstart = false;
    string temp;
    // 문자열 -> 2차원 벡터로. 
    for (int i = 1; i < s.size() - 1; ++i)
    {
        if (s[i] == '{') vstart = true;
        else if (isdigit(s[i])) temp += s[i];
        else if (vstart && s[i] == ',')
        {
            vtemp.push_back(atoi(temp.c_str()));
            temp = "";
        }
        else if (s[i] == '}')
        {
            vtemp.push_back(atoi(temp.c_str()));
            temp = "";
            v.push_back(vtemp);
            vtemp.clear();
            vstart = false;
        }
    }

    // 길이 짧은 순으로 재정렬(람다함수 사용.)
    sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {return a.size() < b.size(); });

    // 정렬된 순으로 탐색하면서 새로 생긴 숫자를 answer에 푸시백.
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = v[i].size() - 1; j >= 0; --j)
        {
            if (find(answer.begin(), answer.end(), v[i][j]) == answer.end())
            {
                answer.push_back(v[i][j]);
                break;
            }
        }
    }

    return answer;
}