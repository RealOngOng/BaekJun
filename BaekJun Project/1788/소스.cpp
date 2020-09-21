#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int dp[1000001];

int main()
{
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

	int n; cin >> n;

	int ans = 0;
	if (n < 0)
		ans = dp[-n] % MOD;
	else
		ans = dp[n] % MOD;

	if (n < 0 && n % 2 == 0)
		ans = -ans;

	if (ans == 0)
		cout << "0\n";
	else
		cout << ((ans < 0) ? "-1" : "1") << "\n";

	cout << abs(ans);
	return 0;
}