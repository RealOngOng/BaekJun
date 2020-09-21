#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> V;
vector<bool> visit, finished;

int comp = 0, node = 0;
bool cycle = false;

void dfs(int idx) {

	visit[idx] = true;

	comp++;

	for (int w : V[idx]) {

		node++;

		if (visit[w]) continue;

		dfs(w);

	}

	finished[idx] = true;

}

int main() {

	int tc = 1;

	while (true) {

		int n, m; cin >> n >> m;

		if (n == 0 && m == 0) break;

		V.resize(n + 1);
		visit.resize(n + 1);
		finished.resize(n + 1);

		while (m--) {

			int a, b; cin >> a >> b;

			V[a].push_back(b);
			V[b].push_back(a);

		}

		int cnt = 0;

		for (int i = 1; i <= n; i++) {

			if (visit[i]) continue;

			comp = 0, node = 0;

			dfs(i);

			cnt += (2 * comp - 2 == node);

		}

		if (cnt == 0) printf("Case %d: No trees.\n", tc);
		else if (cnt == 1) printf("Case %d: There is one tree.\n", tc);
		else printf("Case %d: A forest of %d trees.\n", tc, cnt);

		V.clear();
		visit.clear();
		finished.clear();

		tc++;

	}

	return 0;

}