#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> adj[100001], V[100001];

bitset<100001> visit;

int dp[100001][18];
void dfs(int pos, int parent = -1)
{
	visit[pos] = true;
	for (int w : adj[pos])
	{
		if (visit[w] || w == parent) continue;
		V[pos].push_back(w);
		dfs(w);
	}
}

int solve(int pos, int prev)
{
	int &ret = dp[pos][prev];
	if (ret != 0x3f3f3f3f) return ret;

	for (int i = 1; i <= 17; i++)
	{
		if (i == prev) continue;

		int sum = i;
		for (int w : V[pos])
			sum += solve(w, i);

		ret = min(ret, sum);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= 17; i++)
		ans = min(ans, solve(1, i));

	cout << ans;
	return 0;
}