#include <iostream>
#include <vector>
#include <limits.h>

std::vector<int> arr, dp;

int max(int a, int b) { return (a > b) ? a : b; }

int main() {

	int n;
	std::cin >> n;

	arr.resize(n + 1); dp.resize(n + 1);

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	int _max = -INT_MAX;

	for (int i= n - 1; i >= 0; i--) {

		dp[i] = max(arr[i], arr[i] + dp[i + 1]);

	}

	for (int i = 0; i < n; i++)
		if (_max < dp[i]) _max = dp[i];

	std::cout << _max;

	return 0;

}