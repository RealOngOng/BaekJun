#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
int cost[1001][1001];
int dp[1001];

int solve(int x)
{
	if (x == n) return 0;

	int &ret = dp[x];
	if (ret != -1) return ret;

	for (int i = x; i < n; i++)
		ret = max(ret, solve(i+1) + cost[x][i]);

	return ret;
} 

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		int lo = 0x3f3f3f3f, hi = 0;
		for (int j = i; j < n; j++)
		{
			lo = min(lo, arr[j]);
			hi = max(hi, arr[j]);

			cost[i][j] = hi - lo;
		}
	}

	cout << solve(0);
	return 0;
}
