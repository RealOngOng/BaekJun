#include <bits/stdc++.h>

using namespace std;

typedef pair<int, bool> pi;

int n;
int arr[10001];
int dp[10001][2];

bool order[10001][2];
vector<pi> nxt[10001][2];
vector<int> ans;

vector<int> V[10001], adj[10001];

int solve(int x, int k)
{
	int &ret = dp[x][k];
	if (ret != -1) return ret;

	if (V[x].size() == 0)
	{
		order[x][k] = !k;
		return ret = (k) ? 0 : arr[x];
	}

	ret = 0;

	int v1 = 0, v2 = 0;

	if (!k)
	{
		for (int w : V[x])
			v1 += solve(w, 1);
		v1 += arr[x];
	}

	for (int w : V[x])
		v2 += solve(w, 0);

	ret = max(v1, v2);
	if (v1 > v2)
	{
		for (int w : V[x])
			nxt[x][k].push_back({ w, 1 });
		order[x][k] = true;
	}
	else
	{
		for (int w : V[x])
			nxt[x][k].push_back({ w, 0 });
		order[x][k] = false;
	}

	return ret;
}

void backtrack(int x, int k)
{
	if (order[x][k]) 
		ans.push_back(x);

	for (pi p : nxt[x][k])
		backtrack(p.first, p.second);
}

bitset<10001> visit;
void dfs(int x, int parent = -1)
{
	visit[x] = true;
	for (int w : adj[x])
	{
		if (visit[w] || parent == w) continue;
		V[x].push_back(w);
		dfs(w, x);
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		int from, to; cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	dfs(1);
	V[0].push_back(1);

	cout << solve(0, 0) << "\n";
	backtrack(0, 0);

	sort(ans.begin(), ans.end());
	for (int w : ans)
		cout << w << " ";

	return 0;
}