#include <iostream>

#define MAX 11

int arr[MAX];

int main() {

	int n, k;
	std::cin >> n >> k;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	int result = 0;

	for (int i = n - 1; i >= 0; i--) {

		if (arr[i] > k) continue;

		result += k / arr[i];
		k = k % arr[i];

	}

	std::cout << result << "\n";

	return 0;

}