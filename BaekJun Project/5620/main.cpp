#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

int distance(Vector2 vec1, Vector2 vec2){return (vec1.x - vec2.x) * (vec1.x - vec2.x) + (vec1.y - vec2.y) * (vec1.y - vec2.y);}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	vector<Vector2> vert;

	for (int i = 0; i < n; i++) {

		int a, b; cin >> a >> b;
		vert.push_back({ a, b });

	}

	std::sort(vert.begin(), vert.end(),
			  [](const Vector2& vec1, const Vector2& vec2) -> bool {
		if (vec1.x != vec2.x) return vec1.x < vec2.x;
		return vec1.y < vec2.y;
	});

	int dst = 0x3f3f3f3f;

	for (int i = 1; i < n; i++) {

		int d = distance(vert[i - 1], vert[i]);

		dst = min(dst, d);

	}

	std::sort(vert.begin(), vert.end(),
			  [](const Vector2& vec1, const Vector2& vec2) -> bool {
		if (vec1.y != vec2.y) return vec1.y < vec2.y;
		return vec1.x < vec2.x;
	});

	for (int i = 1; i < n; i++) {

		int d = distance(vert[i - 1], vert[i]);

		dst = min(dst, d);

	}

	cout << dst << "\n";

	return 0;

}