#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;

int n;
int dp[1001][3][4];

int solve(int day, int a, int b)
{
	if (day == n) return 1;

	int &ret = dp[day][a][b];
	if (ret != -1) return ret;

	ret = 0;
	ret += solve(day+1, a, 0) % MOD;
	ret %= MOD;

	if (a < 1)
	{
		ret += solve(day + 1, a + 1, 0) % MOD;
		ret %= MOD;
	}

	if (b < 2)
	{
		ret += solve(day + 1, a, b + 1) % MOD;
		ret %= MOD;
	}

	return ret % MOD;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	cout << solve(0, 0, 0) % MOD;
	return 0;
}