#include <bits/stdc++.h>

using namespace std;

int dp[250][250];
vector<int> arr;

int solve(int s, int e) {

	if (s == e) 
		return arr[s];

	if (s + 1 == e)
		if (arr[s] == arr[e])
			return arr[s] + 1;

	int &ret = dp[s][e];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = s; i < e; i++) {

		int a = solve(s, i), b = solve(i + 1, e);

		if (a == b)
			ret = max(ret, a + 1);

	}

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));

	int n; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			ans = max(ans, solve(i, j));

	cout << ans;

	return 0;

}