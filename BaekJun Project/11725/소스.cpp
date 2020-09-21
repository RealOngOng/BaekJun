#include <bits/stdc++.h>

using namespace std;

typedef struct Vertex {

	int depth = 0;
	vector<int> adj;

};

vector<Vertex> V(100001);
bool visit[100001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n - 1; i++) {

		int a, b; cin >> a >> b;

		V[a].adj.push_back(b);
		V[b].adj.push_back(a);

	}

	queue<int> q;

	q.push(1);
	visit[1] = true;

	while (!q.empty()) {

		int top = q.front(); q.pop();

		int depth = V[top].depth;

		for (int w : V[top].adj) {

			if (visit[w]) continue;

			visit[w] = true;
			V[w].depth = depth + 1;
			q.push(w);

		}

	}

	for (int i = 2; i <= n; i++) {

		int p = 0;

		for(int w : V[i].adj)
			if (V[w].depth == V[i].depth - 1) {

				p = w;
				break;

			}

		cout << p << "\n";

	}

	return 0;

}