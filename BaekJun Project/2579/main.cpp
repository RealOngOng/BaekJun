#include <iostream>
#include <algorithm>

#define MAX 301

int arr[MAX], dp[MAX];

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = std::max(arr[0] + arr[1], arr[1]);
	dp[2] = std::max(arr[0], arr[1]) + arr[2];

	for (int i = 3; i < n; i++)
		dp[i] = arr[i] + std::max(dp[i - 3] + arr[i - 1], dp[i - 2]);

	std::cout << dp[n - 1] << "\n";

	return 0;

}