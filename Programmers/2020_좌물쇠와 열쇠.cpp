// 20.11.03. 화
// kakao 2020_좌물쇠와 열쇠 https://programmers.co.kr/learn/courses/30/lessons/60059
// 구현. IDE 사용 금지.
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// key 90도씩 돌리는 함수.
vector<vector<int> > TurnKey(vector<vector<int> >& key)
{
    auto temp = key;
    for (int i = 0; i < key.size(); ++i)
    {
        for (int j = 0; j < key.size(); ++j)
        {
            temp[j][key.size() - i - 1] = key[i][j];
        }
    }
    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int pansize = 2 * key.size() + lock.size() - 2;
    int moveX = 0, moveY = 0;
    int turn = 4;

    // 왕큰판 가운데에 lock 놓기.
    vector<vector<int> > pan(pansize, vector<int>(pansize, 0));
    for (int i = 0; i < lock.size(); ++i)
    {
        for (int j = 0; j < lock.size(); ++j)
        {
            pan[i + key.size() - 1][j + key.size() - 1] = lock[i][j];
        }
    }
    auto store = pan; // 초기화를 위한 저장.

    while (turn--)
    {
        for (int moveX = 0; moveX <= pansize - key.size(); ++moveX)
        {
            for (int moveY = 0; moveY <= pansize - key.size(); ++moveY)
            {
                // key pan[0][0]부터 이동한 위치만큼 놓습니다.
                // 그냥 놓음 안되고 겹치는지 확인해야하니 연산해야됨!
                for (int i = 0; i < key.size(); ++i)
                {
                    for (int j = 0; j < key.size(); ++j)
                    {
                        pan[i + moveX][j + moveY] += key[i][j];
                    }
                }

                bool noMatch = false;
                // lock 놓은 부분만 확인합니다. 
                // 한자리라도 2(겹침)나 0(빈자리) 되면 안맞는거니까 바로 break.
                for (int i = 0; i < lock.size(); ++i)
                {
                    for (int j = 0; j < lock.size(); ++j)
                    {
                        if (pan[i + key.size() - 1][j + key.size() - 1] == 2 || pan[i + key.size() - 1][j + key.size() - 1] == 0)
                        {
                            noMatch = true;
                            break;
                        }
                    }
                    if (noMatch) break;
                }
                if (!noMatch) return true; // 안맞는거 없이 빠져나오면 끝!.

                pan = store; // 왕큰판 초기화.
            }
        }
        if (turn != 0) key = TurnKey(key); // key 돌려!.
    }

    return false;
}