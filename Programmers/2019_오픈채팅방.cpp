// 20.10.16. 금
// 2019_오픈채팅방 https://programmers.co.kr/learn/courses/30/lessons/42888
// IDE 사용 금지.
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string> > users;
    vector<pair<string, string> > chatlogs;
    string cmd, id, nick;
    for(int i=0; i<record.size(); ++i)
    {
	cmd = record[i].substr(0, record[i].find(' '));
        record[i] = record[i].substr(record[i].find(' ')+1);
        id = record[i].substr(0, record[i].find(' '));
        // users에 데이터가 있는지 검사
        auto it = users.begin();
        for(; it != users.end(); ++it)
        {
            if(it->first == id)
            {
                break;
            }
        }
        if(it == users.end())
        {
            // users에 데이터 없음. ""Enter"" 처음 한 칭구만 여기 걸림.
            record[i] = record[i].substr(record[i].find(' ')+1);
            nick = record[i];
            users.push_back({id, nick});
            chatlogs.push_back({id, "님이 들어왔습니다."});
        }
        else
        {
            // users에 데이터 있음. Enter, Leave, Change.
            if(cmd == "Leave")
            {
                chatlogs.push_back({id, "님이 나갔습니다."});
            }
            else // Enter, Change.
            {
                record[i] = record[i].substr(record[i].find(' ')+1);
                nick = record[i];
                if(cmd == "Enter")
                {
                    chatlogs.push_back({id, "님이 들어왔습니다."});
                }
                it->second = nick;
            }
        }
    }
    
    for(int i=0; i<chatlogs.size(); ++i)
    {
        auto it = users.begin();
        for(; it != users.end(); ++it)
        {
            if(it->first == chatlogs[i].first)
            {
                break;
            }
        }
        answer.push_back(it->second + chatlogs[i].second);
    }
    
    return answer;
}