// 20.12.03. 목
// 1011: Fly me to the Alpha Centauri https://www.acmicpc.net/problem/1011
// Math.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, dist;
        cin >> x >> y;

        dist = y - x;

        int sq = floor(sqrt(dist));
        if (sqrt(dist) != sq) sq++;

        if ((pow(sq - 1, 2) + pow(sq, 2)) / 2 < dist)
            cout << sq * 2 - 1 << "\n";
        else
            cout << sq * 2 - 2 << "\n";
    }

    return 0;
}

/*
거리	작동	sqrt(거리)
---------------------------
 1		 1		 1
 ---------------------------
 2		 2
 3		 3*
 4		 3		 2
 ---------------------------
 5		 4
 6		 4
 7		 5*
 8		 5
 9		 5		 3
 ---------------------------
 10		 6
 11		 6
 12		 6
 13		 7*
 14		 7
 15		 7
 16		 7		 4
 ---------------------------
 17		 8
*/