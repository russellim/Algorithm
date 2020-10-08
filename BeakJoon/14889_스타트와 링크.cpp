// 20.10.08. 목
// 14889: 스타트와 링크 https://www.acmicpc.net/problem/14889
// 백트래킹
#include <iostream>
#include <cmath>
using namespace std;
int arr[20][20];
bool visit[20];
int n;
int ans = 500;

void GetScore(int count, int cur)
{
	if (count == n / 2)
	{
		int a = 0, b = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (visit[i] && visit[j])
				{
					a += arr[i][j];
					a += arr[j][i];
				}
				else if (!visit[i] && !visit[j])
				{
					b += arr[i][j];
					b += arr[j][i];
				}
			}
		}
		ans = min(ans, abs(a - b));
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visit[i] && i > cur)
		{
			visit[i] = true;
			GetScore(cnt + 1, i);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
	GetScore(0, -1);
	cout << ans;
	return 0;
}