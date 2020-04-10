#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <limits.h>

typedef std::pair<int, int> Vector2;
typedef std::pair<Vector2, Vector2> Line;
typedef std::pair<int, Line> Dst;

int n;
Vector2 *vert;

int distance(Vector2 vec1, Vector2 vec2) { return std::pow(vec1.first - vec2.first, 2) + std::pow(vec1.second - vec2.second, 2); }

int main() {

	std::cin >> n;

	vert = new Vector2[n + 1];

	for (int i = 0; i < n; i++) {

		int a, b; std::cin >> a >> b;
		vert[i] = { a, b };

	}

	std::sort(vert, vert + n);

	int min = INT_MAX;

	for (int i = 1; i < n; i++) {

		int d = distance(vert[i - 1], vert[i]);

		if (min > d) min = d;

	}

	std::sort(vert, vert + n, 
			  [](const Vector2& vec1, const Vector2& vec2) -> bool {
		return (vec1.second < vec2.second);
	});

	for (int i = 1; i < n; i++) {

		int d = distance(vert[i - 1], vert[i]);;

		if (min > d) min = d;

	}

	std::cout << min << "\n";

	return 0;

}