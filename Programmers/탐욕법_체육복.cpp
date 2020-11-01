// 20.11.01. 일
// 탐욕법_체육복 https://programmers.co.kr/learn/courses/30/lessons/42862
// 해시, IDE 사용 금지.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    if (lost == reserve) return n;

    int answer = 0;

    // 오름차순이 아닐경우, 답이 제대로 안나올 수 있음!.
    // 예) 7 [3,5] [4,2].
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    map<int, int>m; // 번호, 가지고있는 체육복 수.

    // 여벌있으면+1, 도둑맞았으면-1.
    for (int i = 0; i < n; ++i) m.insert({ i + 1, 1 });
    for (int i = 0; i < reserve.size(); ++i) m[reserve[i]]++;
    for (int i = 0; i < lost.size(); ++i) m[lost[i]]--;

    for (int i = 1; i <= n; ++i)
    {
        if (m[i] == 0)
        {
            if (m[i - 1] == 2) m[i - 1]--;
            else if (m[i + 1] == 2) m[i + 1]--;
            else continue;
            answer++;
        }
        else answer++;
    }

    return answer;
}

// 밑에는 빛나는 실패작들.
//int solution(int n, vector<int> lost, vector<int> reserve) {
//    int answer = 0;
//
//    sort(lost.begin(), lost.end());
//    sort(reserve.begin(), reserve.end());
//
//    for (int i = 0; i < reserve.size(); ++i)
//    {
//        auto it = find(lost.begin(), lost.end(), reserve[i]);
//        if (it != lost.end())
//        {
//            lost.erase(it);
//            reserve.erase(reserve.begin() + i);
//            i--;
//            continue;
//        }
//
//        it = find(lost.begin(), lost.end(), reserve[i] - 1);
//        if (it != lost.end())
//        {
//            if (find(reserve.begin(), reserve.end(), reserve[i] - 1) == reserve.end())
//            {
//                lost.erase(it);
//                continue;
//            }
//        }
//        it = find(lost.begin(), lost.end(), reserve[i] + 1);
//        if (it != lost.end())
//        {
//            if (find(reserve.begin(), reserve.end(), reserve[i] - 1) == reserve.end())
//            {
//                lost.erase(it);
//            }
//        }
//    }
//    answer = n - lost.size();
//    return answer;
//}
//
//
//
//int solution(int n, vector<int> lost, vector<int> reserve) {
//    int answer = 0;
//
//    vector<int> tLost(lost.size());
//    vector<int> tReserve(reserve.size());
//
//    auto it = set_difference(lost.begin(), lost.end(), reserve.begin(), reserve.end(), tLost.begin());
//    tLost.erase(it, tLost.end());
//    it = set_difference(reserve.begin(), reserve.end(), lost.begin(), lost.end(), tReserve.begin());
//    tReserve.erase(it, tReserve.end());
//
//    sort(tLost.begin(), tLost.end());
//    sort(tReserve.begin(), tReserve.end());
//
//    for (int i = 0; i < tReserve.size(); ++i)
//    {
//        it = find(tLost.begin(), tLost.end(), tReserve[i] - 1);
//        if (it != tLost.end())
//        {
//            tLost.erase(it);
//            continue;
//        }
//        it = find(tLost.begin(), tLost.end(), tReserve[i] + 1);
//        if (it != tLost.end())
//        {
//            tLost.erase(it);
//        }
//    }
//    answer = n - tLost.size();
//    return answer;
//}