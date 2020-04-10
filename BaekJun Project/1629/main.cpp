#include <iostream>
#include <math.h>

int a, b, c;

long long ex(long long a, long long b) {

	if (b <= 1) return powl(a, b);

	long long temp = ex(a, b * 0.5);

	if (b % 2 == 0) return (temp * temp) % c;
	else return ((temp * temp) % c * a) % c;

}

int main() {

	std::cin >> a >> b >> c;

	std::cout << ex(a % c, b) << "\n";

	return 0;

}