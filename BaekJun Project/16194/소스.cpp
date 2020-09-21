#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001];
int p[1001];

int solve(int x)
{
	if (x == 0) return 0;

	int &ret = dp[x];
	if (ret != 0x3f3f3f3f) return ret;

	for (int i = 1; i <= n; i++)
	{
		if (x - i < 0) break;
		ret = min(ret, solve(x-i) + p[i]);
	}

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	cout << solve(n);
	return 0;
}