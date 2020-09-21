#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <vector>

#define MAX 1000001

std::vector<int> arr, dp;

std::vector<std::pair<int, int>> d;

std::stack<int> stk;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n; std::cin >> n;

	arr.resize(n + 1);

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	dp.push_back(arr[0]);
	d.push_back({0, arr[0]});

	for (int i = 1; i < n; i++) {

		int idx = std::lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

		if (idx >= dp.size()) dp.push_back(arr[i]);
		else
			dp[idx] = arr[i];

		d.push_back({idx, arr[i]});

	}

	int len = dp.size();

	std::cout << len << "\n";
	
	for (int i = n - 1; i >= 0; i--) {

		std::cout << d[i].first << ", " << d[i].second << "\n";

		if (d[i].first == len - 1)
			stk.push(d[i].second), len--;

	}

	while (!stk.empty())
		std::cout << stk.top() << " ", stk.pop();

	std::cout << "\n";

	return 0;

}