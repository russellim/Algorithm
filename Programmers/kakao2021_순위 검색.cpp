// 21.08.02. 월
// kakao 2021: 순위 검색 https://programmers.co.kr/learn/courses/30/lessons/72412
// map? 구현?

// 효율성 시간초과
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

namespace PROG_72412
{
	vector<string> _tempInfoArr;
	vector<vector<string> > _infoArr;

	/// string 빈칸 기준으로 자르기.
	vector<string> stringToken(string& str)
	{
		vector<string> tokens;
		stringstream ss;
		string res;
		ss.str(str);
		while (ss >> res) tokens.push_back(res);
		return tokens;
	}

	/// Array to String for index [0~3].
	string arrayToString(vector<string>& arr)
	{
		string str = "";
		for (int i = 0; i <= 3; ++i)
		{
			str += arr[i];
		}
		return str;
	}

	/// Array to String for index [0, 2, 4, 6]
	string arrayToString_forEven(vector<string>& arr)
	{
		string str = "";
		for (int i = 0; i <= 6; i += 2)
		{
			str += arr[i];
		}
		return str;
	}

	/// <summary>
	/// "-" 포함된 경우의 수 구하기
	/// </summary>
	/// <param name="arr">초기 배열</param>
	/// <param name="maxBarCount">최대 "-" 갯수</param>
	/// <param name="useBarCount">현재까지 사용한 "-"갯수</param>
	/// <param name="idx">시작할 인덱스</param>
	/// <param name="infoArrIdx">infoArr[Idx]</param>
	void makeCases(vector<string>& arr, int maxBarCount, int useBarCount, int idx, int infoArrIdx)
	{
		if (maxBarCount == useBarCount)
		{
			string str = arrayToString(_tempInfoArr);
			_infoArr[infoArrIdx].push_back(str);
			return;
		}

		for (int i = idx; i < 4; ++i)
		{
			if (maxBarCount - useBarCount > 4 - i) return;
			_tempInfoArr[i] = "-";
			makeCases(arr, maxBarCount, useBarCount + 1, i + 1, infoArrIdx);
			_tempInfoArr[i] = arr[i];
		}
	}

	vector<int> solution(vector<string> info, vector<string> query) {
		vector<int> answer;
		_infoArr.assign(info.size(), vector<string>());

		// info 경우의 수 구하기.
		for (int i = 0; i < info.size(); ++i)
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

		// 점수 내림차순으로 정렬.
		sort(_infoArr.begin(), _infoArr.end(), [](vector<string>& a, vector<string>& b) -> bool { return stoi(a[0]) > stoi(b[0]); });

		// 탐색 시작.
		for (int i = 0; i < query.size(); ++i)
		{
			int count = 0;
			auto arr = stringToken(query[i]);
			int indexScore = arr.size() - 1;
			int searchScore = stoi(arr[indexScore]); // 찾는 점수.
			string searchInfo = arrayToString_forEven(arr); // 찾는 정보.

			// string 경우의수로 만든 정보들 탐색.
			for (auto& infos : _infoArr)
			{
				if (stoi(infos[0]) < searchScore) break; // 점수가 찾는 점수보다 낮으면 끝.
				for (int infoIdx = 1; infoIdx < infos.size(); ++infoIdx)
				{
					if (infos[infoIdx] == searchInfo)
					{
						count++;
						break;
					}
				}
			}
			answer.push_back(count);
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

		for (auto x : answer) cout << x << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	PROG_72412::Solution();

	return 0;
}
