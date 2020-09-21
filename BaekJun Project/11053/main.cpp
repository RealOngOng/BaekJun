#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001

std::vector<int> arr, dp;

int main() {

	int n; std::cin >> n;

	arr.resize(n), dp.resize(n);

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	dp[0] = 1;

	for (int i = 1; i < n; i++) {

		dp[i] = 1;

		for (int j = i - 1; j >= 0; j--) {

			if(arr[i] < arr[j])
				dp[i] = std::max(dp[i], 1 + dp[j]);

		}

	}

	int max = 0;

	for (int i = 0; i < n; i++) max = std::max(max, dp[i]);

	std::cout << max << "\n";

	return 0;

}