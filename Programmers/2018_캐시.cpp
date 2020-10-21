// 20.10.21. 수
// kakao 2018_캐시 https://programmers.co.kr/learn/courses/30/lessons/17680
// LRU(Least Recently Used). IDE 사용 금지!
// 가장 적게 사용된것 삭제하는 알고리즘.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return cities.size() * 5;
    if (cities.size() == 0) return 0;

    vector<string> cache;
    int answer = 0;

    // 첫번째 도시 미리 넣어줌. 왜냐! 밑에서 검색할거니까.
    for (char& x : cities[0]) x = tolower(x);
    cache.push_back(cities[0]);
    answer += 5;

    for (int i = 1; i < cities.size(); ++i)
    {
        string s = cities[i];
        for (char& x : s) x = tolower(x);   // 대소문자 구분 없음.

        auto it = find(cache.begin(), cache.end(), s);
        if (it != cache.end())
        {
            // 캐시에 있음. Hit.
            // 캐시 삭제. (제일 최근으로 옮길것).
            cache.erase(it);
            answer += 1;
        }
        else
        {
            // 캐시에 없음. Miss.
            if (cache.size() >= cacheSize)
            {  
                // 캐시가 다 찼으면 제일 오래전 캐시 삭제.
                cache.erase(cache.begin());
            }
            answer += 5;
        }
        // 업데이트.
        cache.push_back(s);
    }

    return answer;
}