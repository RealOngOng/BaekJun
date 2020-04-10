#include <iostream>
#include <math.h>

int n, r, c;

bool isCollision(int scale, int x1, int y1) {

	return !(x1 > r || x1 + scale < r || y1 > c || y1 + scale < c);

}

void func(int s, int w, int x, int y) {

	int half = s * 0.5;

	if (s == 1) {

		if (x == r && y == c) {

			std::cout << w << "\n";

		}

		return;

	}

	if(isCollision(half, x, y)) func(half, w, x, y);
	if (isCollision(half, x + half, y))func(half, w + 2 * half * half, x + half, y);
	if (isCollision(half, x, y + half))func(half, w + half * half, x, y + half);
	if (isCollision(half, x + half, y + half))func(half, w + 3 * half * half, x + half, y + half);

}

int main() {

	std::cin >> n >> r >> c;

	n = std::pow(2, n);

	func(n, 0, 0, 0);

	return 0;

}