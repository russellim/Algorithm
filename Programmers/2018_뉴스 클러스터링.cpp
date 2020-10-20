// 20.10.20. 화
// kakao 2018_뉴스 클러스터링  https://programmers.co.kr/learn/courses/30/lessons/17677
// 합집합, 교집합. IDE 사용 금지!
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 길이 2의 string으로 이뤄진 부분집합 벡터로 만듦.
vector<string> StringToVector2(const string& s)
{
    vector<string> v;
    string temp;
    for (int i = 0; i < s.size(); ++i)
    {
        // 알파벳 아니면 거르는걸로.
        if (!isalpha(s[i]))
        {
            temp = "";
            continue;
        }
        temp += toupper(s[i]);
        if (temp.size() == 2)
        {
            v.push_back(temp);
            temp = "";
            i--;
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1, v2, uni, inter;

    v1 = StringToVector2(str1);
    v2 = StringToVector2(str2);

    // 합집합, 교집합 넣어줄 벡터 사이즈 미리 만들어두고.
    uni.resize(v1.size() + v2.size());
    inter.resize(v1.size() + v2.size());

    // 다 넣으면 남는 칸 삭제하는거 잊지마! (용량, 정확한 벡터 사이즈).
    auto it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), uni.begin());
    uni.erase(it, uni.end());
    it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inter.begin());
    inter.erase(it, inter.end());

    if (inter.size() == 0 && uni.size() == 0) return 65536;

    answer = (double)inter.size() / uni.size() * 65536;

    return answer;
}