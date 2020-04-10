#include <iostream>

__inline int ya(int n) {

	int sum = 0;

	while (n > 0)
		sum += n % 10, n /= 10;

	return sum;

}

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i++) 
		if (i + ya(i) == n) { std::cout << i; return 0; }

	std::cout << 0;

	return 0;

}