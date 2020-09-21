#include <bits/stdc++.h>

using namespace std;

bool visit[1001];

vector<int> V[1001];

void dfs(int n) {

	visit[n] = true;

	for (int i : V[n]) if(!visit[i]) dfs(i);

}

int main() {

	int n, m; scanf("%d %d", &n, &m);

	while (m--) {

		int a, b; scanf("%d %d", &a, &b);

		V[a].push_back(b);
		V[b].push_back(a);

	}

	int result = 0;

	for (int i = 1; i <= n; i++) {

		if (visit[i]) continue;
		dfs(i), result++;

	}

	printf("%d", result);

	return 0;

}