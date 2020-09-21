#include <bits/stdc++.h>

using namespace std;

int n, m;

int dp[10001][101];
int p[101], cnt[101];

int solve(int x, int k)
{
	if (x == 0) return 1;
	if (k >= m) return 0;

	int &ret = dp[x][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= cnt[k]; i++)
	{
		if (x - p[k] * i < 0) break;
		ret += solve(x-p[k] * i, k + 1);
	}

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> p[i] >> cnt[i];

	cout << solve(n, 0);
	return 0;
}