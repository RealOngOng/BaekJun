#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000001

std::vector<int> arr, dp;

int main() {

	int n; std::cin >> n;

	arr.resize(n + 1);

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	dp.push_back(arr[0]);

	for (int i = 1; i < n; i++) {

		int idx = std::lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

		if (idx >= dp.size()) dp.push_back(arr[i]);
		else dp[idx] = arr[i];

	}

	std::cout << dp.size() << "\n";

	return 0;

}