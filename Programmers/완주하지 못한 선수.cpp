// 20.10.07. 수
// 완주하지 못한 선수  https://programmers.co.kr/learn/courses/30/lessons/42576
// Sort, 효율성 체크 있음, IDE 사용 금지!
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int csize = completion.size();
    answer = participant[participant.size() - 1];
    for (int i = 0; i < csize; ++i)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cout << solution({ "leo", "kiki", "eden" }, { "eden, kiki" }) << endl;
    cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl;
    cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl;

    return 0;
}