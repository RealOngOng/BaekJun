#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[81];

int main()
{
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= 80; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int n; cin >> n;
	cout << 2LL * dp[n] + 2LL * (dp[n] + dp[n - 1]);
	return 0;
}