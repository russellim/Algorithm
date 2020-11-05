// 20.11.05. 목
// 2018_추석 트래픽 https://programmers.co.kr/learn/courses/30/lessons/17676
// 구현. IDE 금지.
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 시간 -> 초 start time, end time 반환.
// start time이 15일 이전이면 음수로 표현됨.
vector<double> ToSeconds(string s)
{
    vector<double> ans(2);
    double seconds = 0.00;
    int h = atoi(s.substr(0, 2).c_str());
    int m = atoi(s.substr(3, 2).c_str());
    double se = atof(s.substr(6, 6).c_str());
    double diff = atof(s.substr(13).c_str());

    ans[0] = ((3600 * h) + (60 * m) + se) - diff + 0.001;
    ans[1] = ((3600 * h) + (60 * m) + se);

    return ans;
}

int solution(vector<string> lines) {
    if (lines.size() <= 1) return lines.size();
    int answer = 0;
    vector<double> startTimes;
    vector<double> endTimes;

    for (int i = 0; i < lines.size(); ++i)
    {
        vector<double> v = ToSeconds(lines[i].substr(11));
        startTimes.push_back(v[0]);
        endTimes.push_back(v[1]);
        //cout.precision(3);
        //cout << fixed << startTimes[i] << " ~ " << endTimes[i] << endl;
    }

    sort(startTimes.begin(), startTimes.end());

    for (int i = 0; i < lines.size() - 1; ++i)
    {
        double end = endTimes[i] + 1;
        int count = 1;
        for (int j = i + 1; j < lines.size(); ++j)
        {
            if (startTimes[j] < end || endTimes[j] < end) count++;
            else break;
        }
        if (answer < count) answer = count;
    }

    return answer;
}