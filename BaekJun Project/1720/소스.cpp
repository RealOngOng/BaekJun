#include <bits/stdc++.h>

using namespace std;

int n;
int dp[31];
int dp1[31];

int solve(int x)
{
	if (x <= 1) return 1;

	int &ret = dp[x];
	if (ret != -1)return ret;

	return ret = 2 * solve(x - 2) + solve(x - 1);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	int sum = 0;
	if (n % 2 == 1)
		sum = (solve(n) + solve(n / 2)) / 2;
	else
		sum = (solve(n) + solve(n / 2) + 2 * solve(n / 2 - 1)) / 2;
	cout << sum;
	return 0;
}