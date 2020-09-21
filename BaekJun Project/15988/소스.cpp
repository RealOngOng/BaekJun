#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 9;

ll dp[1000001];
ll solve(ll x)
{
	if (x == 0) return 1;

	ll &ret = dp[x];
	if (ret != -1) return ret;

	ret = 0;
	ret += solve(x - 1) % MOD;
	ret %= MOD;

	ret += solve(x - 2) % MOD;
	ret %= MOD;

	ret += solve(x - 3) % MOD;
	ret %= MOD;
	
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	int tc; cin >> tc;

	while (tc--)
	{
		ll n; cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}