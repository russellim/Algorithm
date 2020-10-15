// 20.10.15. 목
// 해시_전화번호 목록 https://programmers.co.kr/learn/courses/30/lessons/42577
// IDE 사용 금지.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool SizeSort(string a, string b)
{
    if (a.size() < b.size()) return true;
    else return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), SizeSort);
    int size = phone_book.size();
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (phone_book[j].substr(0, phone_book[i].size()) == phone_book[i]) return false;
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << solution({ "119", "97674223", "1195524421" }) << endl;
    cout << solution({ "123", "456", "789" }) << endl;
    cout << solution({ "12", "123", "1235", "567", "88" }) << endl;

    return 0;
}