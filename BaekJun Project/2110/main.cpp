#include <iostream>
#include <algorithm>

#define MAX 200001

int n, c;
int x[MAX];

bool isOk(int max) {

	int start = x[0];

	int count = 1;

	for (int i = 1; i < n; i++) {

		if (x[i] - start >= max) {

			start = x[i];
			count++;

		}

	}

	return (count >= c);

}

int main() {

	std::cin >> n >> c;
	
	for (int i = 0; i < n; i++) std::cin >> x[i];

	std::sort(x, x + n);

	int result = 0;
	int low = 1, high = x[n - 1] - x[0];

	while (low <= high) {

		int mid = (low + high) * 0.5;

		if (isOk(mid)) {

			result = mid;
			low = mid + 1;

		}
		else
			high = mid - 1;

	}

	std::cout << result << "\n";

}