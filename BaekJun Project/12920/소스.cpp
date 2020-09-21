#include <iostream>
#include <math.h>

int main() {

	while (true) {

		int n; std::cin >> n;

		for (int j = 2; j <= n * 2; j <<= 1)
			std::cout << std::round((double)n / j) << "\n";

		std::cout << "------\n";

		for (int j = n; j > 0; j >>= 1)
			std::cout << j - (j >> 1) << "\n";

	}

	return 0;

}