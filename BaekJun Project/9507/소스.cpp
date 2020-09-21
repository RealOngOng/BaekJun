#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[100];

ll koong(int n) {

	if (dp[n] != 0) return dp[n];

	return dp[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);

}

int main() {

	int tc; cin >> tc;

	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (tc--) {

		int n; cin >> n;
		cout << koong(n) << "\n";

	}

	return 0;

}