#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

bool visit[101][1 << 15]; // i번째 섬, j 보석 수집상태일 때 보석의 최댓값

vector<pi> V[101];

int crystal[101];

int n, m, k;

int ans = 0;

void solve(int pos, int used, int count) {

	if (pos == 1) ans = max(ans, count);

	visit[pos][used] = true;

	for (pi &p : V[pos]) {

		int next = p.first, weight = p.second;

		if (count > weight) continue;

		if (!visit[next][used])solve(next, used, count);

		int jew = crystal[pos];

		if (!jew || count + 1 > weight) continue;

		if (!visit[next][(used | (1 << jew))])
			solve(next, used | (1 << jew), count + 1);

	}

}

int main() {

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++) {

		int a; scanf("%d", &a);
		crystal[a] = i + 1;

	}

	for (int i = 0; i < m; i++) {

		int a, b, c; scanf("%d %d %d", &a, &b, &c);

		V[a].push_back({b, c});
		V[b].push_back({a, c});

	}

	V[1].push_back({1, 14});

	solve(1, 0, 0);

	printf("%d\n", ans);

	return 0;

}