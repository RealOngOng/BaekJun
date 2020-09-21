#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, s;

int dp[300001];
vector<pi> arr;

int solve(int x)
{
	if (x == n) return 0;

	int &ret = dp[x];
	if (ret != -1) return ret;

	ret = max(ret, solve(x+1));

	int idx = 
		lower_bound(arr.begin(), arr.end(), make_pair(arr[x].first + s, 0)) - arr.begin();

	if (idx <= n)
		ret = max(ret, solve(idx) + arr[x].second);

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n >> s;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end());

	cout << solve(0);
	return 0;
}