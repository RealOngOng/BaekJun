#include <iostream>
#include <algorithm>
#include <math.h>

#define MAX 1000001

int h[MAX];

int n, m;

long long len(int w) {

	long long sum = 0;

	for (int i = 0; i < n; i++)
		sum += std::min(w, h[i]);

	return sum;

}

int main() {

	std::cin >> n;

	int a = 0, b = 0;

	for (int i = 0; i < n; i++) {

		std::cin >> h[i];
		if (h[i] > b) b = h[i];

	}

	int result = 0;
	std::cin >> m;

	while (a <= b) {

		int mid = (a + b) * 0.5;

		long long l = len(mid);

		if (l <= m) {

			result = mid;
			a = mid + 1;

		}
		else b = mid - 1;

	}

	std::cout << result << "\n";

	return 0;

}