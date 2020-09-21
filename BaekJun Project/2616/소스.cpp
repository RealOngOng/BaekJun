#include <bits/stdc++.h>

using namespace std;

int dp[3][50001];
int s[50001];

int n, m;

int sum(int a, int b) { return s[b] - s[a - 1]; }

int solve(int cnt, int pos) {

	if (cnt >= 3 || pos > n) return 0;

	int &ret = dp[cnt][pos];

	if (ret != 0) return ret;

	ret = max(ret, solve(cnt + 1, pos + m) + sum(pos, pos + m - 1));
	ret = max(ret, solve(cnt, pos + 1));

	return ret;

}

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {

		int a; cin >> a;
		s[i] = s[i - 1] + a;

	}

	cin >> m;

	cout << solve(0, 1);

	return 0;

}