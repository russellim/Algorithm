// 20.12.14. 월
// kakao 2018_스킬트리 https://programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    string st;

    // 스킬트리에서 skill에 포함 하는 것만 남겨 체크합니다.
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        st = "";
        for (int j = 0; j < skill_trees[i].size(); ++j)
        {
            bool check = false;
            for (int k = 0; k < skill.size(); ++k)
            {
                if (skill_trees[i][j] == skill[k])
                {
                    check = true;
                    break;
                }
            }
            if (check) st += skill_trees[i][j];
        }
        // 남긴 단어가 skill에 0부터! 포함되어야함.
        if (skill.find(st) == 0) answer++;
    }

    return answer;
}