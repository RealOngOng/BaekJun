#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string str;
ll dp[41];

int solve(int x)
{
	if (x == n) return 1;

	ll &ret = dp[x];
	if (ret != -1) return ret;

	ret = 0;
	if (str[x] == '0') return ret;

	ret += solve(x + 1);

	if (x+1 < n)
	{
		int v = atoi(str.substr(x, 2).c_str());
		if (v <= 34)
			ret += solve(x + 2);
	}

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> str;
	n = str.length();
	cout << solve(0);
	return 0;
}