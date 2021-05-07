// 21.05.07. 금
// kakao 2019겨울인턴_호텔 방 배정 https://programmers.co.kr/learn/courses/30/lessons/64063

// failed 효율성 탈락 -> 탐색 최소로.
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<bool> room(k+1, false);
    long long pointer = 1;
    int peopleSize = room_number.size();
    vector<long long> answer(peopleSize);
    
    for(int i=0; i<peopleSize; ++i)
    {
        long long wantRoom = room_number[i];
        if(room[wantRoom])
        {
            if(wantRoom < pointer)
            {
                wantRoom = pointer;
            }
            while(room[wantRoom]) wantRoom++;
        }
        room[wantRoom] = true;
        answer[i] = wantRoom;
        while(room[pointer]) pointer++;
    }
    return answer;
}