#include <iostream>
#include <algorithm>

typedef long long ll;

ll n, k;

int main() {

	std::cin >> n >> k;

	ll low = 1, high = k;

	ll result = 0;

	while (low <= high) {

		ll mid = (low + high) * 0.5;

		ll count = 0;

		for (int i = 1; i <= n; i++) count += std::min(mid / i, n);

		if (count >= k) {

			result = mid;
			high = mid - 1;

		}
		else
			low = mid + 1;

	}

	std::cout << result << "\n";

	return 0;

}