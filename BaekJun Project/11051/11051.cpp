#include <iostream>

using namespace std;

long long int dp[1001][1001];

int main() {

	int n, r;
	cin >> n >> r;

	for (int x = 1; x <= n; x++) {

		for (int y = 0; y <= n; y++) {

			if (x == y || y == 0) { dp[x][y] = 1; continue; }
			dp[x][y] = (dp[x - 1][y] + dp[x - 1][y - 1]) % 10007;

		}

	}

	cout << dp[n][r] << endl;

	return 0;

}