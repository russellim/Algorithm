// 20.10.18. 일
// kakao2020인턴_키패드 누르기 https://programmers.co.kr/learn/courses/30/lessons/67256
// IDE 사용 금지.
#include <string>
#include <vector>

using namespace std;

// 이동 횟수 구하는 함수.
int MoveCount(int key, int current)
{
    int moveCount = 0;
    // 내려가거나, 올라가기 (+- 3).
    while(!(key-1 <= current && key+1 >= current))
    {
        if(current > key) current -= 3;
        else current += 3;
        moveCount++;
    }
    // 바로 옆에 있다는 의미로 한칸 더 이동해줘야 됨.
    if(key != current) moveCount++;
    return moveCount;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;  // *(10), 0(11), #(12).
    
    for(int i=0; i < numbers.size(); ++i)
    {
        int num = numbers[i];
        
        // 0 때문에 먼저 if로 걸러줘야 한다.
        if(num % 3 == 2 || num == 0)
        {
            if(num == 0) num = 11;
            if(MoveCount(num, left) > MoveCount(num, right))
            { 
                right = num;
                answer += "R";
            }
            else if(MoveCount(num, left) < MoveCount(num, right))
            {
                left = num;
                answer += "L";
            }
            else
            {
                if(hand[0] == 'r')
                {
                    right = num;
                    answer += "R";
                }
                else
                {
                    left = num;
                    answer += "L";
                }
            }
        }
        else if(num % 3 == 1)   // 1,4,7.
        {
            left = num;
            answer += "L";
        }
        else                    // 3,6,9.
        {
            right = num;
            answer += "R";
        }
    }
    return answer;
}