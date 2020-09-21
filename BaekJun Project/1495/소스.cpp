#include <bits/stdc++.h>

using namespace std;

int n, s, m;
vector<int> arr;

bool dp[101][1001];

int main() {

	cin >> n >> s >> m;

	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	
	dp[0][s] = true;

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j <= m; j++) {

			if (!dp[i - 1][j]) continue;

			if (j + arr[i] <= m)
				dp[i][j + arr[i]] = true;

			if (j - arr[i] >= 0)
				dp[i][j - arr[i]] = true;

		}

	}

	int ans = -1;

	for (int i = 0; i <= m; i++) if (dp[n][i]) ans = i;

	cout << ans;

	return 0;

}