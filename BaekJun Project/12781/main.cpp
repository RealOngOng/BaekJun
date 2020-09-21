#include <iostream>
#include <algorithm>
#include <vector>

typedef struct Vector2 {

	int x, y;

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

};

typedef struct Line {

	Vector2 start, end;

};

int CCW(Vector2 v1, Vector2 v2, Vector2 v3) {

	int s = (v2.x - v1.x) * (v3.y - v1.y) - (v3.x - v1.x) * (v2.y - v1.y);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else if (s < 0)return -1;

}

bool Cross(Line l1, Line l2) {

	int ccw1 = CCW(l1.start, l1.end, l2.start) * CCW(l1.start, l1.end, l2.end),
		ccw2 = CCW(l2.start, l2.end, l1.start) * CCW(l2.start, l2.end, l1.end);

	if (ccw1 == 0 && ccw2 == 0) return false;

	return (ccw1 < 0 && ccw2 < 0);

}

Line line[2];

int main() {

	for (int i = 0; i < 2; i++)
		std::cin >> line[i].start.x >> line[i].start.y
				>> line[i].end.x >> line[i].end.y;

	std::cout << Cross(line[0], line[1]) << "\n";

	return 0;

}