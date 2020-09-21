#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int dp[1001];

int solve(int pos) {

	if (pos >= n) return 0;

	int &ret = dp[pos];

	if (ret != 0x3f3f3f3f) return ret;

	for (int i = 1; i <= arr[pos]; i++)
		ret = min(ret, solve(pos + i) + 1);

	return ret;

}

int main() {

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	cin >> n;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	if (n == 1) cout << "0\n";
	else {

		int ans = solve(1);

		if (ans == 0x3f3f3f3f) cout << "-1\n";
		else cout << ans;

	}

	return 0;

}