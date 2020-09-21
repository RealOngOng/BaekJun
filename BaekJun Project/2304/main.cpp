#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

pi arr[1001];

int main() {

	stack<pi> stk;
	int max_height = 0, len = 0;

	int n; std::cin >> n;
	for (int i = 0; i < n; i++) 
		std::cin >> arr[i].first >> arr[i].second, max_height = max(max_height, arr[i].second);

	std::sort(arr, arr + n);

	len = arr[n - 1].first - arr[0].first + 1;

	int sum = 0, height = arr[0].second;

	stk.push(arr[0]);

	for (int i = 1; i < n; i++) {

		sum += height * (arr[i].first - stk.top().first);

		height = max(height, arr[i].second);

		stk.push(arr[i]);

	}

	sum += height;

	while (!stk.empty()) stk.pop();

	stk.push(arr[n - 1]), height = arr[n - 1].second;

	for (int i = n - 2; i >= 0; i--) {

		sum += height * -(arr[i].first - stk.top().first);

		height = max(height, arr[i].second);

		stk.push(arr[i]);

	}

	sum += height;

	std::cout << sum - (max_height * len) << "\n";

	return 0;

}