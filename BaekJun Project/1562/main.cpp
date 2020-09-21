#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

int dp[101][10][1 << 10];

int n;

int solve(int pos, int prev, int used) {

	if (pos == n)
		return (used == (1 << 10) - 1);

	int &ret = dp[pos][prev][used];

	if (ret != -1) return dp[pos][prev][used];

	ret = 0;

	if(prev - 1 >= 0)
		ret = (ret + solve(pos + 1, prev - 1, used | (1 << (prev - 1)))) % MOD;

	if(prev + 1 < 10)
		ret = (ret + solve(pos + 1, prev + 1, used | (1 << (prev + 1)))) % MOD;

	return ret % MOD;

}

int main() {

	scanf("%d", &n);

	if (n < 10) printf("0\n");
	else {

		int ans = 0;

		for (int i = 1; i <= 9; i++) {

			memset(dp, -1, sizeof(dp));
			ans = (ans + solve(1, i, 1 << i)) % MOD;

		}

		printf("%d\n", ans % MOD);

	}

	return 0;

}