#include <bits/stdc++.h>

using namespace std;

int len;
int n;
int arr[21];
int dp[21][21][21];

int solve(int pos, int a, int b)
{
	if (pos == n) return 0;

	int &ret = dp[pos][a][b];
	if (ret != 0x3f3f3f3f) return ret;

	int now = arr[pos];

	ret = min(ret, solve(pos + 1, now, b) + abs(a - now));
	ret = min(ret, solve(pos + 1, a, now) + abs(b - now));

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));

	cin >> len;
	int a, b; cin >> a >> b;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << solve(0, a, b);
	return 0;
}