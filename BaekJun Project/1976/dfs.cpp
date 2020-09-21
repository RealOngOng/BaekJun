#include <bits/stdc++.h>

using namespace std;

vector<int> V[201];

bool visit[201];
set<int> used;

void dfs(int n) {

	visit[n] = true;
	used.insert(n);

	for (int w : V[n]) {

		if (visit[w]) continue;
		dfs(w);

	}

}

int main()
{

	int n, m; cin >> n >> m;

	for(int i=0; i < n; i++)
		for (int j = 0; j < n; j++) {

			int a; cin >> a;
			if (a)
				V[i].push_back(j);

		}

	vector<int> dst(m);

	for (int i = 0; i < m; i++) {

		int a; cin >> a;
		dst[i] = a - 1;

	}

	dfs(dst[0]);

	bool ans = true;

	for (int w : dst)
		if (used.find(w) == used.end()) ans = false;

	cout << ((ans) ? "YES" : "NO");

	return 0;

}