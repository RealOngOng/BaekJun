#include <bits/stdc++.h>

using namespace std;

//i자리의 경우의수
int dp[41];

int main() {

	dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 3;
	for (int i = 4; i <= 40; i++) dp[i] = dp[i - 1] + dp[i - 2];

	int n, m; cin >> n >> m;

	vector<int> arr, term;

	arr.push_back(0);

	for (int i = 0; i < m; i++) {

		int a; cin >> a;
		arr.push_back(a);

	}

	arr.push_back(n + 1);

	for (int i = 0; i < arr.size() - 1; i++)
		term.push_back(arr[i + 1] - arr[i] - 1);

	int ans = 1;
	for (int w : term) ans *= dp[w];

	cout << ans;

	return 0;

}