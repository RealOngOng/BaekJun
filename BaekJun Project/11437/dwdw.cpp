#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;
const int M = 20;

vector<int> edge[N];
int p[N][M], //각 부모
l[N], //level 깊이
v[N]; //visit 방문

void dfs(int s, int lev) {
	v[s] = 1;
	l[s] = lev;

	for (int i = 1; i < M; ++i)
		p[s][i] = p[p[s][i - 1]][i - 1];

	for (auto i : edge[s]) {
		if (!v[i]) {
			p[i][0] = s;
			dfs(i, lev + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1, 1);

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < M; j++)
			std::cout << p[i][j] << " ";

		std::cout << "\n";

	}

	int m;
	cin >> m;

	for (int i = 1, a, b; i <= m; i++) {
		cin >> a >> b;

		if (l[a] < l[b])
			swap(a, b);

		// l[a] >= l[b]

		int tmp = l[a] - l[b];

		for (int j = 0; j < M; j++) {
			if (tmp & (1 << j))
				a = p[a][j];
		}

		// l[a] == l[b]

		for (int j = M - 1; j >= 0; j--) {
			if (p[a][j] != p[b][j]) {
				a = p[a][j];
				b = p[b][j];
			}
		}
		if (a == b) {
			cout << a << "\n";
		}
		else {
			cout << p[a][0] << "\n";
		}
	}
	return 0;
}