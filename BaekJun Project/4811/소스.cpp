#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[41][41];

ll solve(int x, int y)
{
	if (x == 0 && y == 0) 
		return 1;

	ll &ret = dp[x][y];
	if (ret != -1) return ret;

	ret = 0;
	if (y > 0)
		ret += solve(x+1, y-1);

	if (x > 0)
		ret += solve(x-1, y);

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	while (true)
	{
		int n; cin >> n;
		if (n == 0) break;
		cout << solve(0, n) << "\n";
	}
	return 0;
}