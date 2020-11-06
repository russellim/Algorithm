// 20.11.06. 금
// 2018_셔틀버스 https://programmers.co.kr/learn/courses/30/lessons/17678
// 구현.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

// 00:00 -> 분으로.
int timeToint(string s)
{
    int h = atoi(s.substr(0, 2).c_str());
    int m = atoi(s.substr(3).c_str());

    return h * 60 + m;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "09:00";
    stringstream ss;

    vector<int> crews; // 크루 시간표.
    vector<int> bus; // 버스 시간표.

    for (auto& x : timetable) crews.push_back(timeToint(x));
    sort(crews.begin(), crews.end());

    // 버스 배차.
    bus.push_back(540);
    for (int i = 1; i < n; ++i)
    {
        bus.push_back(540 + t * i);
    }

    int pivot = 0;
    for (int i = 0; i < bus.size(); ++i)
    {
        int mtemp = m;
        for (int j = pivot; j < crews.size(); ++j)
        {
            // 배차 전에 온 칭구들.
            if (bus[i] >= crews[j])
            {
                pivot++;
                mtemp--;
            }
            else break;

            // 막차에 빈자리 없어지면 막 친구 이전에 오세용.
            if (i == bus.size() - 1 && mtemp == 0)
            {
                int t = crews[j] - 1;
                ss << setfill('0') << setw(2) << t / 60 << ":" << setfill('0') << setw(2) << t % 60;
                return ss.str();
            }

            // 이 버스 꽉찼어요.
            if (mtemp == 0) break;
        }

        // 막차까지 다 안차면 막차올때 딱 탑니다.
        if (i == bus.size() - 1)
        {
            ss << setfill('0') << setw(2) << bus[i] / 60 << ":" << setfill('0') << setw(2) << bus[i] % 60;
            return ss.str();
        }
    }

    return answer;
}

int main()
{
    cout << solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" }) << endl;
    cout << endl;
    cout << solution(2, 10, 2, { "09:10", "09:09", "08:00" }) << endl;
    cout << endl;
    cout << solution(2, 1, 2, { "09:00", "09:00", "09:00", "09:00" }) << endl;
    cout << endl;
    cout << solution(1, 1, 5, { "00:01", "00:01", "00:01", "00:01", "00:01" }) << endl;
    cout << endl;
    cout << solution(1, 1, 1, { "23:59" }) << endl;
    cout << endl;
    cout << solution(10, 60, 45, { "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" }) << endl;
    cout << endl;
    return 0;
}