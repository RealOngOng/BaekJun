#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

typedef struct Weight {

	int to, cost = INF;

};

typedef pair<int, int> pi;

typedef struct cmp {

	bool operator()(const pi& p1, const pi& p2) { return p1.first > p2.first; }
		
};

int main() {

	int n, m; cin >> n >> m;

	vector<int> vert(n + 1, INF);
	vector<vector<Weight>> V(n + 1);

	int s; cin >> s;
	for (int i = 0; i < m; i++) {

		int a, b, c; cin >> a >> b >> c;
		V[a].push_back({b, c});

	}

	priority_queue<pi, vector<pi>, cmp> pq;

	pq.push({ 0, s });

	while (!pq.empty()) {

		pi top = pq.top(); pq.pop();

		int cost = top.first;
		int now = top.second;

		for (Weight w : V[now]) {

			if (vert[w.to] > cost + w.cost) {

				vert[w.to] = cost + w.cost;
				pq.push({ vert[w.to], w.to });

			}

		}

	}

	for (int i = 1; i <= n; i++) {

		if (i == s) cout << "0\n";
		else {

			int v = vert[i];
			if (v == INF) cout << "INF\n";
			else cout << vert[i] << "\n";

		}

	}

	return 0;

}