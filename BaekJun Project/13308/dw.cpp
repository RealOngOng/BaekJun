#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

struct Node {

	int idx, cost;
	ll dst;

	Node(int _idx, int _cost, ll _dst) {

		idx = _idx;
		cost = _cost;
		dst = _dst;

	}

};

struct cmp {

	bool operator()(const Node& n1, const Node& n2) { return n1.dst > n2.dst; }

};

int n, m;

vector<pi> V[2501];

bool visit[2501][2501];
int cost[2501];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> cost[i];
	for (int i = 1; i <= m; i++) {

		int a, b, c; cin >> a >> b >> c;

		V[a].push_back({b, c});
		V[b].push_back({a, c});

	}

	priority_queue<Node, vector<Node>, cmp> pq;

	pq.push({1, cost[1], 0});

	while (!pq.empty()) {

		Node top = pq.top(); pq.pop();

		if (visit[top.idx][top.cost]) continue;
		if (top.idx == n) {

			cout << top.dst;
			break;

		}

		visit[top.idx][top.cost] = true;

		for (pi w : V[top.idx])
			pq.push({w.first, min(top.cost, cost[w.first]), top.cost * w.second + top.dst});

	}

	return 0;

}