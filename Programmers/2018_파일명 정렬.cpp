// 20.10.26. 월
// kakao 2018_파일명 정렬 https://programmers.co.kr/learn/courses/30/lessons/17686
// stable_sort. IDE 사용 금지!

// stable_sort: 구조체 같은 여러 값들이 묶여 있는것을 하나의 요소로 정렬을 했을 때,
//              다른 요소들의 정렬 순서도 정렬 전과 같이 그대로 유지 될 수 있도록 하는 정렬.
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct filename
{
    string head = "";
    string number = "";
    string tail = "";
};

// 정렬에 사용할 비교 함수.
bool cmp(const filename& a, const filename& b)
{
    // 대소문자 구분 없음.
    string st1 = a.head, st2 = b.head;
    for (char& c : st1) c = tolower(c);
    for (char& c : st2) c = tolower(c);
    if (st1 != st2) return st1 < st2;

    // 00001 == 1.
    int temp1 = atoi(a.number.c_str()), temp2 = atoi(b.number.c_str());
    if (temp1 != temp2) return temp1 < temp2;

    return false;
}

vector<string> solution(vector<string> files) {
    if (files.size() == 1) return files;
    vector<string> answer;
    vector<filename> f;

    for (int i = 0; i < files.size(); ++i)
    {
        filename makef;
        int pivot, size = 0; // 문자열 자를 구간(pivot), 자른 사이즈(size).
        for (int j = 0; j < files[i].size(); ++j)
        {
            size++;
            // head 찾기(항상 문자니까 숫자 나오면 그 전까지 head).
            if (makef.head == "" && isdigit(files[i][j]))
            {
                makef.head = files[i].substr(0, size - 1);
                pivot = j;
                size = 0;
            }
            // number 찾기(5자 이상되면 탐색끝).
            if (makef.head != "" && isdigit(files[i][j]) && size == 5)
            {
                makef.number = files[i].substr(pivot, size);
                pivot = j;
                break;
            }
            // number 찾기(5자 이하로 끝났을때).
            if (makef.head != "" && !isdigit(files[i][j]))
            {
                makef.number = files[i].substr(pivot, size);
                pivot = j;
                break;
            }
        }
        // tail이 없는 문자열은 나머지가 number.
        if (makef.number == "")
        {
            makef.number = files[i].substr(pivot);
        }
        // 남는부분은 다 tail.
        else
        {
            makef.tail = files[i].substr(pivot);
        }
        f.push_back(makef);
    }

    // @!!!!!중요!!!!!@ sort만 하면 불안정 정렬이라 틀린다.
    stable_sort(f.begin(), f.end(), cmp);

    for (auto& x : f)
    {
        string temp = x.head + x.number + x.tail;
        answer.push_back(temp);
    }

    return answer;
}