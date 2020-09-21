#include <bits/stdc++.h>

using namespace std;

const int MOD = 9901;

int n, m;
int dp[16][(1 << 14) + 1];

int solve(int line, int state);

void dfs(int line, int state, int x, int now)
{
	//±âÀú »ç·Ê
	if (x >= m)
	{
		dp[line][state] += solve(line + 1, now) % MOD;
		dp[line][state] %= MOD;
		return;
	}

	if (state & (1 << x))
		dfs(line, state, x + 1, now);
	else
	{
		dfs(line, state, x + 1, now | (1 << x));

		if (!(state & (1 << (x + 1))) && (x + 1) < m)
			dfs(line, state, x + 2, now);
	}
}

int solve(int line, int state)
{
	if (line == n)
		return (state == 0);

	int &ret = dp[line][state];
	if (ret != -1) return ret;

	ret = 0;
	dfs(line, state, 0, 0);

	return ret % MOD;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	cout << solve(0, 0) % MOD;
	return 0;
}