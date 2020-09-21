#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int dp[1001], rdp[1002];

int main() {

	int n; scanf("%d", &n);

	dp[1] = 1, dp[2] = 6;
	rdp[2] = 5, rdp[3] = 15;

	for (int i = 3; i <= n; i++) {

		dp[i] = dp[i - 1] + rdp[i] + 1;
		rdp[i + 1] = rdp[i] + rdp[i - 1];

	}

	printf("%d\n", dp[n]);

	return 0;

}