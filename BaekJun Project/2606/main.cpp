#include <bits/stdc++.h>

using namespace std;

vector<int> V[101];
bool visit[101];

int main() {

	int n, m; scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {

		int a, b; scanf("%d %d", &a, &b);

		V[a].push_back(b);
		V[b].push_back(a);

	}

	queue<int> q;

	int count = 0;

	q.push(1);
	visit[1] = true;

	while (!q.empty()) {

		count++;

		int top = q.front(); q.pop();

		for (int i : V[top]) {

			if (visit[i]) continue;

			visit[i] = true;
			q.push(i);

		}

	}

	printf("%d\n", count - 1);

	return 0;

}