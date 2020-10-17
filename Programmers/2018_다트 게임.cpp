// 20.10.18. 일
// kakao2018_다트 게임 https://programmers.co.kr/learn/courses/30/lessons/17682
// IDE 사용 금지.
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// 점수 적용 함수.
int SetScore(int score, char cmd)
{
    if(cmd == 'S') return score;
    else if(cmd == 'D') return pow(score, 2);
    else if(cmd == 'T') return pow(score, 3);
    else if(cmd == '*') return score * 2;
    else if(cmd == '#') return score * -1;
}

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    string tempscore = "";
    for(int i=0; i<dartResult.size(); ++i)
    {
        if(isdigit(dartResult[i]))
        {
            // 10 같이 두개 문자로 된 숫자 때문에 일단 string으로 합체 시켜줌.
            tempscore += dartResult[i];
        }
        else
        {
            if(tempscore != "")
            {
                // 합체 시킨 string -> int로 변환.
                int temp = atoi(tempscore.c_str());
                tempscore = "";
                score.push_back(temp);
            }
            score[score.size()-1] = SetScore(score[score.size()-1], dartResult[i]);
            // *는 이전 점수 2배. (첫번째 점수면 말고).
            if(dartResult[i] == '*' && score.size() > 1)
                score[score.size()-2] = SetScore(score[score.size()-2], '*');
        }
    }
    
    for(int x: score)
    {
        answer += x;
    }
    
    return answer;
}