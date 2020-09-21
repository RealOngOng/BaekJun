#include <bits/stdc++.h>

using namespace std;

vector<int> V[100001];
vector<int> P[100001];
bitset<100001> visit;

int n, m, x;

int updfs(int x) {

	visit[x] = true;

	int ans = 1;

	for (int w : P[x]) {

		if (visit[w]) continue;
		ans += updfs(w);

	}

	return ans;

}

int dfs(int x) {

	visit[x] = true;

	int ans = 1;

	for (int w : V[x]) {

		if (visit[w]) continue;
		ans += dfs(w);

	}

	return ans;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {

		int u, v; cin >> u >> v;
		V[u].push_back(v);
		P[v].push_back(u);

	}

	int up = updfs(x);
	visit.reset();
	int down = n - dfs(x) + 1;

	cout << up << " " << down;

	return 0;

}