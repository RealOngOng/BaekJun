#include <bits/stdc++.h> 

using namespace std;

int main()
{
	int n, s; cin >> n >> s;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++)
		dp[i] = dp[i - 1] + arr[i - 1];

	function<int(int, int)> GetSum = [&](int s, int e) -> int
	{
		return dp[e + 1] - dp[s];
	};

	int l = 0, r = 0;
	int sum = arr[0];
	int ans = 0x3f3f3f3f;
	n--;
	while (l < n || r < n)
	{
		if (sum >= s)
			ans = min(ans, r - l + 1);

		if (l < n && r < n)
		{
			if (sum < s) r++;
			else l++;
		}
		else if (l < n) l++;
		else if (r < n) r++;

		sum = GetSum(l, r);
		if (sum >= s)
			ans = min(ans, r - l + 1);
	}

	if (ans == 0x3f3f3f3f) ans = 0;
	cout << ans;

	return 0;
}