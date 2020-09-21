#include <bits/stdc++.h>

using namespace std;

typedef struct Line{

	int to, cost;

};

vector<Line> V[10001];
int n, m;
int from, to;

bitset<10001> visit;

bool dfs(int n, int weight) {

	visit[n] = true;

	for (Line w : V[n]) {

		if (visit[w.to] || weight >= w.cost) continue;
		dfs(w.to, weight);

	}

	return visit[to];

}

int main() {

	int lo = 0, hi = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {

		int a, b, c; cin >> a >> b >> c;
		V[a].push_back({b, c});
		V[b].push_back({a, c});
		hi = max(hi, c);

	}

	cin >> from >> to;
	
	while (lo+1 < hi) {

		int mid = (lo + hi) / 2;

		visit.reset();
		bool flag = dfs(from, mid);

		if (flag) lo = mid;
		else hi = mid;

	}

	cout << hi;

	return 0;

}