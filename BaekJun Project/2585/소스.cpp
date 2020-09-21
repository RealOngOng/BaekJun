#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

typedef struct Line {

	int to, cost;

};

typedef struct bdata {

	int pos, cnt;

};

int n, k;
vector<Vector2> vec;
vector<Line> V[1010];

bool bfs(int mid) {

	bitset<1010> visit;
	bool flag = false;

	queue<bdata> q;
	visit[0] = true;
	q.push({ 0, 0 });

	while (!q.empty()) {

		bdata top = q.front(); q.pop();

		if (top.cnt > k + 1) continue;
		if (top.pos == n + 1) {
			flag = true;
			continue;
		}

		for (Line w : V[top.pos]) {

			if (visit[w.to] || w.cost > mid) continue;
			visit[w.to] = true;
			q.push({ w.to, top.cnt + 1 });

		}

	}

	return flag;

}

int dist(Vector2 v1, Vector2 v2) {

	double dx = (double)v1.x - v2.x;
	double dy = (double)v1.y - v2.y;

	double dst = sqrt(dx * dx + dy * dy) / 10.0;

	return (int)ceil(dst);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	vec.push_back({ 0, 0 });
	for (int i = 0; i < n; i++) {

		int x, y; cin >> x >> y;
		vec.push_back({ x, y });

	}
	vec.push_back({ 10000, 10000 });

	int lo = 0, hi = 0;

	for (int i = 0; i < vec.size(); i++)
		for (int j = i + 1; j < vec.size(); j++) {

			int dst = dist(vec[i], vec[j]);
			V[i].push_back({ j, dst });
			V[j].push_back({ i, dst });
			hi = max(hi, dst);

		}

	while (lo <= hi) {

		int mid = (lo + hi) / 2;

		bool flag = bfs(mid);

		//cout << lo << " " << hi << " " << " " << mid << " : " << flag << "\n";

		if (flag) hi = mid - 1;
		else lo = mid + 1;

	}

	cout << lo;

	return 0;

}