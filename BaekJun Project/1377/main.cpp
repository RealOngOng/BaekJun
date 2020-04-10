#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

std::vector<std::pair<int, int>> arr;

int max(int a, int b) { return (a > b) ? a : b; }

int main() {

	int n;
	std::cin >> n;

	arr.resize(n);

	for (int i = 0; i < n; i++) {

		std::cin >> arr[i].first;

		arr[i].second = i;

	}

	std::sort(arr.begin(), arr.end());

	int result = 0;

	for (int i = 0; i < n; i++)
		result = max(result, arr[i].second - i);

	std::cout << result + 1 << "\n";

}