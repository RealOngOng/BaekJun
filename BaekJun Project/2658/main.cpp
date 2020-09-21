#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

	bool operator<(Vector2 vec) {

		if (x != vec.x) return x < vec.x;
		return y < vec.y;

	}

	bool operator>(Vector2 vec) {

		if (x != vec.x) return x > vec.x;
		return y > vec.y;

	}

};

typedef struct Result {

	bool result = false;
	vector<Vector2> pos;

};

bool debug[10][10], field[10][10];

Result isTriangle1(Vector2 pos, int size) {

	Result r;

	if (pos.x + size - 1 > 9 || pos.y + size - 1 > 9) return r;

	r.result = true;

	int t = size;

	for (int y = pos.x; y < pos.x + size; y++) {

		for (int x = pos.y; x < pos.y + t; x++) {

			debug[x][y] = true;
			if (!field[x][y]) r.result = false;

		}

		t--;

	}

	if (r.result) {

		r.pos.push_back(pos);
		r.pos.push_back({pos.x + size - 1, pos.y});
		r.pos.push_back({pos.x, pos.y + size - 1});

	}

	return r;

}

Result isTriangle2(Vector2 pos, int size) {

	Result r;

	if (pos.x + size - 1 > 9 || pos.y + size - 1 > 9) return r;

	r.result = true;

	int t = size;

	for (int y = pos.x; y < pos.x + size; y++) {

		for (int x = pos.y + (size - t); x < pos.y + size; x++) {

			if (!field[x][y]) r.result = false;
			debug[x][y] = true;

		}

		t--;

	}

	if (r.result) {

		r.pos.push_back(pos);
		r.pos.push_back({ pos.x, pos.y + size - 1 });
		r.pos.push_back({ pos.x + size - 1, pos.y + size - 1 });

	}

	return r;

}

Result isTriangle3(Vector2 pos, int size) {

	Result r;

	if (pos.x + size - 1 > 9 || pos.y + size - 1 > 9) return r;

	r.result = true;

	int t = size;

	for (int y = pos.x + size - 1; y >= pos.x; y--) {

		if (t > size) break;

		for (int x = pos.y; x < pos.y + t; x++) {

			if (!field[x][y]) r.result = false;
			debug[x][y] = true;

		}

		t--;

	}

	if (r.result) {

		r.pos.push_back(pos);
		r.pos.push_back({ pos.x + size - 1, pos.y});
		r.pos.push_back({ pos.x + size - 1, pos.y + size - 1 });

	}

	return r;

}

Result isTriangle4(Vector2 pos, int size) {

	Result r;

	if (pos.x + size - 1 > 9 || pos.y + size - 1 > 9) return r;

	r.result = true;

	int t = 0;

	for (int y = pos.x + size - 1; y >= pos.x; y--) {

		for (int x = pos.y + size - 1; x >= pos.y + t; x--) {

			if (!field[x][y]) r.result = false;
			debug[x][y] = true;

		}

		t++;

	}

	if (r.result) {

		r.pos.push_back({pos.x + size - 1, pos.y});
		r.pos.push_back({ pos.x, pos.y + size - 1 });
		r.pos.push_back({ pos.x + size - 1, pos.y + size - 1 });

	}

	return r;

}

Result isTriangle5(Vector2 pos, int size) {

	Result r;

	if (size % 2 == 0) return r;

	if (pos.x + (size - 1) / 2 > 9 || pos.y + size - 1 > 9) return r;

	r.result = true;

	int t = 0;

	for (int y = pos.x; y < pos.x + size; y++) {

		for (int x = pos.y + t; x < pos.y + size - t; x++) {

			debug[x][y] = true;
			if (!field[x][y]) r.result = false;

		}

		t++;

	}

	if (r.result) {

		r.pos.push_back(pos);
		r.pos.push_back({ pos.x , pos.y + size - 1 });
		r.pos.push_back({ pos.x + (size - 1) / 2, pos.y + (size - 1) / 2 });

	}

	return r;

}

