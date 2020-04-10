#include <iostream>
#include <algorithm>

#define MAX 1001

int arr[MAX], dp[MAX];

int main() {

	int n;  std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	for (int i = 0; i < n; i++) {

		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {

			if (arr[i] > arr[j])
				if (dp[i] < arr[i] + dp[j]) dp[i] = arr[i] + dp[j];

		}

	}

	std::cout << *std::max_element(dp, dp + n) << "\n";

	return 0;

}