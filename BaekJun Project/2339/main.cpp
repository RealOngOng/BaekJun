#include <iostream>
#include <vector>

#define MAX 21
#define FUCK 1
#define CRYSTAL 2
#define NO 0

int field[MAX][MAX];
int n;

typedef struct Vector2 {

	int x, y;

	void print() {

		std::cout << "(" << x << ", " << y << ")";

	}

};

typedef struct Result {

	bool isGood;
	std::vector<Vector2> fucks;

};

Result okGood(Vector2 pos1, Vector2 pos2) {

	Result result;

	int crystal = 0,
		fuck = 0;

	for (int i = pos1.x; i <= pos2.x; i++)
		for (int j = pos1.y; j <= pos2.y; j++) {

			if (field[i][j] == CRYSTAL) crystal++;
			else if (field[i][j] == FUCK) {

				result.fucks.push_back({ i, j });
				fuck++;

			}

		}

	result.isGood = (crystal == 1 && fuck == 0);

	return result;

}

//cut : true 세로, false 가로
int func(Vector2 pos1, Vector2 pos2, bool cut) {

	Result result = okGood(pos1, pos2);

	if (result.isGood) return 1;

	int var = 0;
	int count = result.fucks.size();

	for (int i = 0; i < count; i++) {

		if (pos1.x >= n || pos2.y >= n || pos2.x < 0 || pos2.y < 0) continue;

		if (!cut)
			var += func(pos1, { pos2.x, result.fucks[i].y - 1 }, !cut) * func({ pos1.x, result.fucks[i].y + 1 }, pos2, !cut);
		else
			var += func(pos1, { result.fucks[i].x - 1, pos2.y }, !cut) * func({ result.fucks[i].x + 1, pos1.y }, pos2, !cut);

	}

	return var;

}

int main() {

	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> field[i][j];

	int n1 = func({ 0, 0 }, { n - 1, n - 1 }, false);
	int n2 = func({ 0, 0 }, { n - 1, n - 1 }, true);

	if (n1 + n2 == 0) std::cout << "-1\n";
	else std::cout << n1 + n2 << "\n";

	return 0;

}