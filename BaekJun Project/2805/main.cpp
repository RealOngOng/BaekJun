#include <iostream>

#define MAX 1000001

int h[MAX];

int n, m;

long long len(int w) {

	long long sum = 0;

	for (int i = 0; i < n; i++)
		if (h[i] > w) sum += h[i] - w;

	return sum;

}

int main() {

	std::cin >> n >> m;

	int a = 0, b = 0;

	for (int i = 0; i < n; i++) {

		std::cin >> h[i];
		if (h[i] > b) b = h[i];

	}

	while (a + 1 != b) {

		int mid = (a + b) * 0.5;

		long long l = len(mid);
		
		if (l >= m) a = mid;
		else b = mid;

	}

	std::cout << a << "\n";

	return 0;

}