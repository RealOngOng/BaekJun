#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int f, s, g, u, d;
bool visit[1000001];

bool isOut(int n) { return (n <= 0 || n > f); }

int main() {

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	queue<pi> q;

	q.push({s, 0});
	visit[s] = true;

	int dx[2] = { u, -d };

	int cnt = 1e9 + 1;

	while (!q.empty()) {

		pi top = q.front(); q.pop();

		if (top.first == g) 
			cnt = min(cnt, top.second);

		for (int i = 0; i < 2; i++) {

			int dir = top.first + dx[i];

			if (isOut(dir) || visit[dir]) continue;

			visit[dir] = true;
			q.push({dir, top.second + 1});

		}

	}

	if (!visit[g]) printf("use the stairs\n");
	else printf("%d\n", cnt);

	return 0;

}