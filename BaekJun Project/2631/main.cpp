#include <iostream>
#include <algorithm>

#define MAX 201

int arr[MAX], dp[MAX];

int main() {

	int n; std::cin >> n;
	for (int i = 1; i <= n; i++) std::cin >> arr[i];

	for (int i = 1; i <= n; i++) {

		dp[i] = 1;

		for (int j = i; j > 0; j--)
			if (arr[i] > arr[j])
				dp[i] = std::max(dp[i], dp[j] + 1);

	}

	int max = 0;

	for (int i = 1; i <= n; i++) max = std::max(max, dp[i]);

	std::cout << n - max << "\n";

	return 0;

}