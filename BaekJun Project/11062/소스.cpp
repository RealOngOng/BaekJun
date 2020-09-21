#include <bits/stdc++.h>

using namespace std;

int n;
int c[1001];
int dp[1001][1001][2];

int solve(int s, int e, bool k)
{
	if (s > e) return 0;

	int &ret = dp[s][e][k];
	if (ret != -1) return ret;

	if (!k)
	{
		ret = max(ret, solve(s+1, e, !k) + c[s]);
		ret = max(ret, solve(s, e-1, !k) + c[e]);
	}
	else
	{
		ret = 0x3f3f3f3f;
		ret = min(ret, solve(s + 1, e, !k));
		ret = min(ret, solve(s, e - 1, !k));
	}

	return ret;
}

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		memset(c, 0, sizeof(c));
		memset(dp, -1, sizeof(dp));

		cin >> n;
		for (int i = 0; i < n; i++) cin >> c[i];

		cout << solve(0, n - 1, false) << "\n";
	}
	return 0;
}