#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll dp[101];

int main() {

	scanf("%d", &n);

	for (int i = 0; i < 6; i++) dp[i] = i;

	for (int i = 6; i <= n; i++) dp[i] = max({dp[i - 1] + 1, dp[i - 3] * 2, dp[i - 4] * 3, dp[i - 5] * 4});

	printf("%lld\n", dp[n]);

	return 0;

}