// 20.10.17. 토
// kakao2019_실패율 https://programmers.co.kr/learn/courses/30/lessons/42889
// lower_bound, upper_bound. IDE 사용 금지.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, double> T; // (스테이지, 실패율).

bool SortFailed(T& a, T& b)
{
    if(a.second == b.second)
    {
        if(a.first < b.first) return true;
        return false;
    }
    if(a.second > b.second) return true;
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<T>failed;
    int size = stages.size();
    sort(stages.begin(), stages.end());
    for(int i=1; i<=N; ++i)
    {
        // 스테이지 클리어 상태 개수.
        int PlayingCount = (upper_bound(stages.begin(), stages.end(), i) - stages.begin()) - 
                    (lower_bound(stages.begin(), stages.end(), i) - stages.begin());
        
        if(size == 0)   // 스테이지에 아무도 도달 안한 경우. 중요!.
        {
            failed.push_back({i, 0});
            continue;
        }
        failed.push_back({i, (double)PlayingCount/(double)size});
        size -= PlayingCount;
    }
    
    // 실패율 정렬.
    sort(failed.begin(), failed.end(), SortFailed);
    
    for(auto& x: failed) answer.push_back(x.first);
    
    return answer;
}