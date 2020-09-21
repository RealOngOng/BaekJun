#include <bits/stdc++.h>

using namespace std;

double arr[21][21];
//1 << 20
double dp[''];

int n;
double solve(int state)
{
	if (state == (1 << n) - 1) return 1.0;

	double &ret = dp[state];
	if (ret >= 0) return ret;

	int pos = 0;
	for (int i = 0; i < n; i++)
		if (state & (1 << i)) pos++;

	ret = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (state & (1 << i)) continue;
		ret = max(ret, solve(state | (1 << i)) * arr[pos][i]);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(dp, dp + '', -1);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			double a; cin >> a;
			a *= 0.01;
			arr[i][j] = a;
		}

	cout << fixed;
	cout.precision(7);
	cout << solve(0) * 100.0;
	return 0;
}