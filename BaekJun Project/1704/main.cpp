#include <iostream>
#include <vector>

#define MAX 16

typedef struct Vector2 {

	int x, y;

};

typedef std::vector<std::vector<bool>> Area;

std::vector<Area> results;

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, 1, 0, -1, 0 };

int w, h;

void PrintArea(Area &area) {

	for (int i = 0; i < w; i++) {

		for (int j = 0; j < h; j++)
			std::cout << area[i][j] << " ";

		std::cout << "\n";

	}

}

bool isGood(Area &field) {

	int score = 0;

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			score += field[i][j];

	return (score == 0);

}

std::vector<Vector2> FindReverse(Area &field, Area &check) {

	std::vector<Vector2> find;

	for(int i=0; i < w; i++)
		for (int j = 0; j < h; j++) {

			if (check[i][j]) continue;

			int score[2];

			Vector2 pos = { i, j };

			for (int q = 0; q < 5; q++) {

				Vector2 npos = { pos.x + dx[i], pos.y + dy[i] };

				if (npos.x < 0 || npos.y < 0 || npos.x >= w || npos.y >= h) continue;

				score[field[npos.x][npos.y]]++;

			}

			if (score[0] <= score[1]) find.push_back(pos);

		}

	return find;

}

void func(Area field, Area check);

void Reverse(Area field, Area check, Vector2 pos) {

	//PrintArea(field);

	check[pos.x][pos.y] = true;

	for (int i = 0; i < 5; i++) {

		Vector2 npos = { pos.x + dx[i], pos.y + dy[i] };

		if (npos.x < 0 || npos.y < 0 || npos.x >= w || npos.y >= h) continue;

		if (check[npos.x][npos.y]) continue;

		field[npos.x][npos.y] = !field[npos.x][npos.y];

	}

	func(field, check);

}

void func(Area field, Area check) {

	if (isGood(field)) {

		results.push_back(check);
		return;

	}

	std::vector<Vector2> find = FindReverse(field, check);

	int count = find.size();

	for (int i = 0; i < count; i++)
		Reverse(field, check, find[i]);

}

int main() {

	Area field(MAX), check(MAX);

	for (int i = 0; i < MAX; i++)
		field[i].resize(MAX), check[i].resize(MAX);

	std::cin >> w >> h;

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) {

			int a; std::cin >> a;
			field[i][j] = a;

		}

	func(field, check);

	int count = results.size();

	for (int i = 0; i < count; i++)
		PrintArea(results[i]);

	return 0;

}