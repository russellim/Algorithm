// 21.03.20. 토
// 완전탐색_카펫 https://programmers.co.kr/learn/courses/30/lessons/42842
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for(int i=sum; i >= 0; --i)
    {
        if(sum % i != 0) continue;
        int div = sum/i;
        if(i-2 <= 0 || div-2 <= 0 ) continue;
        if((i-2) * (div-2) == yellow)
        {
            answer = {i, div};
            break;
        }
    }
    
    return answer;
}