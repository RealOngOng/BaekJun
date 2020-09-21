#include <iostream>
#include <algorithm>

#define MAX 10002

int arr[MAX], dp[MAX];

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	dp[0] = arr[0];
	if (n > 0)
		dp[1] = arr[0] + arr[1];

	for (int i = 2; i < n; i++) {

		dp[i] = std::max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = std::max(dp[i], dp[i - 1]);

	}

	std::cout << dp[n - 1] << "\n";

	return 0;

}