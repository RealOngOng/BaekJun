#include <bits/stdc++.h>

using namespace std;

vector<int> V[10001];
vector<int> adj[10001];
int dp[2][10001];
int arr[10001];

bitset<10001> visit;
void SetTree(int x, int parent = -1) {

	visit[x] = true;

	for (int w : V[x]) {

		if (visit[w] || parent == w) continue;
		adj[x].push_back(w);
		SetTree(w, x);

	}

}

int dfs(bool good, int x) {

	int &ret = dp[good][x];
	if (ret != -1)
		return ret;

	ret = (good) ? arr[x] : 0;

	if (adj[x].empty())
		return ret;

	for (int w : adj[x]) {

		if (good)
			ret += dfs(false, w);
		else {

			int a = dfs(true, w);
			int b = dfs(false, w);

			ret += max(a, b);

		}

	}
	
	return ret;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 1; i++) {

		int a, b; cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);

	}

	SetTree(1);
	
	int a = dfs(false, 1);
	int b = dfs(true, 1);

	cout << max(a, b);

	return 0;

}