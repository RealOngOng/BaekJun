#include <bits/stdc++.h>

using namespace std;

int n;
int dp[10001][4];

int solve(int num, int k)
{
	if (num == n) return 1;

	int &ret = dp[num][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = k; i <= 3; i++)
	{
		if (num + i > n) break;
		ret += solve(num + i, i);
	}

	return ret;
}

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		memset(dp, -1, sizeof(dp));

		cin >> n;
		cout << solve(0, 1) << "\n";
	}
	return 0;
}