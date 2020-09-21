#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1001

typedef long long ll;

typedef struct Vector2 {

	ll x, y;

	bool operator<(Vector2 v) {

		if (x != v.x) return x < v.x;
		else return y < v.y;

	}
	bool operator>(Vector2 v) {

		if (x != v.x) return x > v.x;
		else return y > v.y;

	}
	bool operator==(Vector2 v) {

		return (x == v.x && y == v.y);

	}

};

typedef struct Line {

	Vector2 start, end;

};

typedef struct Vertex {

	int idx; bool isMatch;

	std::vector<int> adjust;

};

ll CCW(Vector2 v1, Vector2 v2, Vector2 v3) {

	ll s = (v2.x - v1.x) * (v3.y - v1.y) - (v3.x - v1.x) * (v2.y - v1.y);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else if (s < 0)return -1;

}

int Cross(Line l1, Line l2) {

	ll ccw1 = CCW(l1.start, l1.end, l2.start) * CCW(l1.start, l1.end, l2.end),
		ccw2 = CCW(l2.start, l2.end, l1.start) * CCW(l2.start, l2.end, l1.end);

	if (CCW(l1.start, l1.end, l2.start) == 0 && CCW(l1.start, l1.end, l2.end) == 0) {

		if (l1.start > l1.end) std::swap(l1.start, l1.end);
		if (l2.start > l2.end) std::swap(l2.start, l2.end);

		if (l1.end < l2.start || l2.end < l1.start) return 0;
		else if (l1.end == l2.start || l1.start == l2.end) return 1;
		else return INF;

	}

	return (ccw1 <= 0 && ccw2 <= 0);

}

std::vector<Vertex> vert; //0 ~ h * k - 1±Ó¡ˆ ±∏∏€, h * k ~ h * k + m-1±Ó¡ˆ ¡„
std::vector<bool> visit;
std::vector<int> match;

bool dfs(int idx) {

	int size = vert[idx].adjust.size();

	for (int i = 0; i < size; i++) {

		int adj = vert[idx].adjust[i];

		if (visit[adj]) continue;

		visit[adj] = true;

		if (match[adj] == -1 || dfs(match[adj])) {

			match[adj] = idx;
			return true;

		}

	}

	return false;

}

int main() {

	int n, k, h, m; std::cin >> n >> k >> h >> m;

	std::vector<Vector2> corner(n), hole(h), mouse(m);
	std::vector<Line> house(n);

	visit.resize(h * k + m), vert.resize(h * k + m);

	match.resize(h * k + m);
	std::fill(match.begin(), match.end(), -1);

	for (int i = 0; i < n; i++)
		std::cin >> corner[i].x >> corner[i].y;

	for (int i = 0; i < n; i++)
		house[i].start = corner[i], house[i].end = corner[(i + 1) % n];

	for (int i = 0; i < h; i++)
		std::cin >> hole[i].x >> hole[i].y;

	for (int i = 0; i < m; i++)
		std::cin >> mouse[i].x >> mouse[i].y;

	//∞£º± ¿’±‚
	for (int i = 0; i < m; i++) {

		Line path;
		path.start = mouse[i];

		for (int j = 0; j < h; j++) {

			path.end = hole[j];

			int v = 0;

			for (int w = 0; w < n; w++) {

				v += Cross(path, house[w]);

				if (v >= INF) {

					v = INF;
					break;

				}

				if (Cross(path, { house[w].start , house[w].start })) v--;

			}

			if (v == 1)
				for (int q = 0; q < k; q++)
					vert[i].adjust.push_back(j * k + q);

		}

	}

	int result = 0;

	//¿Ã∫– ∏≈ƒ™
	for (int i = 0; i < m; i++) {

		std::fill(visit.begin(), visit.end(), false);

		if (dfs(i)) result++;

	}

	if (result < m) std::cout << "Impossible\n";
	else std::cout << "Possible\n";

	return 0;

}