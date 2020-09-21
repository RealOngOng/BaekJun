#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

int arr[4][2500000];

int main() {

	int a, b; scanf("%d %d", &a, &b);

	vector<Vector2> vec;

	int t = 0;

	for (int x = 0; x < 2500000; x++) {

		for (int y = 0; y < 4; y++) {

			t += 1;

			if (t == a) vec.push_back({x, y});
			if (t == b) vec.push_back({x, y});

			arr[y][x] = t;

		}

	}

	printf("%d", abs(vec[0].x - vec[1].x) + abs(vec[0].y - vec[1].y));

	return 0;

}