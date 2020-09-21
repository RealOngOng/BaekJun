#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[1001][1001];
vector<string> field;
int ans;
int px, py;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
 
bool isOut(int x, int y) { return (x < 0 || y < 0 || x >= m || y >= n); }

void dfs(int x, int y) {

	if (ans < dp[x][y]) {
		ans = dp[x][y];
		px = x, py = y;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (isOut(nx, ny) || dp[nx][ny] || field[nx][ny] == '#') continue;

		dp[nx][ny] = dp[x][y] + 1;
		dfs(nx, ny);
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {

		cin >> n >> m;

		px = -1, py = -1;
		ans = 0;
		field.clear(); field.resize(m);
		for (int i = 0; i < m; i++)
			cin >> field[i];

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][j] == '#' || dp[i][j]) continue;
				dp[i][j] = 1;
				dfs(i, j);
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[px][py] = 1;
		dfs(px, py);

		cout << "Maximum rope length is " << ans - 1 << ".\n";

	}

	return 0;

}