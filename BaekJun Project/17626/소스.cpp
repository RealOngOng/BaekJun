#include <bits/stdc++.h>

using namespace std;

int n;
int dp[50001];

int solve(int x)
{
	if (x == 0) return 0;

	int &ret = dp[x];
	if (ret != 0x3f3f3f3f) return ret;

	for (int i = 1; i <= 256; i++)
	{
		if (x - i * i < 0) break;
		ret = min(ret, solve(x - i * i) + 1);
	}

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	cin >> n;
	cout << solve(n);
	return 0;
}