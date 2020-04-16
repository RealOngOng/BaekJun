#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

typedef struct Vector2 {

	int x, y;

	Vector2(int x, int y) : x{ x }, y{ y } {}

	bool operator < (const Vector2& vec) const {

		if (y == vec.y) return x < vec.x;
		else return y < vec.y;

	}

};

bool cmp_x(const Vector2& vec1, const Vector2& vec2) {

	return (vec1.x < vec2.x);

}

bool cmp_y(const Vector2& vec1, const Vector2& vec2) {

	return (vec1.y < vec2.y);

}

int distance(const Vector2& vec1, const Vector2& vec2) {

	return std::pow(vec1.x - vec2.x, 2) + std::pow(vec1.y - vec2.y, 2);

}

std::vector<Vector2> vert;

int main() {

	int n; std::cin >> n;
	for (int i = 0; i < n; i++) {

		int x, y; std::cin >> x >> y;
		vert.push_back({x, y});

	}

	std::sort(vert.begin(), vert.end(), cmp_x);

	std::set<Vector2> candi = { vert[0], vert[1] };
	int ans = distance(vert[0], vert[1]);

	int start = 0;

	for (int i = 2; i < n; i++) {

		Vector2 v = vert[i];

		while (start < i) {

			auto p = vert[start];
			int x = v.x - p.x;

			if (x * x > ans) {

				candi.erase(p);
				start++;

			}
			else
				break;

		}

		int d = (int)std::sqrt((double)ans) + 1;

		auto lower = candi.lower_bound(Vector2(-100000, v.y - d));
		auto upper = candi.upper_bound(Vector2(100000, v.y + d));

		for (auto itr = lower; itr != upper; itr++) {

			int dst = distance(v, *itr);
			ans = std::min(ans, dst);

		}

		candi.insert(v);

	}

	std::cout << ans << "\n";

	return 0;

}

