#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int n, m;
vector<ll> pos, cost;
ll sum[1001];
ll dp[1001][1001][2];

ll solve(int l, int r, int prev)
{
	if (l == 0 && r == n-1) return 0;

	ll &ret = dp[l][r][prev];
	if (ret != LLONG_MAX) return ret;

	int now = (prev == 0) ? l : r;
	//0 ~ l-1, r+1 ~ n-1
	ll len = sum[n-1] - sum[r] + sum[l-1];

	if(l > 0)
		ret = min(ret, solve(l-1, r, 0) + len * abs(pos[now] - pos[l-1]));

	if(r < n - 1)
		ret = min(ret, solve(l, r+1, 1) + len * abs(pos[now] - pos[r+1]));

	return ret;
}

int main()
{
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			for (int k = 0; k <= 1; k++)
				dp[i][j][k] = LLONG_MAX;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		pos.push_back(a);
		cost.push_back(b);
		sum[i] = ((i == 0) ? 0 : sum[i-1]) + b;
	}

	cout << solve(m-1, m-1, 0);
	return 0;
}