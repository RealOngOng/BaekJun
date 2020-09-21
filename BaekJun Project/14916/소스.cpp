#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int solve(int x)
{
	if (x == 0) return 0;

	int &ret = dp[x];
	if (ret != 0x3f3f3f3f) return ret;

	if(x - 2 >= 0)
		ret = min(ret, solve(x - 2) + 1);

	if(x-5 >= 0)
		ret = min(ret, solve(x - 5) + 1);

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	int n; cin >> n;

	int ans = solve(n);
	if (ans == 0x3f3f3f3f) cout << "-1";
	else cout << ans;
	return 0;
}