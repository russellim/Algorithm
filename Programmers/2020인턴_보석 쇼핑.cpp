// 21.05.03. 월
// kakao 2020인턴_보석 쇼핑 https://programmers.co.kr/learn/courses/30/lessons/67258
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> gemsID;
    int idCount = 0;
    int gemsSize = gems.size();

    // 보석 ID 만들기.
    for (int i = 0; i < gemsSize; ++i)
    {
        if (gemsID.find(gems[i]) == gemsID.end())
        {
            gemsID.insert({ gems[i], ++idCount });
        }
    }

    // 첫 구간 찾기 (제일 길고, 제일 앞에 있음).
    vector<int> gemsCounts(idCount + 1, 0);
    int start = 0, end = 0;
    int fullCount = 0;
    while (1)
    {
        int id = gemsID[gems[end]];
        if (gemsCounts[id] == 0) fullCount++;
        gemsCounts[id]++;
        if (end == gemsSize || fullCount == idCount) break;
        end++;
    }
    while (start != end)
    {
        int id = gemsID[gems[start]];
        if (gemsCounts[id] == 1) break;
        gemsCounts[id]--;
        start++;
    }
    answer = { start + 1, end + 1 };
    
    // 보석 수만큼의 구간이면 바로 반환.
    if (end - start + 1 == idCount) return answer;

    // 첫 구간보다 짧고(필수), 뒤에 있는 구간 찾기.
    // 더 짧은게 없으면 첫 구간이 반환됨.
    while (end != gemsSize - 1)
    {
        int endId = gemsID[gems[++end]];
        gemsCounts[endId]++;
        if (gemsCounts[endId] == 1) fullCount++;

        int startId = gemsID[gems[start++]];
        gemsCounts[startId]--;

        if (gemsCounts[startId] == 0) fullCount--;

        if (fullCount == idCount)
        {
            while (1)
            {
                int newStartId = gemsID[gems[start]];
                if (gemsCounts[newStartId] == 1) break;
                // 새로 찾은! 더 짧은! 구간.
                gemsCounts[newStartId]--;
                start++;
                answer = { start + 1, end + 1 };
                // 보석 수만큼의 구간이면 바로 반환.
                if (end - start + 1 == idCount) return answer;
            }

        }
    }
    return answer;
}