#include <bits/stdc++.h>

using namespace std;

int n;
int dp[2501];
int p[2501][2501];
string str;

int palin(int s, int e)
{
	if (s == e) return true;
	if (s + 1 == e)
		return (str[s] == str[e]);

	int &ret = p[s][e];
	if (ret != -1) return ret;

	ret = 0;
	if (str[s] == str[e])
		ret = min(1, palin(s + 1, e - 1));

	return ret;
}

int solve(int x)
{
	if (x == n) return 0;

	int &ret = dp[x];
	if (ret != 0x3f3f3f3f) return ret;

	for (int i = x; i < n; i++)
		if (palin(x, i))
			ret = min(ret, solve(i + 1) + 1);

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(p, -1, sizeof(p));
	memset(dp, 0x3f3f3f3f, sizeof(dp));

	cin >> str;
	n = str.length();

	cout << solve(0);
	return 0;
}