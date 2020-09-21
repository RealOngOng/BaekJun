#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007LL;

int n;
ll dp[2501];

int main()
{
	dp[0] = 1;
	for (int i = 1; i <= 2500; i++)
	{
		ll &ret = dp[i];
		for (int j = 0; j < i; j++)
		{
			ret += (dp[j] % MOD * dp[i - j - 1] % MOD) % MOD;
			ret %= MOD;
		}
	}

	int tc; cin >> tc;
	while (tc--)
	{
		int n; cin >> n;
		if (n % 2 == 1) cout << "0\n";
		else
			cout << dp[n / 2] % MOD << "\n";
	}
	return 0;
}