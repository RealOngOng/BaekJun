#include <iostream>

#define MAX 2500

int field[MAX][MAX];

int case_m1, case_0, case_1;

bool okOne(int n, int x1, int y1) {

	int num_m1 = 0, num_0 = 0, num_1 = 0;

	for (int i = x1; i < x1 + n; i++)
		for (int j = y1; j < y1 + n; j++) {

			switch (field[i][j])
			{

				case -1:
					num_m1++;
					break;

				case 0:
					num_0++;
					break;

				case 1:
					num_1++;
					break;

			}

		}
	
	if (num_m1 == n * n)
		case_m1++;
	else if (num_0 == n * n)
		case_0++;
	else if (num_1 == n * n)
		case_1++;
	else
		return false;

	return true;

}

void func(int n, int x1, int y1) {

	int three = n / 3;

	if (okOne(n, x1, y1)) return;

	if (n < 1) return;

	func(three, x1, y1);
	func(three, x1 + three, y1);
	func(three, x1 + three * 2, y1);

	func(three, x1, y1 + three);
	func(three, x1 + three, y1 + three);
	func(three, x1 + three * 2, y1 + three);

	func(three, x1, y1 + three * 2);
	func(three, x1 + three, y1 + three * 2);
	func(three, x1 + three * 2, y1 + three * 2);

}

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> field[i][j];

	func(n, 0, 0);

	std::cout << case_m1 << "\n" << case_0 << "\n" << case_1 << "\n";

	return 0;

}