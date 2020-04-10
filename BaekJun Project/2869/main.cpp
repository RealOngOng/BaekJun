#include <iostream>

int main() {

	double a, b, c;
	std::cin >> a >> b >> c;

	if (a >= c) std::cout << "1";
	else std::cout << (int)(std::ceil((c - a) / (a - b)) + 1);

	return 0;

}