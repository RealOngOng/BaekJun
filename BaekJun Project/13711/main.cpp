#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

#define MAX 100001

int a[MAX], arr[MAX];
std::pair<int, int> b[MAX];

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i++) std::cin >> a[i];

	for (int i = 0; i < n; i++) {

		int input; std::cin >> input;

		b[i] = { input, i };

	}

	std::sort(b, b + n);

	for (int i = 0; i < n; i++)
		arr[i] = b[a[i] - 1].second;

	std::vector<int> vec;

	for (int i = 0; i < n; i++) {

		int idx = std::lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();

		if (idx >= vec.size()) vec.push_back(arr[i]);
		else vec[idx] = arr[i];

	}

	std::cout << vec.size() << "\n";

	return 0;

}