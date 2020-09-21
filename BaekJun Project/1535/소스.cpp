#include <bits/stdc++.h>

using namespace std;

int n;
int p[21], q[21];
int dp[21][101];

int solve(int pos, int hp)
{
	if (pos == n) return 0;

	int &ret = dp[pos][hp];
	if (ret != -1) return ret;

	ret = max(ret, solve(pos+1, hp));

	if (hp - p[pos] > 0)
		ret = max(ret, solve(pos +1, hp - p[pos]) + q[pos]);

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> q[i];

	cout << solve(0, 100);
	return 0;
}