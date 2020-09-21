#include <bits/stdc++.h>

using namespace std;

int dp[4001][4001];

int main() {

	string a, b; cin >> a >> b;

	for (int i = 0; i < a.length(); i++)
		for (int j = 0; j < b.length(); j++)
			dp[i][j] = (a[i] == b[j]);

	int ans = 0;

	for(int i=0; i < a.length(); i++)
		for (int j = 0; j < b.length(); j++) {

			if (dp[i][j] == 0) continue;
			int nx = i - 1, ny = j - 1;
			if (nx < 0 || ny < 0) continue;
			dp[i][j] += dp[nx][ny];
			ans = max(ans, dp[i][j]);

		}

	cout << ans;

	return 0;

}