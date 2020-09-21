#include <bits/stdc++.h>

using namespace std;

int dp[51][5];

int solve(int n,)
{

	int &ret = dp[a][b][c][d];
	if (ret != -1) return ret;

	ret = 0;
	if(a >= 1 && b >= 1 && c >= 1 && d >= 1 && a ==b && b==c && c==d)
		ret += solve(a-1, b-1, c-1, d-1);

	if (a >= 1 && b >= 1 && c >= 2 && d >= 2 && a == b && c == d)
		ret += solve(a-1, b-1, c-2, d-2);

	if (a >= 1 && b >= 2 && c >= 2 && d >= 1 && a == d && b == c)
		ret += solve(a-1, b-2, c-2, d-1);

	if (a >= 2 && b >= 1 && c >= 1 && d >= 2 && a == d && b == c)
		ret += solve(a-2, b-1, c-1, d-2);

	if (a >= 2 && b >= 2 && c >= 1 && d >= 1 && a == b && c == d)
		ret += solve(a-2, b-2, c-1, d-1);

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int tc; cin >> tc;
	while (tc--)
	{
		int n; cin >> n;
		cout << solve(n, n, n, n) << "\n";
	}
	return 0;
}