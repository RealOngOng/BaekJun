#include <bits/stdc++.h>

using namespace std;

vector<int> V[101];
bool visit[101];

int r = -1;

int n, x, y, m;

void dfs(int i, int num) {

	if (i == y) r = num;

	visit[i] = true;

	for (int w : V[i])
		if (!visit[w]) dfs(w, num + 1);

}

int main() {

	scanf("%d %d %d %d", &n, &x, &y, &m);

	while (m--) {

		int a, b; scanf("%d %d", &a, &b);

		V[a].push_back(b);
		V[b].push_back(a);

	}

	dfs(x, 0);

	printf("%d\n", r);

	return 0;

}