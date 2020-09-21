#include <bits/stdc++.h>

using namespace std;

//i부터 시작해 j개의 콤보를 할때 값
int C[2001][2001];
int a[2001], b[2001];

//i번째에서 콤보를 시작했고, j번째를 볼 때 최대값
int dp[2001][2001];

int n, k, p;

int solve(int start, int pos) {

	if (pos >= n) return p;

	int &ret = dp[start][pos];
	if (ret != -1) return ret;

	for (int k = 1; k < start; k++)
		ret = max(ret, solve(start - k - 1, pos - k) + C[start - k + 1][start] + p);

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));

	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) {

		int v = 0;
		for (int j = 0; j < k && i + j < n; j++) {
			v += a[i + j] * b[j];
			C[i][j] = v;
		}

	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, solve(i, i));

	cout << ans;

	return 0;

}