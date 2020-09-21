#include <bits/stdc++.h>

using namespace std;

int dp[5001][5001];

vector<int> arr;

int solve(int s, int e) {

	if (s >= e)
		return 0;

	int &ret = dp[s][e];

	if (ret != 0x3f3f3f3f) return ret;

	if (arr[s] == arr[e])
		ret = min(ret, solve(s + 1, e - 1));
	else
		ret = min({ ret, solve(s + 1, e) + 1, solve(s, e - 1) + 1 });

	return ret;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	int n; cin >> n;

	arr.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << solve(0, n - 1);

	return 0;

}