// 21.08.02. 월
// kakao 2021: 순위 검색 https://programmers.co.kr/learn/courses/30/lessons/72412
// map? 구현?

// 푸는중.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

namespace PROG_72412
{
	vector<string> _tempInfoArr;
	vector<vector<string> > _infoArr;

	// string 빈칸 기준으로 자르기.
	// ***그럼 " and "는 어떻게?
	vector<string> stringToken(string str)
	{
		vector<string> tokens;
		stringstream ss;
		string res;
		ss.str(str);
		while (ss >> res) tokens.push_back(res);
		return tokens;
	}

	string arrayToString(vector<string> arr)
	{
		string str = "";
		for (int i = 0; i <= 3; ++i)
		{
			str += arr[i];
		}
		return str;
	}

	void makeCases(vector<string>& arr, int maxBarCount, int useBarCount, int idx, int insertIdx)
	{
		if (maxBarCount == useBarCount)
		{
			string str = arrayToString(_tempInfoArr);
			_infoArr[insertIdx].push_back(str);
			cout << str << endl;
			return;
		}

		// *** 여기 고칠것.
		for (int i = idx; i < 4; ++i)
		{
			if (maxBarCount - useBarCount > 4 - i) return;
			_tempInfoArr[i] = "-";
			makeCases(arr, maxBarCount, useBarCount + 1, idx + 1, insertIdx);
			_tempInfoArr[i] = arr[i];
		}
	}

	vector<int> solution(vector<string> info, vector<string> query) {
		vector<int> answer;
		_infoArr.assign(info.size(), vector<string>());

		// info 경우의 수 구하기.
		for (int i=0; i<info.size(); ++i)
		{
			auto arr = stringToken(info[i]);
			_tempInfoArr = arr;
			_infoArr[i].push_back(_tempInfoArr[4]);
			_infoArr[i].push_back(arrayToString(arr));
			for (int barCount = 1; barCount <= 4; ++barCount)
			{
				makeCases(arr, barCount, 0, 0, i);
			}
		}

		for (auto x : _infoArr)
		{
			for (auto y : x)
			{
				cout << y << endl;
			}
			cout << endl << endl;
		}

		return answer;
	}

	void Solution()
	{
		auto answer = solution({ 
			"java backend junior pizza 150",
			"python frontend senior chicken 210",
			"python frontend senior chicken 150",
			"cpp backend senior pizza 260",
			"java backend junior chicken 80",
			"python backend senior chicken 50" },

			{ "java and backend and junior and pizza 100",
			"python and frontend and senior and chicken 200",
			"cpp and - and senior and pizza 250",
			"- and backend and senior and - 150",
			"- and - and - and chicken 100",
			"- and - and - and - 150" });
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	PROG_72412::Solution();

	return 0;
}
