#include <bits/stdc++.h>

using namespace std;

int n, m;

int dp[101][101];
int arr[101], s[101];

int sum(int l, int r) { return s[r + 1] - s[l]; }

int solve(int x, int k)
{
	if (k == m) return 0;
	if (x >= n) return -0x3f3f3f3f+1;

	int &ret = dp[x][k];
	if (ret != -0x3f3f3f3f) return ret;

	ret = max(ret, solve(x+1, k));
	for (int i = x; i < n; i++)
		ret = max(ret, solve(i+2, k + 1) + sum(x, i));

	return ret;
}

int main()
{
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			dp[i][j] = -0x3f3f3f3f;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		s[i + 1] = s[i] + arr[i];
	}

	cout << solve(0, 0);
	return 0;
}