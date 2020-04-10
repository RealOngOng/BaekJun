#include <iostream>
#include <string>
#include <math.h>

bool isClap1(int num) {

	if (num % 3 == 0) return true;

	return false;

}

bool isClap2(int num) {

	if (std::to_string(num).find('3') != std::string::npos) return true;
	if (std::to_string(num).find('6') != std::string::npos) return true;
	if (std::to_string(num).find('9') != std::string::npos) return true;

	return false;

}

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i++) {

		int power2 = std::pow(10, i+1);

		int sum_1 = 0, sum_2 = 0;

		for (int j = 1; j < power2; j++)
			sum_1 += isClap1(j), sum_2 += isClap2(j);

		std::cout << "10^" << i + 1 << " : " << sum_1 << ", " << sum_2 - sum_1 << "\n";

	}

	return 0;

}