// 20.10.28. 수
// kakao 2018_방금그곡 https://programmers.co.kr/learn/courses/30/lessons/17683
// String. IDE 사용 금지!

// 6~9, 21 ,27 Failed.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    pair<int, int> maxMusic = { -1, -1 };
    for (int i = 0; i < musicinfos.size(); ++i)
    {
        int time = atoi(musicinfos[i].substr(6, 2).c_str()) * 60 + atoi(musicinfos[i].substr(9, 2).c_str())
            - atoi(musicinfos[i].substr(0, 2).c_str()) * 60 + atoi(musicinfos[i].substr(3, 2).c_str());

        string originNote = musicinfos[i].substr(musicinfos[i].find(',', 12) + 1);
        string note;
        int play = 0;
        for (int j = 0; j < time; ++j)
        {
            note += originNote[play++];
            if (play < originNote.size() && originNote[play] == '#')
            {
                note += originNote[play++];
            }
            if (play >= originNote.size()) play = 0;
        }
        cout << note << endl;

        int temp = 0;
        while (1)
        {
            if (note.find(m, temp) == string::npos) break;
            int findindex = note.find(m, temp) + m.size();
            if (findindex < note.size() - 1 && note[findindex] == '#')
            {
                temp = findindex;
                cout << temp << endl;
                continue;
            }
            if (maxMusic.second < time) maxMusic = { i, time };
            break;
        }
    }

    if (maxMusic.first == -1) return "(None)";
    else return musicinfos[maxMusic.first].substr(12, musicinfos[maxMusic.first].find(',', 12) - 12);
}