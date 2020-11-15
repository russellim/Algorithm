// 20.11.15. 일
// 10814: 나이순 정렬 https://www.acmicpc.net/problem/10814
// stable_sort
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Member
{
	int age;
	string name;
	Member(int age, string name) : name(name), age(age) {}
	bool operator<(const Member& m) const { return age < m.age; } // 정렬시 나이만 고려함.
};

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	vector<Member> members;
	int n;
	cin >> n;
	while (n--)
	{
		int age; string name;
		cin >> age >> name;
		members.push_back(Member(age, name));
	}
	// 나이가 같으면 순서가 유지됩니다.
	stable_sort(members.begin(), members.end());

	for (auto& x : members)
		cout << x.age << " " << x.name << "\n";

	return 0;
}