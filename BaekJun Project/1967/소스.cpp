#include <bits/stdc++.h>

using namespace std;

typedef struct Line {
	int to, cost;
};

vector<Line> V[10001];
vector<int> node[10001];
vector<int> dst(10001);

int ans = 0;

int dfs(int x) {

	int &ret = dst[x];

	for (Line w : V[x]) {

		int c = dfs(w.to) + w.cost;
		node[x].push_back(c);
		ret = max(ret, c);

	}

	ans = max(ans, ret);
	return ret;

}

void solve(int x, int sum) {

	sort(node[x].begin(), node[x].end(), greater<int>());

	if (node[x].size() == 1)
		ans = max(ans, node[x][0] + sum);
	else if (node[x].size() > 1)
		ans = max(
			{ ans, node[x][0] + node[x][1],
			node[x][0] + sum , node[x][1] + sum });

	for (Line w : V[x])
		solve(w.to, sum + w.cost);
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {

		int a, b, c; cin >> a >> b >> c;
		V[a].push_back({b, c});

	}

	dfs(1);
	solve(1, 0);

	cout << ans << "\n";

	return 0;

}