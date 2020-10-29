// 20.10.28. 수
// kakao 2018_방금그곡 https://programmers.co.kr/learn/courses/30/lessons/17683
// String. IDE 사용 금지!
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// # 치환을 안한 방법.
string solution(string m, vector<string> musicinfos) {
    pair<int, int> maxMusic = { -1, -1 };
    for (int i = 0; i < musicinfos.size(); ++i)
    {
        // 시간 계산에 주의! 1시간은 60분이라 시간*60+분은 계산이 안된다.
        // 사소한건데 이것때문에 계속 틀렸으니까 기억해둬.
        int time = (atoi(musicinfos[i].substr(6, 2).c_str()) - atoi(musicinfos[i].substr(0, 2).c_str())) * 60
            + (atoi(musicinfos[i].substr(9, 2).c_str()) - atoi(musicinfos[i].substr(3, 2).c_str()));

        string originNote = musicinfos[i].substr(musicinfos[i].find(',', 12) + 1);
        string note;
        int play = 0;
        // 라디오에서 재생된 악보 생성.
        for (int j = 0; j < time; ++j)
        {
            note += originNote[play++];
            if (play < originNote.size() && originNote[play] == '#')
            {
                note += originNote[play++];
            }
            if (play >= originNote.size()) play = 0;
        }

        int temp = 0; // 찾은 #의 위치.
        while (1)
        {
            if (note.find(m, temp) == string::npos) break;
            int findindex = note.find(m, temp) + m.size();
            if (findindex < note.size() - 1 && note[findindex] == '#')
            {
                temp = findindex;
                continue;
            }
            if (maxMusic.second < time) maxMusic = { i, time };
            break;
        }
    }

    if (maxMusic.first == -1) return "(None)";
    else return musicinfos[maxMusic.first].substr(12, musicinfos[maxMusic.first].find(',', 12) - 12);
}



// 놀랍게도 #을 치환한 방법을 쓴 이 코드는 30번이 틀린다.
//#include <sstream>
//
//using namespace std;
//
//// # -> 소문자로 변환.
//void sharpTolower(string& st)
//{
//    while (1)
//    {
//        if (st.find('#') == string::npos)
//            break;
//        int index = st.find('#');
//        string lower(1, tolower(st[index - 1]));
//        st.replace(index - 1, 2, lower);
//    }
//}
//
//string solution(string m, vector<string> musicinfos) {
//    pair<string, int> maxMusic = { "-1", -1 };
//    sharpTolower(m);
//
//    for (int i = 0; i < musicinfos.size(); ++i)
//    {
//        string info[4];
//        istringstream ss(musicinfos[i]);
//        int j = 0;
//        while (getline(ss, info[j], ',')) ++j;
//
//        int time = (atoi(info[1].substr(0, 2).c_str()) - atoi(info[0].substr(0, 2).c_str())) * 60
//            + (atoi(info[1].substr(3, 2).c_str()) - atoi(info[0].substr(3, 2).c_str()));
//
//        string originNote = info[3];
//        sharpTolower(originNote);
//        string note;
//        while (note.size() < time)
//        {
//            note += originNote;
//        }
//        note.substr(0, time);
//
//        if (note.find(m) == string::npos) continue;
//        if (maxMusic.second < time) maxMusic = { info[2], time };
//    }
//
//    if (maxMusic.second == -1) return "(None)";
//    else return maxMusic.first;
//}