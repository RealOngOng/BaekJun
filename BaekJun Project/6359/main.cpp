#include <iostream>
#include <algorithm>

#define CLOSE 0
#define OPEN 1

#define MAX 101

int arr[MAX];

int main() {

	int t; std::cin >> t;

	while (t--) {

		int n; std::cin >> n;

		std::fill(arr, arr + MAX, CLOSE);

		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j += i)
				arr[j] = !arr[j];

		int sum = 0;

		for (int i = 1; i <= n; i++)
			sum += arr[i];

		std::cout << sum << "\n";

	}

	return 0;

}