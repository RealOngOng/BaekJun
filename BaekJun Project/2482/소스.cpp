#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1000000000 + 3;

int n, k;
ll dp[1001][1001][2];

ll solve(int pos, int cnt, bool first)
{
	if (cnt >= k) return 1;
	if (pos > n) return 0;

	ll &ret = dp[pos][cnt][first];
	if (ret != -1) return ret;

	ret = 0;
	if (pos != n)
		ret += solve(pos + 1, cnt, first) % MOD + solve(pos + 2, cnt + 1, first) % MOD;
	else
	{
		if (first)
			ret += solve(pos + 1, cnt, first) % MOD;
		else
			ret += solve(pos + 1, cnt, first) % MOD + solve(pos + 2, cnt + 1, first) % MOD;
	}

	return ret % MOD;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n >> k;

	cout << (solve(2, 0, false) % MOD + solve(3, 1, true) % MOD) % MOD;
	return 0;
}