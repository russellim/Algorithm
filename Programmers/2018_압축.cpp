// 20.10.26. 월
// kakao 2018_압축 https://programmers.co.kr/learn/courses/30/lessons/17684
// string. IDE 사용 금지!
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict(27);
    for (int i = 1; i < 27; ++i) dict[i] = 65 + i - 1;

    for (int i = 0; i < msg.size(); ++i)
    {
        string temp = "";
        // 사전 뒤에부터 탐색하십셔(긴거 우선).
        for (int j = dict.size() - 1; j > 0; --j)
        {
            if (msg.find(dict[j]) == i)
            {
                // 긴 문자일 수도 있으니 사이즈 봐서 저장해주세요.
                for (int k = i; k < i + dict[j].size(); ++k)
                {
                    temp += msg[k];
                    msg[k] = '*';   // 찾은 문자는 다음에 못찾게 다른 거 넣어줌.
                }
                i += dict[j].size() - 1;
                answer.push_back(j);
                break;
            }
        }
        // 사전 추가.
        if (i < msg.size() - 1)
        {
            temp += msg[i + 1];
            dict.push_back(temp);
        }
    }

    return answer;
}