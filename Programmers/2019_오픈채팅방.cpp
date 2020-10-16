// 20.10.16. 금
// 2019_오픈채팅방 https://programmers.co.kr/learn/courses/30/lessons/42888
// IDE 사용 금지.

// 수정 후, 굉장히 빨라졌음! map의 key 사용을 잘하자.
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> users;				// 유저 정보 (id, nickname).
    vector<pair<string, string> > chatlogs;	// 채팅 로그(id, "님이 ~~.").
    for(int i=0; i<record.size(); ++i)
    {
        string* cmd = new string[3];

		// ' ' 기준으로 문자열 자르기 유용! (sstream).
        istringstream ss(record[i]);
        int j=0;
        while (getline (ss, cmd[j], ' ')) ++j;
        
        if(cmd[0][0] == 'L')
        {
            chatlogs.push_back({cmd[1], "님이 나갔습니다."});
        }
        else
        {
             users[cmd[1]] = cmd[2]; // key값이 없으면 생성, 이미 있으면 덮어쓰기.
									 // insert는 덮어쓰기가 안됨.
            if(cmd[0][0] == 'E')
            {
                chatlogs.push_back({cmd[1], "님이 들어왔습니다."});
            }
        }
        delete[] cmd;
    }
    
    for(int i=0; i<chatlogs.size(); ++i)
    {
		// 채팅 로그의 아이디 -> 닉네임 변환.
		// map[key]로 value 가져올 수 있음!.
        answer.push_back(users[chatlogs[i].first] + chatlogs[i].second);
    }
    
    return answer;
}