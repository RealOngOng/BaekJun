#include <bits/stdc++.h>

using namespace std;

int n;
int dp[2002][2002];

int solve(int num, int k)
{
	if (num == n) return 0;
	if (num > 2000) return 0x3f3f3f3f;

	int &ret = dp[num][k];
	if (ret != 0x3f3f3f3f) return ret;

	if (num > 1)
		ret = min(ret, solve(num-1, k) + 1);

	if (k > 0 && num + k <= 2000)
		ret = min(ret, solve(num + k, k) + 1);

	ret = min(ret, solve(num, num) + 1);

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	cin >> n;

	cout << solve(1, 0);
	return 0;
}