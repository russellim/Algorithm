// 20.10.10. 토
// 월간 코챌1: 두 개 뽑아서 더하기  https://programmers.co.kr/learn/courses/30/lessons/68644
// Set
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;

    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            s.insert(numbers[i] + numbers[j]);
        }
    }

    answer.assign(s.begin(), s.end());

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    vector<int> v;
    v = solution({ 2,1,3,4,1 });
    for (auto& x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v = solution({ 5,0,2,7 });
    for (auto& x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}