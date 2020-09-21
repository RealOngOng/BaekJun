#include <bits/stdc++.h>

using namespace std;

int n, m, s, e, t;

int dp[3001][3001];
int cost[3001][3001];
int sum[3001][3001];

int no[3001];

int GetSum(int sx, int sy, int ex, int ey)
{
	sx++, sy++, ex++, ey++;
	return sum[ex][ey] - sum[sx - 1][ey] - sum[ex][sy - 1] + sum[sx - 1][sy-1];
}

int solve(int pos, int now)
{
	if (pos >= n) return 0;

	int &ret = dp[pos][now];
	if (ret != 0x3f3f3f3f) return ret;

	for (int i = pos + s; i <= pos + e; i++)
	{
		ret = min(ret, solve(i, now) + GetSum(now, pos, now, i));
		
		for (int j = 0; j < n; j++)
		{
			if (no[j] == now) continue;
			ret = min(ret, solve(i, j) + GetSum(now, pos, now, i) + t);
		}
	}

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));

	cin >> n >> m >> s >> e >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> cost[i][j];
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + cost[i][j];
		}

	for (int i = 0; i < n; i++)
		cin >> no[i];

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
		ans = min(ans, solve(0, i));

	cout << ans;
	return 0;
}