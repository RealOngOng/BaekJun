#include <bits/stdc++.h>

using namespace std;

int dp[31][31];
int solve(int n, int r)
{
	if (n == r || r == 0) return 1;

	int &ret = dp[n][r];
	if (ret != -1) return ret;
	
	return ret = solve(n - 1, r - 1) + solve(n - 1, r);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int n, r; cin >> n >> r;
	cout << solve(n - 1, r - 1);
	return 0;
}