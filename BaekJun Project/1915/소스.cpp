#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int n, m;

int dx[3] = { -1, 0, -1 };
int dy[3] = { 0, -1, -1 };

int main() {

	cin >> n >> m;

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		string str; cin >> str;

		for (int j = 1; j <= m; j++)
			arr[i][j] = str[j - 1] - '0';

	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {

			if (arr[i][j]) dp[i][j] = 1;

			if (arr[i - 1][j] == 1 && arr[i][j - 1] == 1 && arr[i - 1][j - 1] == 1)
				dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

			ans = max(ans, dp[i][j]);

		}

	cout << ans * ans;

	return 0;

}