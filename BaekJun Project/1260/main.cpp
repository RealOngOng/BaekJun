#include <bits/stdc++.h>

using namespace std;

vector<int> V[1001];
vector<int> route;

bool visit[1001];

void dfs(int i) {

	visit[i] = true;

	route.push_back(i);

	for (int w : V[i]) {

		if (visit[w]) continue;

		dfs(w);

	}

}

void bfs(int i) {

	queue<int> q;

	visit[i] = true;
	q.push(i);

	route.push_back(i);

	while (!q.empty()) {

		int top = q.front(); q.pop();

		for (int w : V[top]) {

			if (visit[w]) continue;

			route.push_back(w);
			visit[w] = true;
			q.push(w);

		}

	}
	
}

int main() {

	int n, m, k; scanf("%d %d %d", &n, &m, &k);

	while (m--) {

		int a, b; scanf("%d %d", &a, &b);

		V[a].push_back(b);
		V[b].push_back(a);

	}

	for (int i = 1; i <= n; i++) sort(V[i].begin(), V[i].end());

	dfs(k);

	for (int q : route) printf("%d ", q);

	printf("\n"); route.resize(0);

	memset(visit, false, sizeof(visit));

	bfs(k);

	for (int q : route) printf("%d ", q);

	return 0;

}