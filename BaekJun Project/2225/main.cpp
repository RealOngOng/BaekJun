#include <bits/stdc++.h>

#define MOD 1000000000

using namespace std;

int dp[201][201];

int main() {

	for (int i = 0; i <= 200; i++) dp[i][1] = 1;

	for(int i=0; i <= 200; i++)//³ª´« ¼ö
		for (int j = 0; j <= 200; j++) { //¼ö

			for (int w = 0; w <= j; w++) dp[j][i] = (dp[j][i] + dp[j - w][i - 1]) % MOD;

		}

	int n, k; scanf("%d %d", &n, &k);

	printf("%d\n", dp[n][k] % MOD);

	return 0;

}