#include <bits/stdc++.h>

using namespace std;

int dx[4] = { -1, -1, 0, 1 };
int dy[4] = { 0, -1, -1, -1 };

//dp[i][j] = i j 까지 오는 데 최소 비용
//dp[i][j] = min(dp[i - dx][j - dy] + arr[i][j])
int dp[3][100000];
int arr[3][100000];

int n;

bool isOut(int x, int y){
	return (x < 0 || y < 0 || x >= 3 || y >= n);
};

int solve(int x, int y) {

	int &ret = dp[x][y];

	if (ret != 0x3f3f3f3f) return ret;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i], ny = y + dy[i];
		if (isOut(nx, ny)) continue;
		ret = min(ret, solve(nx, ny) + arr[x][y]);

	}

	return ret;

}

int main() {

	int tc = 1;

	while (true) {

		cin >> n;
		if (n == 0) break;
		
		memset(dp, 0x3f3f3f3f, sizeof(dp));

		for (int i = 0; i < n; i++) {

			int a, b, c; cin >> a >> b >> c;
			arr[0][i] = a;
			arr[1][i] = b;
			arr[2][i] = c;

		}

		dp[1][0] = arr[1][0];
		cout << tc++ << ". " << solve(1, n - 1) << "\n";

	}

	return 0;

}