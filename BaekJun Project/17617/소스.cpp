#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, r, m; cin >> n >> r >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	vector<int> sub(2 * n);
	for (int i = 0; i < n - 1; i++)
		sub[i] = sub[i + n] = arr[i + 1] - arr[i] - 2 * r;
	sub[n - 1] = sub[n - 1 + n] = m - arr[n - 1] + arr[0] - 2 * r;

	int ans = 0;
	vector<int> dp(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++)
	{
		dp[i] = max(0, dp[i - 1]) + sub[i - 1];
		ans = max(ans, dp[i]);
	}

	cout << (ans + 1) / 2;

	return 0;
}