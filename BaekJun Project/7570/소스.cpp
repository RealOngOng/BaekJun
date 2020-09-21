#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int dp[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	unordered_map<int, int> m;
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		m[arr[i]] = i;
	}

	int ans = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1;
		if (m[i - 1] < m[i]) dp[i] = max(dp[i], dp[i-1] + 1);
		ans = max(ans, dp[i]);
	}

	cout << n - ans;
	return 0;
}