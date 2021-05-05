// 21.05.05. 수
// 2021데브매칭_로또의 최고 순위와 최저 순위 https://programmers.co.kr/learn/courses/30/lessons/77484
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int lottoSize = 6;
    vector<bool> numbers(45 + 1);
    vector<int> ranks(lottoSize + 1, 6);

    // 등수 저장.
    for (int i = 2; i <= lottoSize; ++i)
    {
        ranks[i] = 7 - i;
    }

    // win로또 번호 저장.
    for (int i = 0; i < lottoSize; ++i)
    {
        numbers[win_nums[i]] = true;
    }

    // 0, 맞은 번호 저장.
    int zeroCnt = 0;
    int correctCnt = 0;
    for (int i = 0; i < lottoSize; ++i)
    {
        if (lottos[i] == 0) zeroCnt++;
        else if (numbers[lottos[i]]) correctCnt++;
    }

    answer = { ranks[correctCnt + zeroCnt], ranks[correctCnt] };

    return answer;
}