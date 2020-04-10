#include <iostream>
#include <string>

#define MAX 128

int field[MAX][MAX];

std::string inBraket(std::string s1, std::string s2, std::string s3, std::string s4) {

	return "(" + s1 + s2 + s3 + s4 + ")";

}

//-1 실패, 0, 1압축성공
int isZip(int n, int x, int y) {

	int result = -1;

	int sum = 0;

	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			sum += field[i][j];

	if (sum == 0) result = 0;
	else if (sum == n * n) result = 1;

	return result;

}

std::string func(int n, int x, int y) {
	
	int t = isZip(n, x, y);

	if (t != -1) return std::to_string(t);
	if (n == 1) return std::to_string(field[x][y]);

	int half = n * 0.5;

	return 
		inBraket(func(half, x, y), func(half, x, y + half),
				 func(half, x + half, y), func(half, x + half, y + half) );

}

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i++) {

		std::string line;
		std::cin >> line;

		for (int j = 0; j < n; j++)
			field[i][j] = line[j] - '0';

	}

	std::cout << func(n, 0, 0) << "\n";

	return 0;

}