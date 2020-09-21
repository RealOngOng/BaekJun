#include <bits/stdc++.h>

using namespace std;

int n;
int T[16], P[16], dp[16];

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> T[i] >> P[i];

	for (int i = 1; i <= n + 1; i++) {

		int &ret = dp[i];

		for (int j = 1; j <= i; j++) 
			ret = max(ret, dp[j]);

		if (i + T[i] <= n + 1)
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);

	}

	cout << dp[n + 1];

	return 0;

}