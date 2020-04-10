#include <iostream>
#include <algorithm>

#define MAX 10001

typedef long long ll;

int k, n;
ll arr[MAX];

bool cut(ll max) {

	ll sum = 0;

	for (int i = 0; i < k; i++) sum += arr[i] / max;

	return (sum >= n);

}

int main() {

	ll low = 1, high = 0;

	std::cin >> k >> n;
	for (int i = 0; i < k; i++) std::cin >> arr[i], high = std::max(high, arr[i]);

	ll result = 0;

	while (low <= high) {

		ll mid = (low + high) * 0.5;

		if (cut(mid)) {

			result = std::max(result, mid);
			low = mid + 1;

		}
		else
			high = mid - 1;

	}

	std::cout << result << "\n";

	return 0;

}