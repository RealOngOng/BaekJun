#include <bits/stdc++.h>

using namespace std;

struct Pair
{
	int x, y;
	Pair() {}
	Pair(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	Pair operator+(const Pair& p)
	{
		return Pair(x + p.x, y + p.y);
	}
};

Pair dp[31];

int main()
{
	dp[1] = { 1, 0 };
	dp[2] = { 0, 1 };
	
	for (int i = 3; i <= 30; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int d, k; cin >> d >> k;

	for (int i = 1; i <= 100000; i++)
	{
		if ((k - dp[d].x * i) % dp[d].y == 0)
		{
			cout << i << "\n" << (k - dp[d].x * i) / dp[d].y;
			break;
		}
	}
	return 0;
}