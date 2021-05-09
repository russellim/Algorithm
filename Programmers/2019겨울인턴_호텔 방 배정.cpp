// 21.05.07. 금
// kakao 2019겨울인턴_호텔 방 배정 https://programmers.co.kr/learn/courses/30/lessons/64063
// 데이터가 많을때는 map보다 umap의 find가 더 빠르다.
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> room;   // 방번호, 다음 방번호.

long long Find(long long n)
{
    if (room[n] == 0) return n;
    room[n] = Find(room[n]);
    return room[n];
}

vector<long long> solution(long long k, vector<long long> room_number) {
    int peopleSize = room_number.size();
    vector<long long> answer(peopleSize);

    for (int i = 0; i < peopleSize; ++i)
    {
        long long wantRoom = room_number[i];
        if (room[wantRoom] == 0)
        {
            answer[i] = wantRoom;
            room[wantRoom] = Find(wantRoom + 1);
        }
        else
        {
            long long nextRoom = Find(wantRoom);
            answer[i] = nextRoom;
            room[nextRoom] = Find(nextRoom + 1);
        }
    }
    return answer;
}