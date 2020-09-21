#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

map<pi, int> dp;

int func(int s, int e) {

	if (s == 0 && e == 0) return 0;
	if (dp.find({ s, e }) != dp.end()) return dp[{s, e}];

	for (int i = 1; i <= 30; i++) {

		int k = (1 << i) - 1;

		if (k * 2 < s) continue;
		if (k > e) break;

		int ss = max(s, k);
		int ee = min(e, k * 2);

		dp[{s, e}] = max(dp[{s, e}], func(ss - k, ee - k) + i);

	}

	return dp[{s, e}];

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;

	while (tc--) {

		int a, b; cin >> a >> b;

		cout << func(a, b) << "\n";

	}

	return 0;

}