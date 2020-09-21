//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//const ll MOD = 1000000000 + 7;
//
//int n, a, b;
//ll dp[101][101][101];
//
//ll solve(int l, int r, int k)
//{
//	if (k == n)
//		return (l == a && r == b);
//
//	ll &ret = dp[l][r][k];
//	if (ret != -1) return ret;
//
//	ret = 0;
//	ret += solve(l + 1, r, k + 1) % MOD +
//		solve(l, r + 1, k + 1) % MOD +
//		(solve(l, r, k + 1) % MOD * (k - 1)) % MOD;
//
//	return ret % MOD;
//}
//
//int main()
//{
//	memset(dp, -1, sizeof(dp));
//	cin >> n >> a >> b;
//
//	cout << solve(1, 1, 1) % MOD;
//	return 0;
//}