#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;

int dp[1500000];

int main()
{
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i < 1500000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

	long long n; cin >> n;
	cout << dp[n % 1500000] << "\n";
	return 0;
}