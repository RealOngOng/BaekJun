#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
int dp[100001][5][5];

int cost(int from, int to)
{
	if (from == 0) return 2;

	int next = from + 1, prev = from - 1;
	if (next == 5) next = 1;
	if (prev == 0) prev = 4;

	if (to == next || to == prev) return 3;

	return 4;
}

int solve(int pos, int a, int b)
{
	if (pos == n) return 0;

	int &ret = dp[pos][a][b];
	if (ret != 0x3f3f3f3f) return ret;

	if (a == arr[pos] || b == arr[pos])
		ret = min(ret, solve(pos+1, a, b) + 1);
	else
	{
		ret = min(ret, solve(pos+1, arr[pos], b) + cost(a, arr[pos]));
		ret = min(ret, solve(pos+1, a, arr[pos]) + cost(b, arr[pos]));
	}

	return ret;
}

int main()
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));

	while (true)
	{
		int a; cin >> a;
		if (a == 0) break;
		arr[n++] = a;
	}

	cout << solve(0, 0, 0);
	return 0;
}