// 21.02.17. 수
// 7662: 이중 우선순위 큐 https://www.acmicpc.net/problem/7662
// Heap. long long 주의.
// 참고: https://www.acmicpc.net/board/view/57305
#include <iostream>
#include <queue>

using namespace std;

namespace BOJ_7662
{
	class DeletableHeap
	{
	public:
		void Add(long long num)
		{
			data.push(num);
		}
		void Remove(long long num)
		{
			deleted.push(num);
		}
		long long Top()
		{
			Adjust();
			return data.top();
		}
		int Size()
		{
			return data.size();
		}
		void Adjust()
		{
			while (deleted.size() > 0 && data.top() == deleted.top())
			{
				data.pop();
				deleted.pop();
			}
		}
	private:
		priority_queue<long long> data;
		priority_queue<long long> deleted;
	};

	DeletableHeap maxH, minH, emptyH;

	void InsertH(long long num)
	{
		maxH.Add(num);
		minH.Add(-num);
	}

	void DeleteH(long long num)
	{
		long long top;
		if (num == 1)
		{
			if (maxH.Size() == 0) return;
			top = maxH.Top();
			maxH.Remove(top);
			minH.Remove(-top);
			maxH.Adjust();
			minH.Adjust();
		}
		else
		{
			if (minH.Size() == 0) return;
			top = minH.Top();
			minH.Remove(top);
			maxH.Remove(-top);
			minH.Adjust();
			maxH.Adjust();
		}
	}

	void InitH()
	{
		maxH = minH = emptyH;
	}

	void Solution()
	{
		int t, k;
		long long num;
		string cmd;
		cin >> t;
		while (t--)
		{
			cin >> k;
			while (k--)
			{
				cin >> cmd >> num;
				if (cmd == "I")
				{
					InsertH(num);
				}
				else
				{
					DeleteH(num);
				}
			}
			maxH.Adjust();
			minH.Adjust();
			if (maxH.Size() == 0) cout << "EMPTY\n";
			else cout << maxH.Top() << " " << -minH.Top() << "\n";
			if (t != 0) InitH();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_7662::Solution();

	return 0;
}