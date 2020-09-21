#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <algorithm>

#define MAX 10

int arr[MAX];

int table[MAX][MAX];

void ArrRandomSet() {

	for (int i = 0; i < MAX; i++)
		arr[i] = rand() % MAX + 1;

}

int GetMax2(int n) {

	int i = 0;

	while (std::pow(2, i) <= n) { i++; }

	return i - 1;

}

void SetSpraseTable() {

	for (int i = 0; i < MAX; i++)
		table[i][0] = arr[i];

	int logMAX = std::log2(MAX);

	for (int j = 1; j <= logMAX; j++)
		for (int i = 0; i <= MAX - std::pow(2, j); i++)
			table[i][j] = std::min(table[i][j - 1], table[i + (int)std::pow(2, j - 1)][j - 1]);

}

int Query(int a, int b) {

	int j = GetMax2(b - a + 1);

	return std::min(table[a][j], table[b - (int)std::pow(2, j) + 1][j]);

}

void PrintArr() {

	for (int i = 0; i < MAX; i++)
		std::cout << arr[i] << " ";

	std::cout << "\n";

}

void PrintTable() {

	int logMAX = std::log2(MAX);

	for (int j = 1; j <= logMAX; j++) {

		for (int i = 0; i <= MAX - std::pow(2, j); i++)
			std::cout << table[i][j] << " ";

		std::cout << "\n";

	}

	std::cout << "\n";

}

int main() {

	srand(time(NULL));

	ArrRandomSet();

	SetSpraseTable();

	PrintArr();
	PrintTable();

	while (true) {

		int a, b; std::cin >> a >> b;

		std::cout << Query(a, b) << "\n";

	}

	return 0;

}