#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

bool visit[100001];

bool isOut(int num) { return (num < 0 || num > 100000); }

int main() {

	int n, k; scanf("%d %d", &n, &k);

	queue<pi> q;

	q.push({n, 0});
	visit[n] = true;

	int cnt = 1e9;

	while (!q.empty()) {

		pi top = q.front(); q.pop();

		if (top.first == k) cnt = min(cnt, top.second);

		int dx[3] = { top.first + 1, top.first - 1, 2 * top.first };

		for (int i = 0; i < 3; i++) {

			int dir = dx[i];

			if (isOut(dir) || visit[dir]) continue;

			visit[dir] = true;
			q.push({dir, top.second + 1});

		}

	}

	printf("%d\n", cnt);

	return 0;

}