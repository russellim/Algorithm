// 20.12.09. 수
// kakao 2019인턴_징검다리 건너기 https://programmers.co.kr/learn/courses/30/lessons/64062
// 이분탐색.

// 답을 미리 정해놓고 (1~최대값) 이분탐색
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int>& v, int mid, int k)
{
    int jump = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] - mid <= 0) jump++;
        else jump = 0;

        if (jump >= k) return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    if (k == 1) return *min_element(stones.begin(), stones.end());

    int start = 1, end = *max_element(stones.begin(), stones.end());

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (binarySearch(stones, mid, k))
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start;
}