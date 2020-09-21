#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

typedef struct cmp {

	bool operator()(const pi& p1, const pi& p2) { return p1.first > p2.first; }

};

int dijkstra(int pos, int n, vector<vector<int>>& V, vector<int>& person) {

	int ans = 0;

	for (int w : person) {

		vector<int> vert(n + 1, 0x3f3f3f3f);

		priority_queue<pi, vector<pi>, cmp> pq;

		pq.push({ 0, w });

		int dst = 0;

		while (!pq.empty()) {

			pi top = pq.top(); pq.pop();

			int cost = top.first;
			int now = top.second;

			if (now == pos) {

				dst = cost;
				break;

			}

			for (int i = 1; i <= n; i++) {

				if (V[now][i] == -1) continue;

				if (vert[i] > cost + V[now][i]) {

					vert[i] = cost + V[now][i];
					pq.push({ cost + V[now][i], i });

				}

			}

		}

		ans += dst;

	}

	return ans;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;

	while (tc--) {

		int n, m, k; cin >> n >> m;

		vector<vector<int>> V(n + 1, vector<int>(n + 1, -1));
		for (int i = 0; i < m; i++) {

			int a, b, c; cin >> a >> b >> c;
			V[a][b] = c;
			V[b][a] = c;

		}

		cin >> k;
		vector<int> person(k);
		for (int i = 0; i < k; i++) cin >> person[i];

		int cost = 0x3f3f3f3f;
		int ans = 0;

		for (int i = 1; i <= n; i++) {

			int v = dijkstra(i, n, V, person);

			if (v < cost) {

				cost = v;
				ans = i;

			}

		}

		cout << ans << "\n";

	}

	return 0;

}