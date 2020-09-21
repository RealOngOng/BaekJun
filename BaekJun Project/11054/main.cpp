#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001

std::vector<int> arr, add, sub;

int main() {

	int n; std::cin >> n;

	arr.resize(n), add.resize(n), sub.resize(n);

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	for (int i = 0; i < n; i++) {

		add[i] = 1;

		for (int j = i - 1; j >= 0; j--)
			if (arr[i] > arr[j])
				add[i] = std::max(add[i], 1 + add[j]);

	}

	for (int i = n - 1; i >= 0; i--) {

		sub[i] = 1;

		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				sub[i] = std::max(sub[i], 1 + sub[j]);

	}

	int max = 0;

	for (int i = 0; i < n; i++) max = std::max(max, add[i] + sub[i]);

	std::cout << max - 1 << "\n";

	return 0;

}