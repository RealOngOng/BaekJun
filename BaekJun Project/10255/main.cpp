#include <iostream>
#include <vector>

typedef long long ll;

#define MAX 4

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
	bool operator>=(Vector2 v) {

		return (x >= v.x || y >= v.y);

	}
	bool operator<=(Vector2 v) {

		return (x <= v.x || y <= v.y);

	}
	bool operator==(Vector2 v) {

		return (x == v.x && y == v.y);

	}

};

typedef struct Line {

	Vector2 start, end;

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
		else return MAX;

	}

	return (ccw1 <= 0 && ccw2 <= 0);

}

int main() {

	int n; std::cin >> n;

	while (n--) {

		std::vector<Line> cross(4);

		int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

		Line l1, l2, l3, l4;

		l1.start = { x1, y1 }, l1.end = { x1, y2 };
		l2.start = { x1, y2 }, l2.end = { x2, y2 };
		l3.start = { x2, y2 }, l3.end = { x2, y1 };
		l4.start = { x2, y1 }, l4.end = { x1, y1 };

		cross[0] = l1, cross[1] = l2, cross[2] = l3, cross[3] = l4;

		Line path; std::cin >> path.start.x >> path.start.y >> path.end.x >> path.end.y;

		int vert = 0;

		for (int i = 0; i < 4; i++) {

			vert += Cross(path, cross[i]);

			if (vert >= MAX) {

				vert = MAX;
				break;

			}

			if (Cross(path, { cross[i].start , cross[i].start })) vert--;

		}

		std::cout << vert << "\n";

	}

	return 0;

}