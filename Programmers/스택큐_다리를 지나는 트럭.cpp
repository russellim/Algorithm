// 20.11.02.
// 스택/큐_다리를 지나는 트럭 https://programmers.co.kr/learn/courses/30/lessons/42583
// Queue. IDE 사용 금지.
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    if (truck_weights.size() == 1) return bridge_length + 1;

    int answer = 0;
    queue<pair<int, int> > pass;    // 트럭 무게, 들어간 시간.
    int nowW;

    // 첫번째 트럭.
    pass.push({ truck_weights[0], answer });
    nowW = truck_weights[0];
    answer++;

    // 두번째 트럭부터 일단 다 들어갈때까지.
    for (int i = 1; i < truck_weights.size(); ++i)
    {
        // 건널 시간 되면 빠져.
        if (answer - pass.front().second == bridge_length)
        {
            nowW -= pass.front().first;
            pass.pop();
        }

        // 더 들어갈 수 있으면 들어가세여.
        if (weight >= nowW + truck_weights[i])
        {
            pass.push({ truck_weights[i], answer });
            nowW += truck_weights[i];
        }
        else --i; // 못들어가면 앞에 추럭 빠질때까지 기다려야돼.
        answer++;
    }

    // 트럭 다 들어간 다음에는 다 빠질 때까지 시간돌려돌려.
    while (!pass.empty())
    {
        if (answer - pass.front().second == bridge_length)
        {
            nowW -= pass.front().first;
            pass.pop();
        }
        answer++;
    }


    return answer;
}