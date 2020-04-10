#include <iostream>

int main() {

	long long a, b, c;
	std::cin >> a >> b >> c;

	long long result = 0;

	if (c - b <= 0) result = -1;
	else result = a / (c - b) + 1;

	std::cout << result;

	return 0;

}