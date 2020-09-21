#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[201];
int dp[201][201];

int solve(int s, int e)
{
	if (s == e)
		return 0;

	int &ret = dp[s][e];
	if (ret != 0x3f3f3f3f) return ret;

	for (int i = s; i < e; i++)
	{
		int w = (arr[s] != arr[i+1]);
		ret = min(ret, solve(s, i) + solve(i + 1, e) + w);
	}

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0x3f3f3f3f;
	cout << solve(0, n - 1);
	return 0;
}