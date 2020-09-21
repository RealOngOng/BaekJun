#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001][4];
int dp[1001][4][4];

int solve(int pos, int first, int prev)
{
	if (pos == n) return 0;

	int &ret = dp[pos][first][prev];
	if (ret != 0x3f3f3f3f) return ret;

	for (int i = 1; i <= 3; i++)
	{
		if (pos == n - 1 && i == first) continue;
		if (i == prev) continue;
		ret = min(ret, solve(pos + 1, first, i) + arr[pos][i]);
	}

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];

	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= 3; i++)
		ans = min(ans, solve(1, i, i) + arr[0][i]);

	cout << ans;
	return 0;
}