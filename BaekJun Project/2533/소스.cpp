#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

vector<int> V[MAX];
vector<int> adj[MAX];
int dp[2][MAX];

int dfs(bool adapt, int pos) {

	if (adj[pos].empty())
		return adapt;

	int &ret = dp[adapt][pos];
	if (ret != -1) return ret;

	ret = adapt;

	for (int w : adj[pos]) {
		if (adapt) {
			int a = dfs(adapt, w);
			int b = dfs(!adapt, w);

			ret += min(a, b);
		}
		else
			ret += dfs(!adapt, w);
	}

	return ret;

}

bitset<MAX> visit;

void SetTree(int pos, int parent = 0) {

	visit[pos] = true;
	
	for (int w : V[pos]) {
		if (visit[w] || parent == w) continue;

		adj[pos].push_back(w);
		SetTree(w, pos);
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));

	int n; cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	SetTree(1);

	int a = dfs(false, 1);
	visit.reset();
	int b = dfs(true, 1);

	cout << min(a, b) << "\n";

	return 0;

}