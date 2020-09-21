#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[51][51][51];
int solve(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;

	ll &ret = dp[a][b][c];
	if (ret != -1) return ret;

	if (a > 20 || b > 20 || c > 20) return ret = solve(20, 20, 20);
	if (a < b && b < c)
		return ret = solve(a, b, c - 1) + solve(a, b - 1, c-1) - solve(a, b-1, c);

	return ret = solve(a - 1, b, c) + solve(a - 1, b - 1, c) +
		solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));

	while (true)
	{
		int a, b, c; cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
	}
	return 0;
}