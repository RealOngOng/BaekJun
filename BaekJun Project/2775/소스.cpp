#include <bits/stdc++.h>

using namespace std;

int dp[16][16];

int main() {

	for (int i = 1; i <= 15; i++) dp[0][i] = i;

	for (int i = 1; i <= 15; i++)
		for (int j = 1; j <= 15; j++)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];

	int t; scanf("%d", &t);

	while (t--) {

		int k, n; scanf("%d %d", &k, &n);

		printf("%d\n", dp[k][n]);

	}

	return 0;

}