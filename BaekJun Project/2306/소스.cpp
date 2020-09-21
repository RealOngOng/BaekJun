#include <bits/stdc++.h>

using namespace std;

string str;
int dp[501][501];
int solve(int l, int r)
{
	if (l > r) return 0;

	int &ret = dp[l][r];
	if (ret != -1) return ret;

	ret = solve(l + 1, r - 1);
	char temp[] = { str[l], str[r] };
	string merge = string(temp, 2);
	if (merge == "at" || merge == "gc")
		ret = max(ret, solve(l + 1, r - 1) + 2);

	ret = max(ret, solve(l, r - 1));
	ret = max(ret, solve(l + 1, r));

	for (int k = l + 1; k < r; k++)
		ret = max(ret, solve(l, k) + solve(k + 1, r));

	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> str;
	cout << solve(0, str.length() - 1);
	return 0;
}