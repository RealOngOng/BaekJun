#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 4;

struct V {
	int x = 0, y = 0;
	V() {};
	V(int x, int y) : x(x), y(y) {};
	bool operator == (V rhs) {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (V rhs) {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	V operator - (V rhs) {
		return V(x - rhs.x, y - rhs.y);
	}
	int cross(V rhs) {
		return x * rhs.y - y * rhs.x;
	}
};

int ccw(V p, V a, V b) {
	int ans = (a - p).cross(b - p);
	if (ans > 0) return 1;
	else if (ans == 0) return 0;
	else return -1;
}

int segmentIntersects(V a, V b, V c, V d) {
	if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		if (b < c || d < a) return 0;
		else if (b == c || d == a) return 1;
		else return INF;
	}
	else {
		int ab = ccw(a, b, c) * ccw(a, b, d);
		int cd = ccw(c, d, a) * ccw(c, d, b);
		return ab <= 0 && cd <= 0;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		V square[4];
		V line[2];
		for (int i = 0; i < 3; i += 2) {
			cin >> square[i].x >> square[i].y;
		}
		square[1].x = square[2].x;
		square[1].y = square[0].y;
		square[3].x = square[0].x;
		square[3].y = square[2].y;
		cin >> line[0].x >> line[0].y >> line[1].x >> line[1].y;
		int ans = 0;
		for (int i = 0; i < 4; ++i) {
			V a = line[0];
			V b = line[1];
			V p = square[i];
			V q = square[(i + 1) % 4];
			ans += segmentIntersects(a, b, p, q);
			if (ans >= INF) {
				ans = INF;
				break;
			}
			if (segmentIntersects(a, b, p, p)) {
				ans--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

