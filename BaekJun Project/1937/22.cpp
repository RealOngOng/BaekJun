#include <bits/stdc++.h>

using namespace std;

int n;

int arr[500][500];
int dp[500][500];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool isOut(int x, int y) { return (x < 0 || y < 0 || x >= n || y >= n); }

int solve(int x, int y) {

	int &ret = dp[x][y];

	if (ret > 1) return ret;

	ret = 1;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isOut(nx, ny)) continue;

		if (arr[x][y] < arr[nx][ny])
			ret = max(ret, solve(nx, ny) + 1);

	}

	return ret;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(dp[i][j] == 0)
				ans = max(ans, solve(i ,j));

	cout << ans;

	return 0;

}