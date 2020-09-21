#include <bits/stdc++.h>

using namespace std;

int dp[401][401];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			for (int k = j; k < m; k++) {
				if (str[k] == 'X') break;
				dp[i][j]++;
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++)
	//		cout << dp[i][j] << " ";
	//	cout << "\n";
	//}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = 1e9;
			for (int k = i; k < n; k++) {
				u = min(u, dp[k][j]);
				if (u == 0) break;
				ans = max(ans, 2*(k - i + 1) + u * 2 -1);
			}
		}
	}
	cout << ans;

	return 0;

}