Result isTriangle6(Vector2 pos, int size) {

	Result r;

	if (size % 2 == 0) return r;

	if (pos.x + (size - 1) / 2 > 9 || pos.y + size - 1 > 9) return r;

	r.result = true;

	int t = 0;
	
	int half = (size + 1) / 2;

	for (int y = pos.x + half - 1; y >= pos.x; y--) {

		for (int x = pos.y + t; x < pos.y + size - t; x++) {

			debug[x][y] = true;
			if (!field[x][y]) r.result = false;

		}

		t++;

	}

	if (r.result) {

		r.pos.push_back({pos.x, pos.y + (size - 1) / 2});
		r.pos.push_back({pos.x + (size - 1) / 2, pos.y});
		r.pos.push_back({pos.x + (size - 1) / 2, pos.y + size - 1});

	}

	return r;

}

Result isTriangle7(Vector2 pos, int size) {

	Result r;

	if (size % 2 == 0) return r;

	if (pos.x + size - 1 > 9 || pos.y  + (size - 1) / 2 > 9) return r;

	r.result = true;

	int t = 0;

	for (int y = pos.y; y < pos.y + size; y++) {

		for (int x = pos.x + t; x < pos.x + size - t; x++) {

			debug[y][x] = true;
			if (!field[y][x]) r.result = false;

		}

		t++;

	}

	if (r.result) {

		r.pos.push_back(pos);
		r.pos.push_back({pos.x + size - 1 , pos.y });
		r.pos.push_back({ pos.x + (size - 1) / 2, pos.y + (size - 1) / 2 });

	}

	return r;

}

Result isTriangle8(Vector2 pos, int size) {

	Result r;

	if (size % 2 == 0) return r;

	if (pos.x + size - 1 > 9 || pos.y + (size - 1) / 2 > 9) return r;

	r.result = true;

	int t = 0;

	int half = ceil((double)size * 0.5);

	for (int y = pos.y + half - 1; y >= pos.y; y--) {

		for (int x = pos.x + t; x < pos.x + size - t; x++) {

			debug[y][x] = true;
			if (!field[y][x]) r.result = false;

		}

		t++;

	}

	if (r.result) {

		r.pos.push_back({pos.x, pos.y + (size - 1) / 2});
		r.pos.push_back({ pos.x + (size - 1) / 2, pos.y });
		r.pos.push_back({ pos.x + size - 1, pos.y + (size - 1) / 2 });

	}

	return r;

}

std::vector<Result> Triangle(Vector2 pos, int size) {

	std::vector<Result> r;

	r.push_back(isTriangle1(pos, size));
	r.push_back(isTriangle2(pos, size));
	r.push_back(isTriangle3(pos, size));
	r.push_back(isTriangle4(pos, size));
	r.push_back(isTriangle5(pos, size));
	r.push_back(isTriangle6(pos, size));
	r.push_back(isTriangle7(pos, size));
	r.push_back(isTriangle8(pos, size));

	return r;

}

int main() {

	for (int i = 0; i < 10; i++) {

		string str; cin >> str;

		for (int j = 0; j < 10; j++)
			field[j][i] = str[j] - '0';

	}

	int m = 0;
	std::vector<Vector2> cnt;

	//Result r = isTriangle4({0, 0}, 7);

	//printf("%d\n", r.result);

	//for (Vector2 v : r.pos) printf("%d, %d\n", v.x, v.y);

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			Vector2 pos = { i, j };

			for (int s = 3; s < 10; s++) {

				std::vector<Result> rs = Triangle(pos, s);

				int q = 0;

				for (Result r : rs) {

					if (!r.result) continue;

					if (s > m) {

						m = s;
						cnt.assign(r.pos.begin(), r.pos.end());

						//printf("%d %d %d %d\n", i, j, s, q);

					}

					q++;

				}

			}

		}
			
	}

	sort(cnt.begin(), cnt.end());

	for (Vector2 v2 : cnt) printf("%d %d\n", v2.x + 1, v2.y + 1);

	//for (int i = 0; i < 10; i++) {

	//	for (int j = 0; j < 10; j++)
	//		printf("%d", debug[j][i]);

	//	printf("\n");

	//}

	return 0;

}