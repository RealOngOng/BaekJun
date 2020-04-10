#include <iostream>

int min(int a, int b) { return (a < b) ? a : b; }

int main() {

	int l, p, v;

	int i = 1;

	while (true) {

		std::cin >> l >> p >> v;

		if (l + p + v == 0) break;

		std::cout << "Case " << i++ << ": " << v / p * l + min(v % p, l) << "\n";

	}

	return 0;

}