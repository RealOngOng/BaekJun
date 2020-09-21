#include <iostream>
#include <algorithm>
#include <math.h>

#define MAX 10001

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

ll CCW(Vector2 v1, Vector2 v2, Vector2 v3) {

	ll s = (v2.x - v1.x) * (v3.y - v1.y) - (v3.x - v1.x) * (v2.y - v1.y);

	return s;

}

Vector2 vert[MAX];

int main() {

	int n; std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> vert[i].x >> vert[i].y;

	ll scale = 0;

	for (int i = 0; i < n - 1; i++)
		scale += CCW(vert[0], vert[i], vert[i + 1]);

	printf("%.1lf", std::abs(scale / 2.0));

	return 0;

}