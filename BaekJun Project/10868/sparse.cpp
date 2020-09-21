#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

int n, m;

std::vector<int> arr;
std::vector<std::vector<int>> table;

int GetMAX2(int n) {

	int i = 0; 

	while (std::pow(2, i) <= n) { i++; }

	return i - 1;

}

void SetTable() {

	int log = std::log2(n);

	table.resize(n + 1);
	for (int i = 0; i < n; i++) table[i].resize(log + 2);
	
	for (int i = 0; i < n; i++) table[i][0] = arr[i];

	for (int j = 1; j <= log; j++)
		for (int i = 0; i <= n - std::pow(2, j); i++)
			table[i][j] = std::min(table[i][j - 1], table[i + std::pow(2, j - 1)][j - 1]);

}

int Query(int l, int r) {

	int j = GetMAX2(r - l + 1);

	return std::min(table[l][j], table[r - std::pow(2, j) + 1][j]);

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	std::cin >> n >> m;

	arr.resize(n + 1);
	for (int i = 0; i < n; i++) std::cin >> arr[i];

	SetTable();

	while (m--) {

		int a, b; std::cin >> a >> b;

		std::cout << Query(a - 1, b - 1) << "\n";
		
	}

}