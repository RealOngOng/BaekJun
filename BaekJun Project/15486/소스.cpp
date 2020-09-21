#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1500001];
int d[1500001], p[1500001];

int solve(int day)
{
	if (day == n) return 0;

	int &ret = dp[day];
	if (ret != -1) return ret;

	ret = 0;
	if(day + d[day] <= n)
		ret = max(ret, solve(day + d[day]) + p[day]);
	ret = max(ret, solve(day + 1));

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> d[i] >> p[i];

	cout << solve(0);
	return 0;
}