#include <iostream>

#define MAX 10000

char field[MAX][MAX];

void SetStar(int x, int y) {

	field[x][y] = field[x + 1][y] = field[x + 2][y] = '*';

	field[x][y + 1] = field[x + 2][y + 1] = '*';
	field[x + 1][y + 1] = ' ';

	field[x][y + 2] = field[x + 1][y + 2] = field[x + 2][y + 2] = '*';

}

void func(int n, int x, int y) {

	if (n == 3) {

		SetStar(x, y);
		return;

	}

	int half = n / 3;

	func(half, x, y);
	func(half, x + half, y);
	func(half, x + half * 2, y);

	func(half, x, y + half);
	func(half, x + half * 2, y + half);

	func(half, x, y + half * 2);
	func(half, x + half, y + half * 2);
	func(half, x + half * 2, y + half * 2);

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int n; std::cin >> n;

	for (int i = 0; i < n; i++)
		std::fill(field[i], field[i] + n, ' ');

	func(n, 0, 0);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++)
			std::cout << field[i][j];

		std::cout << "\n";

	}

	return 0;

}