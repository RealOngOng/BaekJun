#include <bits/stdc++.h>

using namespace std;

//dp[i] = i개를 갖고 있을 때 최소횟수
//dp[i] = dp[i - c] + 1
int dp[300001];

int main() {

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	int n; cin >> n;

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {

		int &ret = dp[i];

		int p = 0;

		for (int j = 1; ;j++) {

			p += j * (j + 1) / 2;
			if (p > i) break;
			ret = min(ret, dp[i - p] + 1);

		}

	}

	cout << dp[n];

	return 0;

}