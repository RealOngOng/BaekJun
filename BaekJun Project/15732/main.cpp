#include <iostream>
#include <algorithm>
#include <limits.h>

#define MAX 1000001

typedef long long ll;

typedef struct Rule {

	int start, end, gap;

};

Rule rule[MAX];
int n, k, d;

bool isOk(ll n) {

	ll count = 0;

	for (int i = 0; i < k; i++) {

		if (rule[i].start > n) continue;

		ll max = std::min(n, (ll)rule[i].end);

		count += (max - rule[i].start) / rule[i].gap + 1;

	}

	return (count >= d);

}

int main() {

	ll low = INT_MAX, high = -INT_MAX;

	std::cin >> n >> k >> d;

	for (int i = 0; i < k; i++) {

		ll a, b, c; std::cin >> a >> b >> c;

		rule[i] = { a, b, c };

		low = std::min(low, a);
		high = std::max(high, b);

	}

	ll result = 0;

	while (low <= high) {

		ll mid = (low + high) * 0.5;

		if (isOk(mid)) {

			result = mid;
			high = mid - 1;

		}
		else
			low = mid + 1;

	}

	std::cout << result << "\n";

	return 0;

}

