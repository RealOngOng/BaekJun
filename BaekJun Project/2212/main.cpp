#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> vec;
std::vector<int> sub;

int main() {

	int n, k;
	std::cin >> n >> k;

	if (n <= k) {

		std::cout << 0 << "\n";
		return 0;

	}

	for (int i = 0; i < n; i++) {

		int a; std::cin >> a;
		vec.push_back(a);

	}

	std::sort(vec.begin(), vec.end());

	int result = 0;

	for (int i = 0; i < n - 1; i++) {

		sub.push_back(vec[i + 1] - vec[i]);
		result += vec[i + 1] - vec[i];

	}

	std::sort(sub.begin(), sub.end(), std::greater<int>());

	for (int i = 0; i < k - 1; i++)
		result -= sub[i];

	std::cout << result << "\n";

	return 0;

}