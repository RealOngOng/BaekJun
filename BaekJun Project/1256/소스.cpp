#include <bits/stdc++.h>

using namespace std;

//a i°³, z j°³
int dp[101][101];

string str;

void solve(int n, int m, int k) {

	if (n == 0 || m == 0) {

		if(n == 0)
			for (int i = 0; i < m; i++)
				str += 'z';

		if(m == 0)
			for (int i = 0; i < n; i++)
				str += 'a';

		return;

	}

	if (k <= dp[n - 1][m]) {

		str += 'a';
		solve(n - 1, m, k);

	}
	else {

		str += 'z';
		solve(n, m - 1, k - dp[n - 1][m]);

	}

}

int main() {

	for (int i = 1; i <= 100; i++)
		dp[i][0] = dp[0][i] = 1;

	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			dp[i][j] = min(dp[i - 1][j] + dp[i][j - 1], 1000000000);

	int n, m, k; cin >> n >> m >> k;

	if (k > dp[n][m])
		cout << "-1";
	else {

		solve(n, m, k);
		cout << str;

	}

	return 0;

}