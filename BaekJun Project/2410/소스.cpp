#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int n;
int dp[1000001][21];
int pw[21];

int solve(int x, int k)
{
	if (x == n) return 1;
	if (x > n || k >= 19) return 0;

	int &ret = dp[x][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= 20; i++)
	{
		if (k + i >= 20) break;
		ret += solve(x + pw[k + i], k + i) % MOD;
		ret %= MOD;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n;

	pw[0] = 1;
	for(int i=1; i <= 20; i++)
		pw[i] = (pw[i - 1] * 2) % MOD;

	cout << solve(0, 0) % MOD;
	return 0;
}