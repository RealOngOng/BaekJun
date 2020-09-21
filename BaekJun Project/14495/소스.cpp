#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[120];

int main()
{
	dp[1] = dp[2] = dp[3] = 1;

	int n; cin >> n;
	for (int i = 4; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 3];

	cout << dp[n];
	return 0;
}