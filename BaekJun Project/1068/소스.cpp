#include <bits/stdc++.h>

using namespace std;

int parent[51];
vector<int> V[51];
bool visit[51];
int cnt = 0;

void dfs(int idx) {

	visit[idx] = true;

	if (V[idx].size() == 0) cnt++;

	for (int w : V[idx]) {

		if (visit[w]) continue;

		dfs(w);

	}

}

int main() {

	int root = 0;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {

		int a; cin >> a;

		parent[i] = a;

		if (a == -1) root = i;
		else 
			V[a].push_back(i);

	}

	int d; cin >> d;

	if (d == root)
		cout << "0\n";
	else {

		V[parent[d]].erase(find(V[parent[d]].begin(), V[parent[d]].end(), d));

		dfs(root);

		cout << cnt << "\n";

	}

	return 0;

}